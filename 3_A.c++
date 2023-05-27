#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack <int> st;
string s;
int a,b,num;

int main(){
    getline(cin,s);

    for(int i=0; i<s.length(); i++){
        if(s[i]=='+'){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(b+a);
        }else if(s[i]=='-'){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(b-a);
        }else if(s[i]=='*'){
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(b*a);
        }else if(s[i]!=' '){
            num=0;
            // 複数桁の数字に対応
            while(s[i]!=' '){
                num=num*10+s[i++]-'0';
            }
            st.push(num);
        }
    }

    cout << st.top() << endl;
    return 0;
}