#include <bits/stdc++.h>
using namespace std;

const int T=1e7+2,N=3e5+2,P=20;

vector<int> e[N];
int n,m;
int sum[T],dep[N],fa[N],ls[T],rs[T];
int w[N],cnt=0;
int rootup[N],rootdown[N];
int st[N][P],ans[N];

void up(int i){
    sum[i]=sum[ls[i]]+sum[rs[i]];
}

void dfs1(int u,int last){
    fa[u]=last;
    dep[u]=dep[last]+1;
    st[u][0]=last;
    for(int p=1;p<P;p++){
        st[u][p]=st[st[u][p-1]][p-1];
    }
    for(int v:e[u]){
        if(v^last){
            dfs1(v,u);
        }
    }
}

int LCA(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int i=P-1;i>=0;i--){
        if(dep[st[a][i]]>=dep[b]) a=st[a][i];
    }
    if(a==b) return a;
    for(int i=P-1;i>=0;i--){
        if(st[a][i]!=st[b][i]){
            a=st[a][i],b=st[b][i];
        }
    }
    return st[a][0];
}

int add(int ji,int jv,int l,int r,int i){
    int idx=i;
    if(!idx) idx=++cnt;
    if(l==r){
        sum[idx]+=jv;
        return idx;
    }
    int mid=(l+r)>>1;
    if(ji<=mid) ls[idx]=add(ji,jv,l,mid,ls[idx]);
    else rs[idx]=add(ji,jv,mid+1,r,rs[idx]);
    up(idx);
    return idx;
}

int merge(int l,int r,int t1,int t2){
    if(t1==0||t2==0) return t1+t2;
    if(l==r){
        sum[t1]+=sum[t2];
    }else{
        int mid=(l+r)>>1;
        ls[t1]=merge(l,mid,ls[t1],ls[t2]);
        rs[t1]=merge(mid+1,r,rs[t1],rs[t2]);
        up(t1);
    }
    return t1;
}

int query(int ji,int l,int r,int i){
    if(ji<l||ji>r||i==0) return 0;
    if(l==r){
        return sum[i];
    }
    int mid=(l+r)>>1;
    if(ji<=mid) return query(ji,l,mid,ls[i]);
    else return query(ji,mid+1,r,rs[i]);
}

void dfs2(int u,int last){
    for(int v:e[u]){
        if(v^last){
            dfs2(v,u);
            rootup[u]=merge(1,n,rootup[u],rootup[v]);
            rootdown[u]=merge(-n,n,rootdown[u],rootdown[v]);
        }
    }
    ans[u]=ans[u]+query(dep[u]+w[u],1,n,rootup[u])+query(dep[u]-w[u],-n,n,rootdown[u]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>w[i];
    dfs1(1,0);
    for(int i=1;i<=m;i++){
        int s,t;
        cin>>s>>t;
        int lca=LCA(s,t);
        rootup[s]=add(dep[s],1,1,n,rootup[s]);
        rootup[fa[lca]]=add(dep[s],-1,1,n,rootup[fa[lca]]);
        rootdown[t]=add(2*dep[lca]-dep[s],1,-n,n,rootdown[t]);
        rootdown[lca]=add(2*dep[lca]-dep[s],-1,-n,n,rootdown[lca]);
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}