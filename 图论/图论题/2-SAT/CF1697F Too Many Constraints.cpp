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
const int N=5e5+2;
int n,m,k,dfn[N],low[N],tt,tot,cnt,head[N],scc[N],ans[N];
int p[(N/10)][12][2];
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
    int nct=0;
    tot=tt=cnt=0;
    while(s.size()) s.pop();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k+1;j++){
            for(int nt=0;nt<=1;nt++){
                p[i][j][nt]=++nct;
                dfn[nct]=head[nct]=low[nct]=scc[nct]=ans[nct]=vis[nct]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            add(p[i][j][0],p[i][j+1][0]);
            add(p[i][j+1][1],p[i][j][1]);
            if(i<n){
                add(p[i][j][1],p[i+1][j][1]);
                add(p[i+1][j][0],p[i][j][0]);
            }
        }
        add(p[i][k+1][1],p[i][k+1][0]);
        add(p[i][1][0],p[i][1][1]);
    }
    for(int u=0;u<m;u++){
        int op;int i,j,x;
        cin>>op>>i;
        if(op==1){
            cin>>x;
            add(p[i][x+1][0],p[i][x][0]);
            add(p[i][x][1],p[i][x+1][1]);
        }else{
            cin>>j>>x;
            if(op==2){
                for(int num=1;num<=k;num++){
                    add(p[i][num][1],p[j][max(1,min(x-num+1,k+1))][0]);
                    add(p[j][max(1,min(x-num+1,k+1))][1],p[i][num][0]);
                }
            }else{
                for(int num=2;num<k+2;num++){
                    add(p[i][num][0],p[j][max(1,min(x-num+1,k+1))][1]);
                    add(p[j][max(1,min(x-num+1,k+1))][0],p[i][num][1]);
                }
            }
        }
    }
    for(int i=1;i<=nct;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        ans[i]=1;
        for(int x=1;x<=k+1;x++){
            if(scc[p[i][x][1]]==scc[p[i][x][0]]){
                cout<<"-1\n";
                return ;
            }else if(x<k+1&&scc[p[i][x][1]]<scc[p[i][x][0]]){
                ans[i]=x;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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