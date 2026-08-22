#include <bits/stdc++.h>
using namespace std;
/*

    很显然，这个从外向内按照括号种类进行消除
    可以转换成如果当前字符等级比自己低的还存在，就不可以，否则就是可以消除的

*/
void sol() {
    string s;
    cin>>s;
    vector<int> sum(5,0);
    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            sum[1]++;
            stk.push(s[i]);
        }else if(s[i]=='['){
            sum[2]++;
            stk.push(s[i]);
        }else if(s[i]=='('){
            sum[3]++;
            stk.push(s[i]);
        }else if(s[i]=='<'){
            sum[4]++;
            stk.push(s[i]);
        }else if(s[i]=='}'){
            if(stk.size()==0||stk.top()!='{'||sum[2]+sum[3]+sum[4]){
                cout<<"NO\n";
                return ;
            }else{
                stk.pop();
                sum[1]--;
            }
        }else if(s[i]==']'){
            if(stk.size()==0||stk.top()!='['||sum[3]+sum[4]){
                cout<<"NO\n";
                return ;
            }else{
                stk.pop();
                sum[2]--;
            }
        }else if(s[i]==')'){
            if(stk.size()==0||stk.top()!='('||sum[4]){
                cout<<"NO\n";
                return ;
            }else{
                stk.pop();
                sum[3]--;
            }
        }else{
            if(stk.size()==0||stk.top()!='<'){
                cout<<"NO\n";
                return ;
            }else{
                stk.pop();
                sum[4]--;
            }
        }
    }
    if(stk.size()){
        cout<<"NO\n";
    }else cout<<"YES\n";
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