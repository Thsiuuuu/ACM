#include <iostream>
#include <algorithm>

using namespace std;

const int N=30001;
const int INF=10000001;


int n,m;
int arr[N];

int head[N],nxt[N<<1],to[N<<1],cntg=0;

int fa[N],dep[N],siz[N],son[N];

int top[N],dfn[N],seg[N],cntd=0;

int maxv[N<<2],sumv[N<<2];

void addEdge(int u,int v){
    nxt[++cntg]=head[u];
    to[cntg]=v;
    head[u]=cntg;
}

void dfs1(int u,int f){
    fa[u]=f;
    dep[u]=dep[f]+1;
    siz[u]=1;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=f){
            dfs1(v,u);
        }
    }
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=f){
            siz[u]+=siz[v];
            if(!son[u]||siz[son[u]]<siz[v]){
                son[u]=v;
            }
        }
    }
}


void dfs2(int u,int t){
    top[u]=t;
    dfn[u]=++cntd;
    seg[cntd]=u;
    if(!son[u]) return;
    dfs2(son[u],t);

    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=fa[u]&&v!=son[u]){
            dfs2(v,v);
        }
    }
}

void up(int i){
    sumv[i]=sumv[i<<1]+sumv[i<<1|1];
    maxv[i]=max(maxv[i<<1],maxv[i<<1|1]);
}

void build(int l,int r,int i){
    if(l==r){
        sumv[i]=maxv[i]=arr[seg[l]];
    }else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
        }
}

void update(int jobi,int jobv,int l,int r,int i){
    if(l==r){
        sumv[i]=maxv[i]=jobv;
    }else{
        int mid=(l+r)>>1;
        if(jobi<=mid){
            update(jobi,jobv,l,mid,i<<1);
        }else{
            update(jobi,jobv,mid+1,r,i<<1|1);
        }
        up(i);
    }
}

int queryMax(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return maxv[i];
    }
    int mid=(l+r)>>1,ans=-INF;
    if(jobl<=mid){
        ans=max(ans,queryMax(jobl,jobr,l,mid,i<<1));
    }
    if(jobr>mid){
        ans=max(ans,queryMax(jobl,jobr,mid+1,r,i<<1|1));
    }
    return ans;
}

int querySum(int jobl,int  jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return sumv[i];
    }
    int mid=(l+r)>>1,ans=0;
    if(jobl<=mid){
        ans+=querySum(jobl,jobr,l,mid,i<<1);
    }
    if(jobr>mid){
        ans+=querySum(jobl,jobr,mid+1,r,i<<1|1);
    }
    return ans;
}

void pointUpdate(int u,int v){
    update(dfn[u],v,1,n,1);
}

int pathMax(int x,int y){
    int ans=-INF;
    while(top[x]!=top[y]){
        if(dep[top[x]]<=dep[top[y]]){
            ans=max(ans,queryMax(dfn[top[y]],dfn[y],1,n,1));
            y=fa[top[y]];
        }else{
            ans=max(ans,queryMax(dfn[top[x]],dfn[x],1,n,1));
            x=fa[top[x]];
        }
    }
    return max(ans,queryMax(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),1,n,1));
}

int pathSum(int x,int y){
    int  ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<=dep[top[y]]){
            ans+=querySum(dfn[top[y]],dfn[y],1,n,1);
            y=fa[top[y]];
        }else{
            ans+=querySum(dfn[top[x]],dfn[x],1,n,1);
            x=fa[top[x]];
        }
    }
    return ans+querySum(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),1,n,1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,n,1);
    cin>>m;
    string op;
    int x,y;
    while(m--){
        cin>>op>>x>>y;
        if(op=="CHANGE"){
            pointUpdate(x,y);
        }else if(op=="QMAX"){
            cout<<pathMax(x,y)<<"\n";
        }else{
            cout<<pathSum(x,y)<<"\n";
        }
    }
    return 0;
}