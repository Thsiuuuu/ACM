#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const int M=3e6+10,N=2e6+10;

int head[N],to[M<<1],ne[M<<1],color[M<<1],cnt=1;
int dfn[N],low[N],idx;
int stk[N],instk[N],top;
int scc[N],tot;
int b[N],w[N];

vector<int> e[N];

void add(int u,int v,int c){
    ne[++cnt]=head[u];
    to[cnt]=v;
    color[cnt]=c;
    head[u]=cnt;
}

void tarjan(int u,int ine){
    dfn[u]=low[u]=++idx;
    instk[u]=1,stk[++top]=u;
    for(int i=head[u];i;i=ne[i]){
        if(i^ine^1){
            int v=to[i];
            if(!dfn[v]){
                tarjan(v,i);
                low[u]=min(low[u],low[v]);
            }else{
                low[u]=min(low[u],dfn[v]);
            }
        }
    }
    if(low[u]==dfn[u]){
        int v;
        tot++;
        do{
            v=stk[top--],instk[v]=0;
            scc[v]=tot;
            e[tot].push_back(v);
        }while(v^u);
    }
}


void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        add(u,v,c),add(v,u,c);
    }
    int number=0;
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            if(number){
                cout<<"0\n";
                return ;
            }
            tarjan(i,0);
            number++;
        }
    }
    vector<pll> res;
    for(int i=1;i<=tot;i++){
        for(int u:e[i]){
            for(int cur=head[u];cur;cur=ne[cur]){
                if(scc[to[cur]]!=scc[u]) continue;
                else{
                    if(color[cur]) b[i]++;
                    else w[i]++;
                }
            }
        }
        w[i]/=2,b[i]/=2;
        pll tmp={0,0};
        for(int num=1;num<=w[i];num++){
            if(num>e[i].size()-1) break;
            if(e[i].size()-1-num>b[i]) continue;
            else{
                tmp.second=num;
                if(tmp.first==0) tmp.first=num;
            }
        }
        res.push_back(tmp);
    }
    // cout<<tot<<'\n';
    pll ans={0,0};
    for(int i=0;i<res.size();i++) ans.first+=res[i].first,ans.second+=res[i].second;
    cout<<ans.second-ans.first+1<<'\n';
    for(int i=1;i<=tot;i++){
        e[i].clear();
        b[i]=w[i]=0;
    }
    for(int u=1;u<=n;u++){
        head[u]=0;
        scc[u]=0;tot=idx=cnt=0;
        dfn[u]=low[u]=0;
    }
    for(int i=1;i<=2*m;i++){
        to[i]=ne[i]=color[i]=0;
    }
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