#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> S(n); // 荷物の重さ,初めの位置をペアにして持つ配列Sを用意する
    int minS=1e5;   // Sの最小値を管理する整数を用意して1e5で初期化
    for(int i=0; i<n; i++){
        int W;
        cin >> W;
        S[i] = {W,i};
        minS=min(minS,W);
    }
    sort(S.begin(),S.end()); //数列Sをソートする
    int an=0;  //答えを管理する整数anを用意して0に初期化する
    vector<bool> USE(n,false);  //既に荷物を並び替えたかを表すbool値USEの配列を用意してfalseで初期化する

    for(int i=0; i<n; i++){
        if(USE[i]){ //既に荷物が正しい位置にある場合
            continue;
        }
        USE[i]=true;

        int x=S[i].second;
        int minG = S[i].first;
        int sumG=S[i].first;
        int numG=1;

        while(x!=i){//xがiと異なる間繰り返す

            minG=min(minG, S[x].first); //minGをminGとx番目の荷物の重さの小さい方に更新
            sumG+=S[x].first; //sumGにx番目の荷物の重さに更新
            numG++;
            USE[x]=true;
            x=S[x].second;
        }
        int INSwap=(sumG-minG)+minG*(numG-1); //荷物のグループの内部で整列を完了する場合のコストの最小値を計算する.この場合グループ内で最も軽い荷物を動かし続けるのが最適
        int OUTSwap=(minS+minG)+sumG+minS*(numG); //荷物のグループの内部のほか,全体で最も軽い荷物も用いる場合のコストの最小値を計算する.
        an+=min(INSwap,OUTSwap);
    }
    cout << an << endl;
    return 0;
}