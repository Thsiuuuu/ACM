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
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
void sol() {
    int n;ll x,y;cin>>n>>x>>y;
    VL a(n+1,0),pre(n+1,-1e18),suf(n+2,-1e18);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],(a[i]&y)-a[i]);
    for(int i=n;i>=1;i--) suf[i]=max(suf[i+1],(a[i]&y)-a[i]);
    ll ans=1e18;
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=a[i];
    for(int i=1;i<=n;i++){
        ans=min(ans,sum+(a[i]|x)-a[i]+max({suf[i+1],pre[i-1],((a[i]|x)&y)-(a[i]|x)}));
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