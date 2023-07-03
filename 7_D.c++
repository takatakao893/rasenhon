#include<bits/stdc++.h>
using namespace std;

struct node{
    int parent, left, right;
};

vector<node> V; //木の頂点を配列Vで保持

//後攻順で出力する
void dfs(int v){
    if(V[v].left != -1){ //左の子が存在する場合
        dfs(V[v].left); //左の子から再帰的に探索
    }
    if(V[v].right != -1){ //右の子が存在する場合
        dfs(V[v].right); //右の子から再帰的に探索
    }

    cout << v+1; 
    if(V[v].parent == -1){ //親が存在しない場合 
        cout << endl;
    }
    else{
        cout << " ";
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> pre(n); //先行順巡回でi番目に訪れる頂点番号を管理する配列preを用意する
    vector<int> invmid(n); //頂点番号iが中間順巡回で何番目に訪れるかを管理する配列invmidを用意する
    vector<int> mid(n); //中間順巡回でi番目に訪れる頂点番号を管理する配列midを用意する
    for(int i=0; i<n; i++){
        cin >> pre[i];
        pre[i]--; //preを0indexにするため1減らす
    }
    for(int i=0; i<n; i++){
        cin >> mid[i];
        mid[i]--;
        invmid[mid[i]]=i;
    }
    int root = pre[0]; //木の根をpre[0]とする
    V.assign(n, node{-1,-1,-1,}); //頂点の配列を全ての要素を-1にして初期化

    for(int i=0; i<n-1; i++){
        if(invmid[pre[i]] > invmid[pre[i+1]]){ //中間順巡回でpre[i]の前にpre[i+1]を訪れる場合
            V[pre[i]].left = pre[i+1]; //pre[i]の左の子をpre[i+1]にする
            V[pre[i+1]].parent = pre[i]; //pre[i+1]の親をpre[i]にする
        }
        else{
            for(int k=invmid[pre[i+1]]; k>=0; k--){
                int j=mid[k];
                if(V[j].right == -1 && (V[j].parent != -1 || V[j].left != -1 || j==root)){
                    V[j].right = pre[i+1]; //jの右の子をpre[i+1]にする
                    V[pre[i + 1]].parent = j; //pre[i+1]の親をjにする
                    break;
                }
            }
        }
    }
    dfs(root);

    return 0;
}