#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    string s;
    cin>>n>>s;
    int cnt=count(s.begin(),s.end(),s[s.size()-1]);
    cout<<n-cnt<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}