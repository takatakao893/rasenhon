#include<bits/stdc++.h>
using namespace std;

struct node{
    int id, left, right, parent;
};

vector<int> pre, ino, pos;

void dfs(int n, vector<node> &NODE){
    pre.push_back(NODE[n].id); //先行順巡回の配列の末尾にn番目のノードの番号を追加
    if(NODE[n].left != -1){  //左の子が存在する場合
        dfs(NODE[n].left, NODE); //左の子について再帰的に探索をする
    }
    ino.push_back(NODE[n].id); //中間順巡回の配列の末尾にn番目のノードの番号を追加
    if(NODE[n].right != -1){
        dfs(NODE[n].right, NODE); //右の子について再帰的に探索をする
    }
    pos.push_back(NODE[n].id); //後攻順巡回の配列の末尾にn番目のノードの番号を追加
    return;
}

int main(){
    int n;
    cin >> n;
    vector<node> NODE(n, node{-1,-1,-1,-1}); //n個ノードからなる配列NODEを用意して,初期化する

    for(int i=0; i<n; i++){
        int id,left,right;
        cin >> id >> left >> right;
        NODE[id].id = id;
        if(left!=-1){ //左の子が存在する場合
            NODE[id].left=left; //id番のノードの左の子を登録する
            NODE[left].parent = id; //左の子の親にid番を設定
        }
        if(right!=-1){ //右の子が存在する場合
            NODE[id].right=right; //id番のノードの右の子を登録する
            NODE[right].parent = id; //右の子の親にid番を設定
        }
    }
    int root = -1;
    for(int i=0; i<n; i++){
        if(NODE[i].parent == -1){ //i番目のノードに親が存在しない場合
            root = i;
        }
    }
    dfs(root, NODE); //根を起点に探索を開始する

    cout << "Preorder" << endl;
    for(int i=0; i<n; i++){
        cout << " " << pre[i];
    }
    cout << endl;

    cout << "Inorder" << endl;
    for(int i=0; i<n; i++){
        cout << " " << ino[i];
    }
    cout << endl;

    cout << "Postorder" << endl;
    for(int i=0; i<n; i++){
        cout << " " << pos[i];
    }
    cout << endl;
    return 0;
}
