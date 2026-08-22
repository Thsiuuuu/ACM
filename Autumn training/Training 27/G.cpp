#include <bits/stdc++.h>
using namespace std;

#define int long long 

int dp[120];
const int mod=1e9+7;
bool check(const string&cpy,const string&b){
    for(int i=0;i<b.size();i++){
        if(cpy[i]=='?') continue;
        if(b[i]!=cpy[i]) return false;
    }
    return true;
}

void sol(){
    int n;
    cin>>n;
    vector<string> st;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.push_back(s);
    }
    string t;
    cin>>t;
    dp[0]=1;
    for(int i=1;i<=t.size();i++){
        for(string s:st){
            if(s.size()<=i&&check(t.substr(i-s.size(),s.size()),s)){
                dp[i]=(dp[i]%mod+dp[i-(int)s.size()]%mod)%mod;
            }
        }
    }
    cout<<dp[t.size()];
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    sol();
    return 0;
}