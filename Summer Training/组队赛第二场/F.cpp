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
const int N=2e5+10;
VI e[N];
int n,st[N][22],dep[N],dis[N];
void dfs1(int u,int fa){
    dep[u]=dep[fa]+1;
    st[u][0]=fa;
    dis[u]=dis[fa]+1;
    for(int i=1;i<=20;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(int v:e[u]){
        if(v^fa){
            dfs1(v,u);
        }
    }
}
void dfs2(int u,int fa){
    dis[u]=dis[fa]+1;
    for(int v:e[u]){
        if(v^fa){
            dfs2(v,u);
        }
    }
}
int LCA(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=20;i>=0;i--){
        if(dep[st[a][i]]>=dep[b]) a=st[a][i];
    }   
    if(a==b) return a;
    for(int i=20;i>=0;i--){
        if(st[a][i]!=st[b][i]) a=st[a][i],b=st[b][i];
    }
    return st[a][0];
}
int gd(int a,int b){
    int p=LCA(a,b);
    return dep[a]+dep[b]-2*dep[p];
}
void sol() {
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    int a,b,c;
    a=0,b=0,c=-1;
    dfs1(1,0);
    for(int i=1;i<=n;i++){
        if(dis[a]<dis[i]) a=i;
    }
    dis[0]=-1;
    dfs2(a,0);
    // cout<<dis[a]<<'\n';
    for(int i=1;i<=n;i++){
        if(dis[b]<dis[i]) b=i;
    }
    ll ans=-1;
    for(int i=1;i<=n;i++){
        if(i==a||i==b) continue;
        int d=(gd(i,a)+gd(i,b)-gd(a,b))/2;
        if(d>ans) c=i,ans=d;
    }
    ans+=*max_element(dis+1,dis+1+n);
    cout<<ans<<'\n';
    cout<<a<<" "<<b<<" "<<c;
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