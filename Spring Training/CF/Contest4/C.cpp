#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

struct Edge{
    int v,w;
};
const int N=1e5+10;
vector<Edge> e[N];

void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    vector<bool> vis(N,false);
    vector<int> dis(N,INT32_MAX);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,1});
    dis[1]=0;
    while(q.size()){
        auto [d,u]=q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto [v,w]:e[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
    if(dis[n]==INT32_MAX) cout<<"-1";
    else cout<<dis[n];
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