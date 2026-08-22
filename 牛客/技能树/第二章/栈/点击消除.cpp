#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    stack<char> stk;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(stk.size()&&stk.top()==s[i]){
            stk.pop();
        }else{
            stk.push(s[i]);
        }
    }
    if(stk.size()){
        string t;
        while(stk.size()){
            t.push_back(stk.top());
            stk.pop();
        }
        reverse(t.begin(),t.end());
        cout<<t;
    }else{
        cout<<stk.size();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}