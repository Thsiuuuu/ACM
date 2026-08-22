#include <bits/stdc++.h>
using namespace std;
const int M=2e6+10,N=5e5+10;

int head[N],to[M<<1],ne[M<<1],cnt=1;
int dfn[N],low[N],idx;
int stk[N],instk[N],top;
int scc[N],tot;

vector<int> e[N];

void add(int u,int v){
    ne[++cnt]=head[u];
    to[cnt]=v;
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i,0);
        }
    }
    cout<<tot<<'\n';
    for(int i=1;i<=tot;i++){
        cout<<e[i].size()<<" ";
        for(int u:e[i]){
            cout<<u<<" ";
        }
        cout<<'\n';
    }
    return 0;
}