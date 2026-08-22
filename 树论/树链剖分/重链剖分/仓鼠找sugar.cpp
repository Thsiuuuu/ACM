#include <iostream>
#include <algorithm>

using namespace std;
#define int long long 


const int N=1e5+10;

int n,m,q,root,mod;
int arr[N];

int head[N],nxt[N<<1],to[N<<1],cntg=0;

int  fa[N],dep[N],siz[N],son[N];
int top[N],dfn[N],seg[N],cntd=0;

/*


    这个可以打上标记，a-b加1,c-d减1，最后看a-b范围和是不是满足题意的


*/

/*


    其实也可以不用树链剖分做
    只需要考虑lca的问题，做树有关的题应当经常考虑lca

    如果两个路径有重合，则一个路径的lca必在另外一个上面
    


*/




int sum[N<<2],addTag[N<<2];


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
    sum[i]=(sum[i<<1]+sum[i<<1|1]);
}

void lazy(int i,int v,int n){
    sum[i]=(sum[i]+v*n);
    addTag[i]=(addTag[i]+v);
}

void down(int i,int ln,int rn){
    if(addTag[i]!=0){
        lazy(i<<1,addTag[i],ln);
        lazy(i<<1|1,addTag[i],rn);
        addTag[i]=0;
    }
}

void build(int l,int r,int i){
    if(l==r){
        sum[i]=arr[seg[l]];
    }else{
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
}

void add(int jobl,int jobr,int jobv,int l,int r,int i){
    if(jobl<=l&&r<=jobr){
        lazy(i,jobv,r-l+1);
    }else{
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);
        if(jobl<=mid){
            add(jobl,jobr,jobv,l,mid,i<<1);
        }
        if(jobr>mid){
            add(jobl,jobr,jobv,mid+1,r,i<<1|1);
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

void pathAdd(int x,int y,int v){
    while(top[x]!=top[y]){
        if(dep[top[x]]<=dep[top[y]]){
            add(dfn[top[y]],dfn[y],v,1,n,1);
            y=fa[top[y]];
        }else{
            add(dfn[top[x]],dfn[x],v,1,n,1);
            x=fa[top[x]];
        }
    }
    add(min(dfn[x],dfn[y]),max(dfn[x],dfn[y]),v,1,n,1);
}

void subtreeAdd(int  x,int v){
    add(dfn[x],dfn[x]+siz[x]-1,v,1,n,1);
}

int pathSum(int x,int y){
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

int  subtreeSum(int x){
    return query(dfn[x],dfn[x]+siz[x]-1,1,n,1);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }

    dfs1(1,0);
    dfs2(1,1);
    build(1,n,1);

    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        pathAdd(a,b,1);
        int ini=pathSum(a,b);

        pathAdd(c,d,-1);
        int aft=pathSum(a,b);
        if(ini==aft) cout<<"N\n";
        else cout<<"Y\n";
        pathAdd(c,d,1);
        pathAdd(a,b,-1);
    }
    return 0;
}