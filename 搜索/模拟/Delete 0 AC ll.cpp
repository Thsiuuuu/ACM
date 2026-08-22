#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

https://webvpn.neu.edu.cn/https/62304135386136393339346365373340bfebea318fd008d8f60d257088/problems/42

*/
void sol() {
    string s;
    while(getline(cin,s)){
        istringstream iss(s);
        vector<string> tokens;
        string token;
        while(iss>>token){
            tokens.push_back(token);
        }
        int ans=stoll(tokens[0]);
        for(int i=1;i<tokens.size();i+=2){
            int cur=stoll(tokens[i+1]);
            if(tokens[i]=="+") ans+=cur;
            else ans-=cur;
        }        
        cout<<ans<<'\n';
    }
}

signed  main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t=1;
    while (t--) {
        sol();
    }
    return 0;
}