#include<bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N){
    int cnt=0;
    for(int i=0; i<N; i++){
        int minj=i;
        for(int j=i; j<N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            swap(A[i],A[minj]);
            cnt+=1;
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
    res=selectionSort(A,N);
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