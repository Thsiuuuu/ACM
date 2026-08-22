#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int lc,rc,val,rnk;
};

const int MAXN=1e5+10,MAXM=2e5+10;

SegmentTree t[MAXN*2+MAXM*40];
int rt[MAXM];
int n,m,tot;

int build(int l,int r){
    int p=++tot;
    if(l==r){
        t[p].val=l;
        t[p].rnk=1;
        return p;
    }
    int mid=(l+r)>>1;
    t[p].lc=build(l,mid);
    t[p].rc=build(mid+1,r);
    return p;
}

int getRnk(int p,int l,int r,int pos){
    if(l==r) return t[p].rnk;
    int mid=(l+r)>>1;
    if(pos<=mid) return getRnk(t[p].lc,l,mid,pos);
    else return getRnk(t[p].rc,mid+1,r,pos);
}

int modifyRnk(int now,int l,int r,int pos,int val){
    int p=++tot;
    t[p]=t[now];
    if(l==r){
        t[p].rnk=max(t[p].rnk,val);//按高度取排，因为相等就是需要取+1了，所以取最大值
        return p;
    }
    int mid=(l+r)>>1;
    if(pos<=mid) t[p].lc=modifyRnk(t[now].lc,l,mid,pos,val);
    else t[p].rc=modifyRnk(t[now].rc,mid+1,r,pos,val);
    return p;
}

int query(int p,int l,int r,int pos){
    if(l==r){
        return t[p].val;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        return query(t[p].lc,l,mid,pos);
    }else{
        return query(t[p].rc,mid+1,r,pos);
    }
}//查找父节点

int findRoot(int p,int pos){
    int f=query(p,1,n,pos);
    if(pos==f){
        return pos;
    }
    return findRoot(p,f);
}//查询根节点

int modify(int now,int l,int r,int pos,int fa){
    int p=++tot;
    t[p]=t[now];
    if(l==r){
        t[p].val=fa;
        return p;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        t[p].lc=modify(t[now].lc,l,mid,pos,fa);
    }else{
        t[p].rc=modify(t[now].rc,mid+1,r,pos,fa);
    }
    return p;
}//修改父节点

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    rt[0]=build(1,n);
    for(int i=1;i<=m;i++){
        int op,a,b;
        cin>>op;
        if(op==1){
            cin>>a>>b;
            int fa=findRoot(rt[i-1],a),fb=findRoot(rt[i-1],b);
            if(fa^fb){
                if(getRnk(rt[i-1],1,n,fa)>getRnk(rt[i-1],1,n,fb)) swap(fa,fb);
                int tmp=modify(rt[i-1],1,n,fa,fb);
                rt[i]=modifyRnk(tmp,1,n,fb,getRnk(rt[i-1],1,n,fa)+1);
            }else{
                rt[i]=rt[i-1];
            }
        }else if(op==2){
            cin>>a;
            rt[i]=rt[a];
        }else{
            cin>>a>>b;
            rt[i]=rt[i-1];
            cout<<(findRoot(rt[i],a)==findRoot(rt[i],b))<<'\n';
        }
    }
    return 0;
}