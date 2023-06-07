#include<iostream>
#include<map>
using namespace std;

map<string, int> arr;

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string t;
        string r;

        cin >> t >> r;

        if(t=="insert"){
            //連想配列のキーとしてタプルが使われる
            arr.insert(pair<string,int>(r,1));
        }else{
            //autoはコンパイル時に型を推測
            auto iter = arr.find(r);
            //見つかった要素へのイテレータを返す
            if(iter != arr.end()){
                cout << "yes" << endl;
            }else{//そうでない場合は、end()を返す
                cout << "no" << endl;
            }
        }
    }
}