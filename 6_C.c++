#include<bits/stdc++.h>
using namespace std;

struct card{
    int value;
    char suit;
};

int partition(vector<card>& A,int p,int r){
    int x=A[r].value;
    int i=p-1;
    for(int j=p;j<r;j++){
        if(A[j].value<=x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void quicksort(vector<card>& A,int p,int r){
    if(p<r){
        int q = partition(A,p,r); // 末尾を基準位置にpartitionを行う
        quicksort(A,p,q-1); //求めたpartitionの位置を区切りに再帰的にクイックソートを行う
        quicksort(A,q+1,r); //求めたpartitionの位置を区切りに再帰的にクイックソートを行う
    }
}

/*
    二つのカードの列で同じ数字を持つカードがある場合、それらが同じ順序で登場するかを確認する
*/
bool stable(vector<card> A,vector<card> B, int N){
    map<int,vector<int>> Aorder; //列Aの各数字に関して絵柄の登場順を管理する連想配列
    map<int,vector<int>> Border; //列Bの各数字に関して絵柄の登場順を管理する連想配列
    //バケットソートのような感じ
    for(int i=0;i<N;i++){
        Aorder[A[i].value].push_back(A[i].suit);
    }
    for(int i=0;i<N;i++){
        Border[B[i].value].push_back(B[i].suit);
    }

    return (Aorder==Border);
}

int main(){
    int n;
    cin >> n;
    vector<card> S(n);
    for(int i=0;i<n;i++){
        char suit;
        int val;
        cin >> suit >> val;
        S[i] = card{val,suit};
    }
    vector<card> T=S; //ソートするようにカード列をコピーしてTとおく
    quicksort(T,0,n-1);

    if(stable(T,S,n)){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }

    for(int i=0; i<n; i++){
        cout << T[i].suit << " " << T[i].value << endl;
    }
    return 0;

}