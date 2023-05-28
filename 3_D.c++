#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> down; //下り斜面のindexを管理するスタックを用意する
    stack<pair<int, int>> pool; //水たまりの位置,面積をペアにしたスタックを用意する
    string S; //Sの型を文字列で指定
    cin >> S; //地形の様子を受け取る
    int n = S.size();

    for(int i=0; i<n; i++){
        if(S[i]=='/'){ //Sのi文字目が/(上り斜面)である場合
            if(down.size() == 0){ //対応する下り斜面(\)が無い場合
                continue;
            }
            int D = down.top(); //下り斜面のスタックの先頭をDとする
            down.pop(); //downの先頭を消去する
            int area = i - D; //この場所,この高さにできる水たまりの面積を求める

            while(pool.size()>0){ //水溜まりのスタックが空でない限り繰り返し
                pair<int, int> P = pool.top(); //水溜まりの先頭をPとする
                if (P.first <= D){
                    break;
                }
                pool.pop(); //水溜まりのスタックの先頭を削除する
                area += P.second; //二つの水溜まりを合わせる(面積を足し合わせる)
            }

            pool.push(make_pair(D, area)); //今できた水たまりを水たまりスタックに追加する
        }else if(S[i]=='_'){
            //Sのi文字目が_の場合
        }else{
            //それ以外の場合
            down.push(i); //下り坂のスタックに今のインデックスiを追加する
        }
    }

    int pn = pool.size(); //pnを水溜まりの数とおく
    int ps = 0; //水溜まりの総面積を表す整数psを用意して,0で初期化

    vector<int> an(pn); //水溜まりの面積列を入れる長さpnの整数配列を用意する
    for(int i=pn - 1; i>=0; i--){
        an[i] = pool.top().second; //anのi番目に水溜まりの面積を入れる
        ps += an[i]; //面積の総和に現在の水溜まりの面積を加算する
        pool.pop(); //集計の終わった水溜まりをスタックから消す
    }
    cout << ps << endl; //水溜まりの総面積を出力する
    cout << pn; //水溜まりの数を出力する
    for(int i=0; i<pn; i++){
        cout << " " << an[i];
    }
    cout << endl;
    return 0;
}