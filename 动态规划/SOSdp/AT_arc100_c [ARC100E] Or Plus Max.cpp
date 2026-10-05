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
const int N=20;
ll a[1<<N];
pll f[1<<N];
int n;
void sol() {
    cin>>n;
    for(int i=0;i<(1<<n);i++) cin>>a[i];
    for(int i=0;i<(1<<n);i++) f[i].first=a[i];
    for(int i=0;i<n;i++){
        for(int mask=0;mask<(1<<n);mask++){
            if((mask>>i)&1){
                int opj=(mask^(1<<i));
                array<ll,4> all={f[opj].first,f[opj].second,f[mask].first,f[mask].second};
                sort(all.begin(),all.end(),greater<ll>());
                f[mask]={all[0],all[1]};
            }
        }
    }
    ll ans=f[0].first;
    for(int mask=1;mask<(1<<n);mask++){
        ans=max(ans,f[mask].first+f[mask].second);
        cout<<ans<<'\n';
    }
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