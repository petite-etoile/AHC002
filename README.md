# AHC002
[AtCoder](https://atcoder.jp)のヒューリスティックスコンテストである[AtCoder Heuristic Contest](https://atcoder.jp/contests/ahc002)に対する回答

## ChokudaiSearch.cpp 
[Chokudaiサーチ(ビームサーチ亜種)](https://chokudai.hatenablog.com/entry/2017/04/12/055515)を用いた解法

## BeamSearch.cpp
ビームサーチを用いた解法

## 上記手法の評価関数
素のスコアを評価関数に用いると微妙
最後、袋小路になって止まってしまうことを考えると、渦巻き状になるとうれしい -> 中心からのチェビシェフ距離を評価関数に追加する


## 提出履歴
|内容|ファイル名|得点|提出ページ|
|:--:|:--:|---:|:--:|
|空のファイル|[empty.cpp](https://github.com/petite-etoile/AHC002/blob/d4095f541dd86ecf3475be49446b9de33b36ba2f/empty.txt)|4861|[提出リンク](https://atcoder.jp/contests/ahc002/submissions/22062564)|
|貪欲()|[ChokudaiSearch.cpp](https://github.com/petite-etoile/AHC002/blob/d4095f541dd86ecf3475be49446b9de33b36ba2f/ChokudaiSearch.cpp)|180042|[提出リンク](https://atcoder.jp/contests/ahc002/submissions/22064052)|
|単純なChokudaiサーチ|[ChokudaiSearch.cpp](https://github.com/petite-etoile/AHC002/blob/d4095f541dd86ecf3475be49446b9de33b36ba2f/ChokudaiSearch.cpp)|3282136|[提出リンク](https://atcoder.jp/contests/ahc002/submissions/22064925)|
|履歴を持ってfor文の無駄な深さの探索を削除|[ChokudaiSearch.cpp](https://github.com/petite-etoile/AHC002/blob/d4095f541dd86ecf3475be49446b9de33b36ba2f/ChokudaiSearch.cpp)|3282136|[提出リンク](https://atcoder.jp/contests/ahc002/submissions/22067923)|
|評価関数に中心からのチェビシェフ距離を追加(重み10)|[ChokudaiSearch.cpp](https://github.com/petite-etoile/AHC002/blob/d4095f541dd86ecf3475be49446b9de33b36ba2f/ChokudaiSearch.cpp)|4924141|[提出リンク](https://atcoder.jp/contests/ahc002/submissions/22083857)|


※masterブランチにファイルがあります
