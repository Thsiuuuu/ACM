#include <iostream>
#include <algorithm>

using namespace std;
#define int long long 

const int N=5e5+10;
int n,q;
int arr[N];

int head[N],nxt[N<<1],to[N<<1],cntg=0;

int fa[N],dep[N],siz[N],son[N];
int top[N],dfn[N],seg[N],cntd=0;

int sum[N<<2],updateTag[N<<2];

void addEdge(int u,int v){
    nxt[++cntg]=head[u];
    to[cntg]=v;
    head[u]=cntg;
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
    dfn[u]=++cntd;
    seg[cntd]=u;
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

void up(int i){
    sum[i]=sum[i<<1]+sum[i<<1|1];
}

void lazy(int i,int v,int n){
    sum[i]=v*n;
    updateTag[i]=v;
}

void down(int i,int ln,int rn){
    if(updateTag[i]!=-1){
        lazy(i<<1,updateTag[i],ln);
        lazy(i<<1|1,updateTag[i],rn);
        updateTag[i]=-1;
    }
}

void build(int l,int r,int i){
    if(l==r){
        sum[i]=arr[seg[l]];
        updateTag[i]=-1;
    }else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
}

void update(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        lazy(i,jobv,r-l+1);
    }else{
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);
        if(jobl<=mid){
            update(jobl,jobr,jobv,l,mid,i<<1);
        }
        if(jobr>mid){
            update(jobl,jobr,jobv,mid+1,r,i<<1|1);
        }
        up(i);
    }
}

int query(int jobl,int jobr,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        return sum[i];
    }
    int mid=(l+r)>>1;
    down(i,mid-l+1,r-mid);
    int ans=0;
    if(jobl<=mid){
        ans=(ans+query(jobl,jobr,l,mid,i<<1));
    }
    if(jobr>mid){
        ans=(ans+query(jobl,jobr,mid+1,r,i<<1|1));
    }
    return ans;
}

void pathUpdate(int x,int y,int v){
    while(top[x]!=top[y]){
        if(dep[top[x]]<=dep[top[y]]){
            update(dfn[top[y]],dfn[y],v,1,n,1);
            y=fa[top[y]];
        }else{
            update(dfn[top[x]],dfn[x],v,1,n,1);
            x=fa[top[x]];
        }
    }
    update(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),v,1,n,1);
}

void subtreeUpdate(int  x,int v){
    update(dfn[x],dfn[x]+siz[x]-1,v,1,n,1);
}

int queryUpdate(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<=dep[top[y]]){
            ans=(ans+query(dfn[top[y]],dfn[y],1,n,1));
            y=fa[top[y]];
        }else{
            ans=(ans+query(dfn[top[x]],dfn[x],1,n,1));
            x=fa[top[x]];
        }

    }
    ans=(ans+query(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),1,n,1));
    return ans; 
}

void sol(){
    

    fill(seg,seg+N,0);
    fill(top,top+N,0);
    fill(dfn,dfn+N,0);
    fill(sum,sum+4*N,0);
    fill(updateTag,updateTag+4*N,-1);
    fill(fa,fa+N,0);
    fill(dep,dep+N,0);
    fill(siz,siz+N,0);
    fill(son,son+N,0);
    fill(head,head+N,0);
    fill(nxt,nxt+(N<<1),0);
    fill(to,to+(N<<1),0);
    fill(arr,arr+N,0);
    cntg=0,cntd=0;
    
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }

    
    dfs1(1,0);
    dfs2(1,1);
    build(1,n,1);
    
    cin>>q;
    while(q--){
        int op,v;
        cin>>op>>v;
        if(op==1){
            subtreeUpdate(v,1);
        }else if(op==2){
            pathUpdate(1,v,0);
        }else{
            cout<<queryUpdate(v,v)<<"\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

    return 0;
}