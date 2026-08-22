#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    string s;
    cin>>s;
    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if(stk.size()==0){
            stk.push(s[i]);
        }else{
            if(s[i]=='B'){
                stk.pop();
            }else{
                stk.push(s[i]);
            }
        }
    }
    cout<<stk.size()<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}