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
const int N=4010;
ll f[N][N],g[N][N];
int n,k;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void sol() {
    f[0][0]=1;
    cin>>n>>k;
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            f[i][j]=f[i-1][j-1]*((k-j+1+mod)%mod)%mod;
            f[i][j]=(f[i][j]+g[i-1][j])%mod;
        }
        ans=(ans+(f[i][k]*ksm(k,n-i)%mod))%mod;
        f[i][0]=f[i][k];
        for(int j=k-1;j>=1;j--){
            g[i][j]=(f[i][j]+((j<k-1)?g[i][j+1]:0))%mod;
        }
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