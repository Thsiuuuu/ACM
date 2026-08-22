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

const int N=1e6+10;
int fa[N],siz[N];
int n,m;
bool vis[N];

void init(){
    for(int i=1;i<=n;i++){
        siz[i]=1;
        fa[i]=i;
    }
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    if(siz[fx]<siz[fy]) swap(fx,fy);
    siz[fx]+=siz[fy];
    fa[fy]=fx;
}

void sol() {
    cin>>n>>m;
    init();
    ll ans=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(find(u)==find(v)) ans++;
        else{
            unite(u,v);
        }
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(!vis[find(i)]){
            sum++;
            vis[find(i)]=true;
        }
    }

    // cout<<sum<<'\n';
    ans+=(sum-1);
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