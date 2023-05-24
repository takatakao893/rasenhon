#include<bits/stdc++.h>
using namespace std;

struct card {char suit; int value;};

void bs(struct card a[], int n){
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=i+1; j--){
            if(a[j].value<a[j-1].value){
                card t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
        }
    }
}

void ss(struct card a[], int n){
    for(int i=0; i<n; i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(a[j].value<a[minj].value){
                minj=j;
            }
        }
        card t=a[i];
        a[i]=a[minj];
        a[minj]=t;
    }
}

void print(struct card a[], int n){
    for(int i=0; i<n; i++){
        if(i>0) cout << " ";
        cout << a[i].suit << a[i].value;
    }
    cout << endl;
}

bool iss(struct card c1[],struct card c2[], int n){
    for(int i=0; i<n; i++){
        if(c1[i].suit!=c2[i].suit){
            return false;
        }
    }
    return true;
}

int main(){
    card c1[999],c2[999];
    int n;
    char ch;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> c1[i].suit >> c1[i].value;
    }

    for(int i=0; i<n; i++){
        c2[i]=c1[i];
    }
    bs(c1,n);
    ss(c2,n);
    print(c1,n);
    cout<<"Stable"<<endl;
    print(c2,n);
    if(iss(c1,c2,n)){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    return 0;
}