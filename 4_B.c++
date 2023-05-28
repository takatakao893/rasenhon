#include<bits/stdc++.h>
using namespace std;

bool binary_search(int key, int S[], int n){
    int left=0;
    int right=n;
    while (left<right){
        int mid=(left+right)/2;
        if(S[mid]<key){
            left=mid+1;
        }else if(S[mid]>key){
            right=mid;
        }else{
            return true;
        }
    }
    return false;
}

int main(){
    int n,q,cnt=0;
    cin >> n;
    int S[n];
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
    cin >> q;
    for(int i=0; i<q; i++){
        int a;
        cin >> a;
        if(binary_search(a,S,n)) cnt+=1;
    }
    cout << cnt << endl;
    return 0;       
}