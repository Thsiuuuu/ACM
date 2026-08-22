#include <bits/stdc++.h>
using namespace std;

const int  N=5010,M=10010;
int head[N],ne[M<<1],to[M<<1],cnt=1;
int dfn[N],low[N],idx;
int scc[N],deg[N],tot;
int instk[N],stk[N],top;

/*

    边双联通分量缩点之后必然没有环，都是链的形式
    那么缩点之后最外层节点和靠里一层节点路径一定是唯一的
    显然两两配对最优，还剩下一个就去成环
    答案就是度为一节点数量/2上取整

*/

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
                low[u]=min(low[v],low[u]);
            }else{
                low[u]=min(low[u],dfn[v]);
            }
        }
    }
    if(dfn[u]==low[u]){
        int v;
        tot++;
        do{
            v=stk[top--],instk[v]=0;
            scc[v]=tot;
        }while(v^u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
    }
    tarjan(1,0);
    for(int u=1;u<=n;u++){
        for(int i=head[u];i;i=ne[i]){
            int v=to[i];
            if(scc[v]^scc[u]){
                deg[scc[v]]++;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=tot;i++){
        if(deg[i]==1){
            ans++;
        }
    }
    cout<<(ans+1)/2;
    return 0;
}