#include <bits/stdc++.h>
using namespace std;
/*



*/

const int N=5e3+10;
struct Edge{
    int v,w;
};

vector<Edge> e[N];
vector<int> dis(N,0),cnt(N,0),vis(N,0);


bool spfa(int n,int s){
    queue<int> q;
    for(int i=0;i<=n;i++){
        dis[i]=INT32_MAX;
    }
    dis[s]=0,vis[s]=1;
    q.push(s);
    while(q.size()){
        int u=q.front();
        q.pop(),vis[u]=0;
        for(auto [v,w]:e[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n) return false;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    return true;
}

void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        e[v].push_back({u,c});
    }
    for(int i=1;i<=n;i++){
        e[0].push_back({i,0});
    }
    if(spfa(n+1,0)){
        for(int i=1;i<=n;i++){
            cout<<dis[i]<<" ";
        }
    }else{
        cout<<"NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}