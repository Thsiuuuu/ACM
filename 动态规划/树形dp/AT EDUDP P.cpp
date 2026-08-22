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
const ll mod=1e9+7,N=1e5+10;
VI e[N];
int n;
ll f[N][2];
void dfs(int u,int fa){
    f[u][0]=f[u][1]=1;
    for(int v:e[u]){
        if(v^fa){
            dfs(v,u);
        }
    }
    for(int v:e[u]){
        if(v^fa){
            f[u][1]*=f[v][0];
            f[u][1]%=mod;
        }
    }
    for(int v:e[u]){
        if(v^fa){
            f[u][0]*=(f[v][0]+f[v][1])%mod;
            f[u][0]%=mod;
        }
    }
}
void sol() {
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    cout<<(f[1][0]+f[1][1])%mod;
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