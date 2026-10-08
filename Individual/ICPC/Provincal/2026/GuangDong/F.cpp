#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
void sol() {
    map<ll,int> mp;
    int n;cin>>n;
    VL a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    ll mx=*max_element(a.begin(),a.end());
    if(mx>=n){
        int ans=1;
        for(int i=0;i<n;i++){
            if(mp[i]) ans++;
            else break;
        }
        cout<<ans;
        return ;
    }
    int mex=0;
    for(int i=0;i<n;i++){
        if(mp[i]) mex++;
        else break; 
    }
    for(auto&[key,val]:mp){
        --val;
    }
    if(mex!=mx+1){
        cout<<mex+1;
        return ;
    }
    int ans=mx+2;
    for(int i=0;;i=(i+1)%(mx+1)){
        if(mp[i]==0) break;
        ans++,mp[i]--;
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