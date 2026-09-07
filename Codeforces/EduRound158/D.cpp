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

#define 艹 (n+2,0)
void sol() {
    int n;cin>>n;
    VL a 艹,suf 艹,pre 艹;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        pre[i]=max(pre[i-1],a[i]-i+n);
    }  
    for(int i=n;i>=1;i--) {
        suf[i]=max(suf[i+1],a[i]+i-1);
    }
    ll ans=1e18;
    for(int i=1;i<=n;i++){
        ans=min(ans,max({pre[i-1],suf[i+1],a[i]}));
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