#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
const int N=250;
struct Edge{
    int from,to;
    ll cap,flow;
    Edge(int u,int v,ll c,ll f):from(u),to(v),cap(c),flow(f){}
};

struct EK{
    int n,m;
    vector<Edge> edges;
    vector<int> G[N];
    ll a[N],p[N];

    void init(int n){
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(ll from,ll to,ll cap){
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    ll Macflow(int s,int t){
        ll flow=0;
        for(;;){
            memset(a,0,sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s]=INT32_MAX;
            while(Q.size()){
                int x=Q.front();
                Q.pop();
                for(int i=0;i<G[x].size();i++){
                    Edge& e=edges[G[x][i]];
                    if(!a[e.to]&&e.cap>e.flow){
                        p[e.to]=G[x][i];
                        a[e.to]=min(a[x],e.cap-e.flow);
                        Q.push(e.to);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u=t;u!=s;u=edges[p[u]].from){
                edges[p[u]].flow+=a[t];
                edges[p[u]^1].flow-=a[t];
            }
            flow+=a[t];
        }
        return flow;
    }
};
void sol() {
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    EK ek;
    ek.init(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ek.AddEdge(u,v,w);
    }
    cout<<ek.Macflow(s,t);
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