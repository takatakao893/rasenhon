#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &A,int p,int r){
    int x = A[r];
    int i = p-1;
    for(int j=p; j<r; j++){
        if(A[j] <= x){
            i+=1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    int k = partition(A,0,n-1);
    for(int i=0; i<n; i++){
        if(i==k){
            cout << "[" << A[i] << "]";
        }else{
            cout << A[i];
        }
        if(i!=n-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
}