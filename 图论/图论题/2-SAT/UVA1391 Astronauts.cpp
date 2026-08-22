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
const int N=2e6+2;
int n,m,dfn[N],low[N],t,tot,cnt,head[N],scc[N],ans[N];
bool vis[N];
stack<int> s;

struct node{
    int to,next;
}e[N<<2];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
}

void tarjan(int u){
    dfn[u]=low[u]=++t;
    s.push(u);
    vis[u]=1;
    for(int i=head[u],v;i;i=e[i].next){
        v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int cur;
        ++cnt;
        do{
            cur=s.top();
            s.pop();
            vis[cur]=0;
            scc[cur]=cnt;
        }while(cur^u);
    }
}

bool cal(ll x,ll sum,ll n){
    return x*n>=sum;
}

void sol(){
    
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        for(int i=0;i<=2*n;i++){
            head[i]=scc[i]=dfn[i]=vis[i]=low[i]=ans[i]=0;
        }
        VL num(n+1,0);
        ll sum=0;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            sum+=num[i];
        }
        cnt=tot=t=0;
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            add(u,v+n);
            add(v,u+n);
            if(cal(num[u],sum,n)==cal(num[v],sum,n)){
                add(v+n,u);
                add(u+n,v);
            }
        }
        for(int i=1;i<=2*n;i++){
            if(!dfn[i]) tarjan(i);
        }
        bool f=true;
        for(int i=1;i<=n;i++){
            ans[i]=(scc[i]<scc[i+n]?0:1);
            if(scc[i]==scc[i+n]){
                f=false;
                break;
            }
        }
        if(f){
            for(int i=1;i<=n;i++){
                cout<<(ans[i]?(cal(num[i],sum,n)?'A':'B'):((char)('C')))<<'\n';
            }
        }else cout<<"No solution.\n";
    }
    
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