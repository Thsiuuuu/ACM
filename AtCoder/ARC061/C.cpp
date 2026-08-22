#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
void sol() {
    string s;
    cin>>s;
    int n=s.size();
    ll ans=0;
    if(n==1){
        cout<<s;
        return ;
    }
    for(int mask=0;mask<(1<<(n-1));mask++){
        // cout<<mask<<' ';
        vector<ll> all;
        string tmp(1,s[0]);
        for(int i=n-2;i>=0;i--){
            if((mask>>i)&1){
                all.push_back(stoll(tmp));
                tmp.assign(1,s[n-1-i]);
            }else tmp+=s[n-1-i];
        } 
        // cout<<ans<<'\n';
        // cout<<tmp<<'\n';
        all.push_back(stoll(tmp));
        for(int i=0;i<all.size();i++) ans+=all[i];
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}