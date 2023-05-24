#include<bits/stdc++.h>
using namespace std;

void printArray(int A[],int N){
    for(int i=0; i<N; i++){
        cout << A[i];
        if(i==N-1){
            cout << "\n";
        }else{
            cout << " ";
        }
    }
}

void insertionSort(int A[],int N){
    for(int i=1; i<N; i++){
        int v=A[i];
        int j=i-1;
        while (j>=0 and A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        printArray(A,N);
    }
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    printArray(A,N);
    insertionSort(A,N);
    return 0;
}