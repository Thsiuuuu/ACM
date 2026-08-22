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
const int N=8e6+2,M=2e6+2;
int n,m,k,dfn[N],low[N],tt,tot,cnt,head[N],scc[N];
int zi[M][2],yun[M][2];
bool vis[N],is[M];
stack<int> s;

struct node{
    int to,next;
}e[N];

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
    cin>>n>>m>>k;
    tt=tot=cnt=0;
    int nct=0;
    for(int i=1;i<=n;i++){
        for(int k=0;k<2;k++){
            zi[i][k]=++nct;
            dfn[nct]=low[nct]=vis[nct]=is[nct]=head[nct]=scc[nct]=0;
        }
    }
    for(int i=1;i<=m;i++){
        for(int k=0;k<2;k++){
            yun[i][k]=++nct;
            // cout<<nct<<'\n';
            dfn[nct]=low[nct]=vis[nct]=is[nct]=head[nct]=scc[nct]=0;
        }
    }
    vector<vector<array<int,3>>> Q(m+1);
    for(int i=0;i<k;i++){
        int u,v,y,z;
        cin>>u>>v>>y>>z;
        if(y&&!z) is[v]=1;
        Q[v].push_back({u,y,z});
    }
    for(int i=1;i<=m;i++){
        for(const auto[u,y,z]:Q[i]){
            if(y==0&&z==0){
                add(zi[u][1],yun[i][0]);
                add(yun[i][1],zi[u][0]);
            }else if(!y&&z){
                add(zi[u][0],zi[u][1]);
                add(yun[i][0],yun[i][1]);
            }else if(y&&!z){
                add(zi[u][1],yun[i][1]);
                add(zi[u][0],yun[i][0]);
                add(yun[i][0],zi[u][0]);
                add(yun[i][1],zi[u][1]);
            }else{
                add(zi[u][0],yun[i][1]);
                add(yun[i][0],zi[u][1]);
                if(is[i]){
                    add(zi[u][1],yun[i][0]);
                    add(yun[i][1],zi[u][0]);
                }
            }
        }
    }
    for(int i=1;i<=nct;i++){
        if(!dfn[i]) tarjan(i);
    }
    // cout<<nct<<'\n';
    for(int i=1;i<=n;i++){
        if(scc[zi[i][0]]==scc[zi[i][1]]){
            cout<<"NO\n";
            return ;
        }
    }
    for(int i=1;i<=m;i++){
        if(scc[yun[i][1]]==scc[yun[i][0]]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        cout<<(scc[zi[i][0]]>scc[zi[i][1]]);
    }
    cout<<'\n';
    for(int i=1;i<=m;i++){
        if(scc[yun[i][0]]<scc[yun[i][1]]) cout<<'&';
        else{
            if(is[i]) cout<<"^";
            else cout<<'|';
        }
    }
    cout<<'\n'; 
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