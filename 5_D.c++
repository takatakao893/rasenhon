#include<bits/stdc++.h>
using namespace std;
int INF = 1e9+5;
long cnt = 0;

void merge(vector<int> &A,int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    int i,j;
    for(i=0; i<n1; i++){
        L[i] = A[left+i];
    }
    for(j=0; j<n2; j++){
        R[j] = A[mid+j];
    }
    i=j=0;
    L[n1]=INF;
    R[n2]=INF;
    for(int k=left; k<right; k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i+=1;
        }else{
            A[k]=R[j];
            j+=1;
            cnt+=n1-i;
        }
    }
    return;
}

void mergeSort(vector<int> &A,int left,int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> S(n);
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
    mergeSort(S, 0, n);
    
    cout << cnt << endl;
    return 0;
}