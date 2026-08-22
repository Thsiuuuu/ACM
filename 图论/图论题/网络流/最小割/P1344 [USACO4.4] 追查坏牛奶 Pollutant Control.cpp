#include <bits/stdc++.h>
using namespace std;
/*

    对每个容量都乘a倍，那么答案%a就是最终的割边数量

*/
#define ll long long 
const int N=33;
const ll mod=1e3+10;
struct Edge{
    int from,to;
    ll cap,flow;
    Edge(int u,int v,ll c,ll f):from(u),to(v),cap(c),flow(f){}
};

struct Dinic{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[N];
    int d[N],cur[N];
    bool vis[N];

    void init(int n){
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,ll cap){
        edges.push_back(Edge(from,to,mod*cap+1,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS(){
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(Q.size()){
            int x=Q.front();
            Q.pop();
            for(int i=0;i<G[x].size();i++){
                Edge &e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    
    ll DFS(int x,ll a){
        if(x==t||a==0) return a;
        ll flow=0,f;
        for(int &i=cur[x];i<G[x].size();i++){
            Edge &e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }

    ll Maxflow(int s,int t){
        this->s=s;
        this->t=t;
        ll flow=0;
        while(BFS()){
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INT64_MAX);
        }
        return flow;
    }
}mf;

void sol() {
    int n,m;
    cin>>n>>m;
    mf.init(n);
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        mf.AddEdge(u,v,w);
    }
    ll ans=mf.Maxflow(1,n);
    cout<<ans/mod<<" "<<ans%mod;
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