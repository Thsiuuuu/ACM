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
const int N=23;
const ll mod=998244353;
ll f[1<<N];
ll p[N],n,in[N];
void sol() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    bool fg=false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i]>p[j]){
                in[j]|=(1ll<<i);
                fg=true;
            }
        }
    }
    if(!fg){
        ll ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*i%mod;
        }
        cout<<ans<<'\n';
        return ;
    }
    f[0]=1;
    for(ll mask=1;mask<(1<<n);mask++){
        for(int u=0;u<n;u++){
            if(((mask>>u)&1)&&!(in[u]&mask)) f[mask]=(f[mask]+f[(mask^(1<<u))]);
        }
    }
    cout<<2*f[(1<<n)-1]%mod<<'\n';
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