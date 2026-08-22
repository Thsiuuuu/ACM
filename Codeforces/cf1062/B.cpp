#include <bits/stdc++.h>
using namespace std;

#define int long long 

void sol(){
    string s,t;
    int n;
    cin>>n;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    // cout<<s<<'\n';
    if(s==t) cout<<"yes\n";
    else cout<<"no\n";
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