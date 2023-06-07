#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> A(n);
    int sm=0;
    for(int i=0; i<n; i++){
        cin >> A[i];
        sm+=A[i];
    }
    int mn = 0;
    int mx = sm;
    while(mx-mn > 1){
        int ce = (mn+mx) / 2;
        bool ok = true;
        int nw = 0;
        int z = 1;
        for(int i=0; i<n; i++){
            if(ce < A[i]){
                ok = false;
                break;
            }else if(nw+A[i] > ce){
                nw = A[i];
                z++;
            }else{
                nw += A[i];
            }
        }
        if(ok && z <= k){
            mx = ce;
        }else{
            mn = ce;
        }
    }
    cout << mx << endl;
}