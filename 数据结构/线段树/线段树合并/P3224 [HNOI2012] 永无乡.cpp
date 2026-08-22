#include <bits/stdc++.h>
using namespace std;

const int T=4e6,N=1e5+10;
int p[N],siz[N],fa[N];
int root[N],sum[T],ls[T],rs[T],cnt;
int tran[N];
int n,m;

void up(int i){
    sum[i]=sum[ls[i]]+sum[rs[i]];
}

int build(int ji,int l,int r,int i){
    int rt=i;
    if(!rt) rt=++cnt;
    if(l==r) sum[rt]++;
    else{
        int mid=(l+r)>>1;
        if(ji<=mid) ls[rt]=build(ji,l,mid,ls[rt]);
        else rs[rt]=build(ji,mid+1,r,rs[rt]);
        up(rt);
    }
    return rt;
}

int merge(int l,int r,int t1,int t2){
    if(t1==0||t2==0) return t1+t2;
    if(l==r){
        sum[t1]+=sum[t2];
        return t1;
    }
    int mid=(l+r)>>1;
    ls[t1]=merge(l,mid,ls[t1],ls[t2]);
    rs[t1]=merge(mid+1,r,rs[t1],rs[t2]);
    up(t1);
    return t1;
}   

int query(int k,int l,int r,int i){
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(k<=sum[ls[i]]) return query(k,l,mid,ls[i]);
    else return query(k-sum[ls[i]],mid+1,r,rs[i]);
}

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    if(siz[fy]>siz[fx]) swap(fx,fy);
    siz[fx]+=siz[fy];
    fa[fy]=fx;
    merge(1,n,root[fx],root[fy]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        root[i]=build(p[i],1,n,root[i]);
        fa[i]=i,tran[p[i]]=i,siz[i]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        unite(u,v);
    }
    int q;
    cin>>q;
    while(q--){
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c=='Q'){
            int fx=find(x);
            if(y>sum[root[fx]]) cout<<"-1\n";
            else cout<<tran[query(y,1,n,root[fx])]<<'\n';
        }else{
            unite(x,y);
        }
    }
    return 0;
}