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
const int N=5e3+2;
int n,dfn[N*2],low[N*2],tt,tot,cnt,head[N*2],scc[N*2];
bool vis[N*2];
stack<int> s;
bool is[N][N];
int all[N];
vector<int> pl,pr;
struct node{
    int to,next;
}e[N*N];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
}

void tarjan(int u){
    dfn[u]=low[u]=++tt;
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

void sol(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int v;cin>>v;
            is[i][v]=is[v][i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(is[i][j]){
                add(i,j+n);
                add(j,i+n);
            }else{
                add(i+n,j);
                add(j+n,i);
            }
        }
    }
    for(int i=1;i<=2*n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        if(scc[i]<scc[i+n]) pl.push_back(i);
        else if(scc[i]>scc[i+n]) pr.push_back(i);
        else{
            cout<<"0";
            return ;
        }
    }
    for(int x:pl){
        for(int y:pr){
            if(is[x][y]) all[x]++;
            else all[y]++;
        }
    }
    ll ans=(pr.size()&&pl.size());
    if(n==2){
        cout<<2;
        return ;
    }
    if(pl.size()!=1){
        for(int x:pl){
            if(all[x]==pr.size()) ans++;
        }
    }
    if(pr.size()!=1){
        for(int x:pr){
            if(all[x]==pl.size()) ans++; 
        }
    }
    for(int x:pr){
        for(int y:pl){
            if(all[x]-(!is[x][y])+1==pl.size()&&all[y]-is[x][y]+1==pr.size()){
                ans++;
            }
        }
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