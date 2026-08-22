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
const ll inf=0x3f3f3f3f3f3f3f3fLL;
const int N=1100;
// const ll mod=1e3+10;
struct Edge{
    int from,to;
    ll cap,flow;
    Edge(int u,int v,ll c,ll f):from(u),to(v),cap(c),flow(f){}
};

bool is[N-99][31];

struct Dinic{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[N];
    int d[N],cur[N];
    bool vis[N];
    
    vector<int> ke;

    void xiu(int x){
        for(const auto&bian:ke){
            edges[bian].cap=x;
        }
    }

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
};
bool ck(int x,int n,int k){
    Dinic mf;
    mf.init(n+k+2);
    for(int i=1;i<=n;i++){
        mf.AddEdge(0,i,1);
        for(int j=1;j<=k;j++){
            if(is[i][j]){
                mf.AddEdge(i,j+n,1);
            }
        }
    }
    for(int j=1;j<=k;j++) mf.AddEdge(j+n,n+k+1,x);
    return mf.Maxflow(0,n+k+1)==x*k;
}
void sol() {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=k;j++){
        char x;cin>>x;
        is[i][j]=(x-'0');
    }
    int l=0,r=n/k,mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(ck(mid,n,k)) ans=mid,l=mid+1;
        else r=mid-1;
    }    
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