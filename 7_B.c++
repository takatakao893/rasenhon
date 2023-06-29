#include<bits/stdc++.h>
using namespace std; 

struct node{
    int id,parent,depth,height,deg,left,right;
};

int main(){
    int n;
    cin >> n;
    vector<node> NODE(n,node{-1,-1,-1,0,0,-1,-1}); //n個のノードからなる配列NODEを用意して,初期化する
    for(int i=0;i<n;i++){
        int id,left,right; //id,left,rightを整数で指定
        cin>>id>>left>>right;
        NODE[id].id=id;
        if(left!=-1){ //左の子が存在する場合
            NODE[id].left=left;
            NODE[id].deg++; //id番のノード次数を1増やす
            NODE[left].parent=id; //左の子の親をidと登録する
        }
        if(right!=-1){ //右の子が存在する場合
            NODE[id].right=right; //id番のノードの右の子をrightと登録する
            NODE[id].deg++; //id番のノード次数を1増やす
            NODE[right].parent=id; //右の子の親をidと登録する
        }
    }

    for(int i=0;i<n;i++){
        int d=0; //深さを表す整数dを用意して0で初期化する
        int j=i; //現在見ている頂点を表す整数jを用意してiで初期化する
        while(NODE[j].parent!=-1){ //NODE[j]に親がいる間繰り返す
            j=NODE[j].parent;
            d++; //dを加算する
            NODE[j].height=max(NODE[j].height,d); //ノードjの高さを,dと現在登録している高さの高い方に更新する
        }
        NODE[i].depth=d; //NODE[i]の深さを登録する
    }

    for(int i=0;i<n;i++){
        cout<<"node ";
        cout<<NODE[i].id<<": parent = "; //ノードiの番号と": parent = "を出力
        cout<<NODE[i].parent<<", sibling = "; //ノードiの親の番号と", sibling = "を出力

        if(NODE[i].parent==-1){ //親が存在しない場合
            cout<<-1; //-1と出力
        }
        else{ //それ以外の場合
            if(NODE[NODE[i].parent].left!=-1 && NODE[NODE[i].parent].left!=i){ //親の左の子が存在して自身と異なる場合
                cout<<NODE[NODE[i].parent].left; //親の左の子の番号を出力する
            }
            else if(NODE[NODE[i].parent].right!=-1&&NODE[NODE[i].parent].right!=i){ //親の右の子が存在して自身と異なる場合
                cout<<NODE[NODE[i].parent].right; //親の右の子の番号を出力する
            }
            else{ //それ以外の場合
                cout<<-1; //-1を出力する
            }
        }
        cout<<", degree = "; //", degree = "を出力する
        cout<<NODE[i].deg; //ノードiの次数を出力する
        cout<<", depth = "; //", depth = "を出力する

        
        cout <<NODE[i].depth << ", height = "; //ノードiの深さと", height = "を出力
        cout <<NODE[i].height;

        if(NODE[i].depth==0){ //ノードiの深さが0の時
            cout<<", root"<<endl; //", root"と出力して改行する
        }
        else if(NODE[i].height==0){ //ノードiの高さが0の時
            cout<<", leaf"<<endl; //", leaf"と出力して改行する
        }
        else{ //それ以外の時
            cout << ", internal node" << endl;
        }
    }
    return 0;
}