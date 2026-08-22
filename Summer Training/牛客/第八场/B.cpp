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
const ll mod=998244353;
const int N=5003;
ll f[N<<1],g[N<<1];
int suf[N<<1];
bool is[N<<1];
void sol() {
    int n,m;cin>>n>>m;
    for(int i=0;i<=2*n;i++) f[i]=g[i]=suf[i]=is[i]=0;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        suf[min(2*n+1,x)]++;
        is[min(2*n+1,x)]=1;
    }
    for(int i=2*n;i>=1;i--) suf[i]+=suf[i+1]; 
    // cout<<suf[1]<<'\n';
    f[0]=1;
    ll ans=0;
    for(int i=1;i<=2*n;i++){
        for(int j=n-suf[i+1];j>=n-j;j--){
            g[j]=f[j];
        }
        for(int j=n-suf[i+1];j>=n-j;j--){
            if(is[i]){
                f[j]=g[j-1];
            }else{
                f[j]=(g[j-1]+g[j])%mod;
            }
        }
        ans+=f[n];
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