#include <bits/stdc++.h>
using namespace std;
int a[305];
int main(){
    int n,k,total=0;
    pair<int,string> a[100005];
    queue< pair<int,string>> q,ans;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i].second>>a[i].first;
        q.push(a[i]);
    }
    while(!q.empty()){
        if(q.front().first>k){
            q.front().first-=k;
            // qの先頭を末尾に追加
            q.push(q.front());
            // qの先頭はまだ消えていないので、消す
            q.pop();
            total+=k;
        }else{
            q.front().first+=total;
            total+=q.front().first-total;
            ans.push(q.front());
            q.pop();
        }
    }
    while(!ans.empty()){
        cout << ans.front().second << " " << ans.front().first << endl;
        ans.pop();
    }
    return 0;
}