#include<bits/stdc++.h>
using namespace std;

int bubbleSort(int A[], int N){
    int cnt=0;
    bool flag=true;
    while (flag){
        flag=false;
        for(int j=N-1; j>=1; j--){
            if(A[j] < A[j-1]){
                swap(A[j],A[j-1]);
                cnt+=1;
                flag=true;
            }
        }
    }
    return cnt;
}

int main(){
    int N,res=0;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    res=bubbleSort(A,N);
    for(int i=0; i<N; i++){
        cout << A[i];
        if(i==N-1){
            cout << "\n";
        }else{
            cout << " ";
        }
    }
    cout << res << endl;
}