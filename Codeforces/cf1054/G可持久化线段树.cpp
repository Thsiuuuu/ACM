#include <bits/stdc++.h>
using namespace std;
/*

    可持久化线段树
    首先开一颗值域线段树，然后维护每一个版本下的数值情况
    查询某一个区间[l,r]可以转化为两个版本线段树作差，即[1,r]-[1,l-1]
    查某一个数值频率只需要作差然后线段树上二分即可

*/
const int N=2e5+10,K=200;
int n,q,lc[N*19],rc[N*19],sum[N*19],rt[N],A[N],a[N];
int nodecnt;

void modify(int &t,int pre,int l,int r,int x){
    t=++nodecnt;
    lc[t]=lc[pre],rc[t]=rc[pre],sum[t]=sum[pre]+1;
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(x<=mid) modify(lc[t],lc[pre],l,mid,x);
    else modify(rc[t],rc[pre],mid+1,r,x);
}

set<int> res;
void query(int u,int v,int l,int r,int x){
    if(l==r){res.insert(l);return ;}
    int mid=(l+r)>>1;
    if(sum[lc[v]]-sum[lc[u]]>=x) query(lc[u],lc[v],l,mid,x);
    if(sum[rc[v]]-sum[rc[u]]>=x) query(rc[u],rc[v],mid+1,r,x);
}


void sol() {
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        A[i]=a[i];
    }
    sort(A+1,A+n+1);
    int cnt=unique(A+1,A+n+1)-(A+1);
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(A+1,A+cnt+1,a[i])-A;
    }
    for(int i=1;i<=n;i++) modify(rt[i],rt[i-1],1,cnt,a[i]);
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        int len=(r-l+1)/3+1;
        res.clear();
        query(rt[l-1],rt[r],1,cnt,len);
        if(!res.size()) cout<<"-1\n";
        for(int x:res) cout<<A[x]<<" ";
        cout<<'\n';
    }
    nodecnt=0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}