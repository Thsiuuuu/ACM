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
    int n;cin>>n;
    VL l(n),r(n);
    vector<pii> a(n);
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        a[i].first=l[i],a[i].second=r[i];
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    ll ans=1e18;
    for(int i=0;i<n;i++){
        ll sum=0;
        auto [x,y]=a[i];
        sum+=lower_bound(r.begin(),r.end(),x)-r.begin();
        sum+=l.end()-upper_bound(l.begin(),l.end(),y);
        ans=min(ans,sum);
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