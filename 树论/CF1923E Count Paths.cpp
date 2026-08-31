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
const int N=2e5+10;
VI e[N];
int col[N],c[N],n;
ll ans=0;
void dfs(int u,int fa){
    ans+=col[c[u]];
    ll sum=col[c[u]];
    for(int v:e[u]){
        if(v^fa){
            col[c[u]]=1;
            dfs(v,u);
        }
    }
    col[c[u]]=1+sum;
}
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    ans=0;
    for(int i=1;i<=n;i++){
        e[i].clear();
        col[i]=0;
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
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