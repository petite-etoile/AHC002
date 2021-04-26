# AHC002
[AtCoder](https://atcoder.jp)のヒューリスティックスコンテストである[AtCoder Heuristic Contest](https://atcoder.jp/contests/ahc002)に対する回答

## ChokudaiSearch.cpp 
[Chokudaiサーチ(ビームサーチ亜種)](https://chokudai.hatenablog.com/entry/2017/04/12/055515)を用いた解法

## BeamSearch.cpp
ビームサーチを用いた解法

## 上記手法の評価関数
素のスコアを評価関数に用いると微妙
最後、袋小路になって止まってしまうことを考えると、渦巻き状になるとうれしい -> 中心からのチェビシェフ距離を評価関数に追加する

※masterブランチにファイルがあります
