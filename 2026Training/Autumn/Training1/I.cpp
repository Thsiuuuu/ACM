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
VI e[5010];
const ll mod=998244353;
int a[5010],n,siz[5010];
ll f[5004],dp[5004][5004],nf[5004];
void dfs(int u,int fa){
    siz[u]=1;
    if(e[u].size()==1&&fa!=0){
        if(a[u]==1) dp[u][0]=dp[u][1]=1;
        if(a[u]>1) dp[u][0]=1;
        return ;
    }
    for(int v:e[u]){
        if(v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    int sum=0;
    f[0]=1;
    for(int v:e[u]){
        if(v==fa) continue;
        for(int i=0;i<=sum;i++){
            for(int j=0;j<=siz[v];j++){
                nf[i+j]+=f[i]*dp[v][j]%mod;
                nf[i+j]%=mod;
            }
        }
        sum+=siz[v];
        for(int i=0;i<=sum;i++) f[i]=nf[i],nf[i]=0;
    }
    if(a[u]) dp[u][0]=f[0];  
    for(int i=1;i<=siz[u];i++){
        if(i==a[u]) dp[u][i]=f[i-1];
        else dp[u][i]=f[i]; 
    }
    for(int i=0;i<=sum;i++) f[i]=0;
}
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        e[i].clear();
        memset(dp[i],0,sizeof(dp[i]));
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    ll ans=0;
    for(int i=0;i<=n;i++)  ans=(ans+dp[1][i])%mod;
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