#include<bits/stdc++.h>
using namespace std;

void CountingSort(vector<int> A,vector<int> B, int k){
    vector<int> C(k+1,0); //各整数の出現回数を記録する整数列を用意して0に初期化する
    int n=A.size(); //Aの長さをnとする
    for(int i=0; i<n; i++){
        C[A[i]]+=1; //C[A[i]]を1加算する
    }
    for(int i=1; i<=k; i++){
        C[i]+=C[i-1];
    }
    for(int j=n-1;j>=0;j--){
        B[C[A[j]]-1]=A[j]; //ソート後の位置にA[j]を代入
        C[A[j]]--; //A[j]以下の数を1減少
    }
    for(int i=0; i<n; i++){
        cout << B[i];
        if(i!=n-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n,0); //数列を受け取る配列を用意する
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    CountingSort(A, A, 10000);

    return 0;
}