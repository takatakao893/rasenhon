#include<bits/stdc++.h>
using namespace std;
int INF = 1e9+5;
int cnt=0;

void merge(vector<int>& A,int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    
    vector<int> L(n1+1);
    vector<int> R(n2+1);
    for(int i=0; i<n1; i++){
        L[i]=A[left+i];
    }
    for(int j=0; j<n2; j++){
        R[j]=A[mid+j];
    }
    L[n1]=R[n2]=INF;
    int i=0,j=0;
    cnt+=(right-left);
    for(int k=left; k<right; k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i+=1;
        }else{
            A[k]=R[j];
            j+=1;
        }
    }
    return;
}

void mergeSort(vector<int>& A,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
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
    mergeSort(S,0,n);
    for(int i=0; i<n; i++){
        cout << S[i];
        if(i!=n-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}