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
const int N=3e5+10,M=1e6+10;
vector<pii> e[N];
struct Edge{
    int u,v,w;
};
int n,m;
vector<Edge> edge;
bool vis[N];
int dis1[N],dis2[N];
void dijkstra(int st,int *dis){
    for(int i=1;i<=n;i++) vis[i]=false,dis[i]=INT_MAX;
    dis[st]=0;
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    Q.push({0,st});
    while(Q.size()){
        auto [d,u]=Q.top();
        Q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto&[v,w]:e[u]){
            if(vis[v]) continue;
            if(max(w,d)<dis[v]){
                dis[v]=max(w,d);
                Q.push({max(w,d),v});
            }
        }
    }
}
void sol() {
    cin>>n>>m;
    int ans=INT_MAX;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        if(u>v) swap(u,v);
        if(u==1&&v==n){
            ans=w;
            continue;
        }
        edge.push_back({u,v,w});
        edge.push_back({v,u,w});
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dijkstra(1,dis1);
    dijkstra(n,dis2);
    for(const auto&[u,v,w]:edge){
        if(dis1[u]>w||dis2[v]>w) continue;
        array<int,3> tmp={w,dis1[u],dis2[v]};
        sort(tmp.begin(),tmp.end(),greater<int>());
        ans=min(ans,tmp[0]+tmp[1]);
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