#include<bits/stdc++.h>
using namespace std;

struct node{
    int id,parent,depth;
    vector<int> child;
};

int main(){
    int n;
    cin >> n;
    vector<node> NODE(n,node{-1,-1,-1,{}}); //n個のノードからなる配列NODEを用意して、初期化する
    for(int i=0;i<n;i++){
        int id,k;
        cin>>id>>k; //i番目に与えられる節点の番号idと次数kを受け取る
        NODE[id].id=id; //id番目のノードに番号を登録する
        for(int j=0;j<k;j++){
            int c;
            cin >> c;
            NODE[id].child.push_back(c); //id番目のノードの子を登録する
            NODE[c].parent=id; //c番目のノードの親にid番目のノードを登録する
        }
    }

    for(int i=0; i<n; i++){
        int d=0; //深さを表す整数を用意して0で初期化する
        int j=i; //現在みている頂点を表す整数を用意してiで初期化する
        while(NODE[j].parent!=-1){ //NODE[j]に親がいる間繰り返す
            j=NODE[j].parent; //jをNODE[j]の親に更新する
            d++; //dを1加算する
        }
        NODE[i].depth=d; //NODE[i]の深さを登録する
    }

    for(int i=0; i<n; i++){
        int CN=NODE[i].child.size(); //CNをノードiの子の数とする

        cout << "node "; 
        cout << NODE[i].id << ": parent = ";
        cout << NODE[i].parent << ", depth = ";
        cout << NODE[i].depth << ", ";
        if(NODE[i].parent==-1){ //ノードiに親が存在しないとき
            cout<<"root, [";
        }
        else if(CN==0){ //子が存在しないとき
            cout << "leaf, [";
        }
        else{ //それ以外の時
            cout << "internal node, [";
        }
        for(int j=0;j<CN; j++){
            cout<<NODE[i].child[j]<<(j==CN-1?"":", ");//ノードiのj番目の子を出力して,末尾でなければコンマ区切りを出力する
        }
        cout << "]" << endl;
    }

    return 0;
}