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
const int N=2e5+3;
ll f[N],a[N];
void sol() {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(i<=k) f[i]=0;
        else{
            f[i]=1e18;
            ll c=i;
            for(ll x=2;x*x<=c;x++){
                if(c%x==0) {
                    f[i]=min(f[i],x*f[i/x]);
                    while(c%x==0) c/=x;
                }
            }
            if(c>=2) f[i]=min(f[i],c*f[i/c]);
            f[i]+=1;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=f[a[i]];
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