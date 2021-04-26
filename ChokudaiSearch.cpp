/*

　　　∫ ∫ ∫
　　　ノヽ
　　（＿　 ）
　（＿　　　 ）
（＿＿＿＿＿＿ ）
　ヽ(´･ω･)ﾉ　
　　 |　 /
　　 UU
*/
#pragma region macro
#include <bits/stdc++.h>
typedef long long int64;
using namespace std;
typedef vector<int> vi;
const int MOD = (int)1e9 + 7;
const int64 INF = 1LL << 62;
const int inf = 1<<30;
const char bn = '\n';
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,s,n) for (int i = s; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end() //コンテナじゃないと使えない!!
#define debug(x) cerr << #x << ": " << x << "\n";
#define mp make_pair
template <typename T>
ostream& operator<<(ostream& os, const vector<T> &V){
    int N = V.size();
    REP(i,N){
        os << V[i];
        if (i!=N-1) os << " ";
    }
    os << "\n";
    return os;
}
template <typename T,typename S>
ostream& operator<<(ostream& os, pair<T,S> const&P){
    os << "(";
    os << P.first;
    os << " , ";
    os << P.second;
    os << ")";
    return os;
}
template <typename T,typename S,typename U>
ostream& operator<<(ostream& os, tuple<T,S,U> const& P){
    os << "(";
    os << get<0>(P);
    os << ", ";
    os << get<1>(P);
    os << ", ";
    os << get<2>(P);
    os << ")";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T> &S){
    auto it=S.begin();
    while(it!=S.end()){
        os << *it;
        os << " ";
        it++;
    }
    os << "\n";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T> &q){
    for(auto it=q.begin();it<q.end();it++){
        os<<*it;
        os<<" ";
    }
    os<<endl;
    return os;
}
template <typename T,typename S>
ostream& operator<<(ostream& os, map<T,S> const&M){
    for(auto e:M){
        os<<e;
    }
    os<<endl;
    return os;
}
vector<pair<int,int>> dxdy = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1)};
#pragma endregion
//fixed<<setprecision(10)<<ans<<endl;


const int N = 50;


//----局面の状態----
class State{
    public:
    int score;
    vector<char> move;
    bitset<N*N> visited;
    pair<int,int> place;
    State(){
        score = 0;
        
    }

    State(int score_, bitset<N*N> const& visited_, vector<char> const& move_, pair<int,int> const& place_){
        score = score_;
        visited = visited_;
        move = move_;
        place = place_;

    }

    bool operator<(const State& S2) const{
        return this->score < S2.score;
    }

    bool operator>(const State& S2) const{
        return this->score > S2.score;
    }
};

bool is_outside(pair<int,int> const& HW){
    return (HW.first<0 or HW.first>=N or HW.second<0 or HW.second>=N);
}


void save_ans(vector<multiset<State>>const& priq_vec, vector<char>& ans, int& ans_score){
    for(int depth = N*N-1; depth>=0; depth--){
        if(priq_vec[depth].empty()) continue;
        ans = (*--priq_vec[depth].end()).move;
        ans_score = (*--priq_vec[depth].end()).score;
    }
}


void cout_move(vector<char> const& move){
    for(auto a:move){
        if(a==0) cout<<"D";
        else if(a==1) cout<<"U";
        else if(a==2) cout<<"R";
        else if(a==3) cout<<"L";
    }
    cout << endl;
}



void chokudai_search(vector<int> const& S, vector<vector<int>> const& T, vector<vector<int>> const& P, int& ans_score, vector<char>& ans, clock_t end_time){

    vector<multiset<State>> priq_vec(N*N); //各深さごとの(スコア, 局面)を昇順でもつ 状態が大きくなりすぎてMLEするので定期的に削除できるようにmultiset

    //まず探索
    vector<char> move; move.reserve(N*N); //動き
    int before_score = P[S[0]][S[1]]; //スコア
    pair<int,int> before_place = mp(S[0], S[1]); //現在地
    bitset<N*N> visited; visited.set(T[S[0]][S[1]]); //踏んだタイル
    
    int next_upper = 0; //どの深さまでキューが入ってるか
    for(int depth=0; depth<N*N; depth++){
        move.push_back(0);
        REP(i,4){
            pair<int,int> now_place = before_place;
            if(i==0) now_place.first += 1;
            else if(i==1) now_place.first -= 1;
            else if(i==2) now_place.second += 1;
            else now_place.second -= 1;

            if(is_outside(now_place)) continue;
            if(visited.test(T[now_place.first][now_place.second])){
                continue;
            }else{
                int new_score = before_score + P[now_place.first][now_place.second];
                visited.set(T[now_place.first][now_place.second]);
                move[depth] = i;
                priq_vec[depth].insert(State(new_score, visited, move, now_place));

                visited.reset(T[now_place.first][now_place.second]);
                next_upper = depth+1;
            }
        }

        if(priq_vec[depth].empty()) {
            move.pop_back();
            break;
        }

        before_score = (*--priq_vec[depth].end()).score;
        visited = (*--priq_vec[depth].end()).visited;
        before_place = (*--priq_vec[depth].end()).place;
        move = (*--priq_vec[depth].end()).move;
    }

    while(true){
        clock_t now = clock();
        int upper = next_upper;
        next_upper = 0;

        if(now >= end_time){
            return;
        }

        //各深さについて、今まで探索したやつで一番いいやつを使って次を探索
        for(int depth=1; depth<=min(upper,N*N-1); depth++){
            if(priq_vec[depth-1].empty()){ continue;} //priqが空

            State before_state = *--priq_vec[depth-1].end(); priq_vec[depth-1].erase(--priq_vec[depth-1].end()); //１個前の局面の一番いいやつ
            int& before_score = before_state.score;
            vector<char>& move = before_state.move;
            pair<int,int>& before_place = before_state.place;
            bitset<N*N>& visited = before_state.visited; 
            
            if(not priq_vec[depth-1].empty()) next_upper=depth+1;

            move.push_back(0);
            REP(i,4){
                pair<int,int> now_place = before_place;
                if(i==0) now_place.first += 1;
                else if(i==1) now_place.first -= 1;
                else if(i==2) now_place.second += 1;
                else now_place.second -= 1;

                if(is_outside(now_place)) continue;
                if(visited.test(T[now_place.first][now_place.second])){
                    continue;
                }else{ //validな移動なら、スコアとか状態とかを更新し、priqに入れる. ついでにスコアが更新されてたら更新しておく
                    int new_score = before_score + P[now_place.first][now_place.second];
                    visited.set(T[now_place.first][now_place.second]);
                    move[depth] = i;
                    priq_vec[depth].insert(State(new_score, visited, move, now_place));

                    visited.reset(T[now_place.first][now_place.second]);
                    if(new_score > ans_score){
                        ans = move;
                        ans_score = new_score;
                    }
                    upper++;
                }
            }
        }
    }

    exit(1);

}



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    const double sec = 1.7;    
    clock_t start_time = clock();
    clock_t end_time   = start_time + sec * CLOCKS_PER_SEC;

    vector<int> S(2); cin >> S[0] >> S[1];
    vector<vector<int>> T(N, vector<int>(N,0));
    vector<vector<int>> P(N, vector<int>(N,0));
    REP(i,N) REP(j,N) cin >> T[i][j];
    REP(i,N) REP(j,N) cin >> P[i][j];

    int score = 0; vector<char> ans;
    chokudai_search(S,T,P,score,ans,end_time); 

    debug(score)
    cout_move(ans);


}