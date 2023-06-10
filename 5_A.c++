#include<bits/stdc++.h>
using namespace std;

int A[30],n;

int solve(int i,int m){
    if(m==0) return true;
    if(i>=n) return false;
    int res = solve(i+1,m) || solve(i+1,m-A[i]);
    return res;
}


int main(){
    int q,M,i;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> A[i];
    }
    cin >> q;
    for(i=0; i<q; i++){
        cin >> M;
        if(solve(0,M)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

    }


}