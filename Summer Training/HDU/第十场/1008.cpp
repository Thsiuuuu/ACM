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
#define I (n+2,0)
void sol() {
    int n;cin>>n;
    VL a(n+2,0),pr I,sf I,Mp I, Ms I;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pr[i]=pr[i-1]+a[i];
        Mp[i]=max(Mp[i-1],pr[i]);
    }
    for(int i=n;i>=1;i--){
        sf[i]=sf[i+1]+a[i];
        Ms[i]=min(Ms[i+1],sf[i]);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<Mp[i]<<" "<<Ms[i]<<'\n';
    // }
    ll ans=-1e18;
    for(int i=1;i<=n;i++){
        ans=max(ans,pr[i]);
        ans=max(ans,sf[i]-Ms[i+1]+Mp[i-1]);
        // cout<<i<<" "<<ans<<'\n';
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}