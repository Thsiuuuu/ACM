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
    int n;cin>>n;
    vector<ll> a(n+1,0),pre(n+1,INT64_MIN),suf(n+1,INT64_MIN);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        pre[i]=max(pre[i-1],a[i]-a[i-1]);
    }
    for(int i=n-1;i>=1;i--){
        suf[i]=max(suf[i+1],a[i+1]-a[i]);
    }   
    ll ans=INT64_MAX;
    for(int i=2;i<=n-1;i++){
        ans=min(ans,max({a[i+1]-a[i-1],pre[i-1],suf[i+1]}));
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