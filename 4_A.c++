#include<bits/stdc++.h>
using namespace std;

int linear_search(int n,int S[],int q,int T[]){
    int cnt=0;
    for(int i=0; i<q; i++){
        for(int j=0; j<n; j++){
            if(T[i]==S[j]){
                cnt+=1;
                break;
            }
        }
    }
    return cnt;    
}

int main(){
    int n;
    cin >> n;
    int S[n];
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
    int q;
    cin >> q;
    int T[q];
    for(int i=0; i<q; i++){
        cin >> T[i];
    }
    int res=0;
    res=linear_search(n,S,q,T);
    cout << res << endl;
    return 0;
}