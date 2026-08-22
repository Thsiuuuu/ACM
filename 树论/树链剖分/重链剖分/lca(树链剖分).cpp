#include <algorithm>
#include <iostream>

using namespace std;

#define int long long  

const int N=500001;

int n,m,root;

int head[N],nxt[N<<1],to[N<<1],cnt=0;

int  fa[N],dep[N],siz[N],son[N],top[N];

void addEdge(int u,int v){
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}


void dfs1(int u,int f){
    fa[u]=f;
    dep[u]=dep[f]+1;
    siz[u]=1;
    for(int e=head[u],v;e>0;e=nxt[e]){
        v=to[e];
        if(v!=f){
            dfs1(v,u);
        }
    }
    for(int e=head[u],v;e>0;e=nxt[e]){
        v=to[e];
        if(v!=f){
            siz[u]+=siz[v];
            if(son[u]==0||siz[son[u]]<siz[v]){
                son[u]=v;
            }
        }
    }
}

void dfs2(int u,int t){
    top[u]=t;
    if(son[u]==0){
        return ;
    }
    dfs2(son[u],t);
    for(int e=head[u],v;e>0;e=nxt[e]){
        v=to[e];
        if(v!=fa[u]&&v!=son[u]){
            dfs2(v,v);
        }
    }
}

int lca(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]<=dep[top[b]]){
            b=fa[top[b]];
        }else{
            a=fa[top[a]];
        }
    }
    return dep[a]<=dep[b]?a:b;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m>>root;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }

    dfs1(root,0);
    dfs2(root,root);
    for(int i=1,a,b;i<=m;i++){
        cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
    return 0;
}