#include <bits/stdc++.h>
using namespace std;
/*

    

*/
#define ll long long 
const ll inf=0x3f3f3f3f3f3f3f3fLL;
const int N=210;
// const ll mod=1e3+10;
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
        edges.push_back(Edge(from,to,cap,0));
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
            flow+=DFS(s,inf);
        }
        return flow;
    }
}mf;

void sol() {
    int n,m,c1,c2;
    cin>>n>>m>>c1>>c2;
    mf.init(2*n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mf.AddEdge(u+n,v,inf);
        mf.AddEdge(v+n,u,inf);
    }
    for(int i=1;i<=n;i++){
        mf.AddEdge(i,i+n,1);
    }
    ll ans=mf.Maxflow(c1+n,c2);
    cout<<ans;
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