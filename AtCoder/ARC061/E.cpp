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

struct Edge{
    int v,p;  
};

struct node{
    ll dis;
    int u;
    int from;
    bool operator<(const node&other)const{
        return dis>other.dis;
    }
};
const int N=1e5+10;
vector<Edge> e[N]; 

void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,p;
        cin>>u>>v>>p;
        e[u].push_back({v,p});
        e[v].push_back({u,p});
    }
    vector<ll> ans(n+1,1e18);
    vector<bool> vis(n+1,false);
    priority_queue<node> q;
    q.push({1,1,0});
    ans[1]=1;
    while(q.size()){
        auto [dis,u,from]=q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto&[v,p]:e[u]){
            int add=(from!=0&&from!=p);
            if(dis+add<ans[v]){
                ans[v]=dis+add;
                q.push({ans[v],v,p});
            }
        }
    }
    if(ans[n]==1e18) ans[n]=-1;
    cout<<ans[n];
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