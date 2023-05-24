#include<bits/stdc++.h>
using namespace std;

bool judge_prime(int a){
    if(a==1) return false;
    if(a==2) return true;
    int i=2;
    while (i*i<=a){
        if(a%i==0){
            return false;
        }
        i+=1;
    }
    return true;
}

int main(){
    int n,cnt=0;
    cin >> n;
    for(int i=0; i<n; i++){
        int b=0;
        cin >> b;
        if (judge_prime(b)){
            cnt+=1;
        }
    }
    cout << cnt << endl;
}