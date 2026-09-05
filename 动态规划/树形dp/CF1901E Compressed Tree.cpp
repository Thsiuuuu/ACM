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

const int N=5e5+10;
ll f[N],a[N],n,ans;
VI e[N];
void dfs1(int u,int fa){
    f[u]=a[u];
    ans=max(ans,a[u]);
    VL ff;
    for(int v:e[u]){
        if(v==fa) continue;
        dfs1(v,u);
        f[u]=max(f[u],f[v]);
        ans=max(ans,a[u]+f[v]);
        ff.push_back(f[v]);
    }
    sort(ff.begin(),ff.end(),greater<ll>());
    if(ff.size()>=2) {
        ans=max(ans,ff[0]+ff[1]);
        ll sum=ff[0]+ff[1];
        for(int i=2;i<ff.size()&&ff[i]>0;i++) sum+=ff[i];
        f[u]=max(f[u],sum+a[u]);
    }
    if(ff.size()>=3){
        ll sum=ff[0]+ff[1]+ff[2];
        for(int i=3;i<ff.size()&&ff[i]>0;i++) sum+=ff[i];
        ans=max(ans,sum+a[u]); 
    }
}
void sol() {
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++){
        f[i]=a[i]=0;
        e[i].clear();
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }   
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
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