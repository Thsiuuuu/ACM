#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
const int N=2e5+4;
int sum[N<<2][3],a[N];
void up(int u){
    for(int i=0;i<3;i++){
        sum[u][i]=sum[ls][i]+sum[rs][i];
    }
}
void build(int u,int l,int r){
    if(l==r){
        sum[u][a[l]]++;
    }else{
        build(ls,l,mid);
        build(rs,mid+1,r);
        up(u);
    }
}
void add(int u,int ji,int l,int r,int ori,int aft){
    if(l==r){
        a[ji]=aft;
        sum[u][ori]--;
        sum[u][aft]++;
    }else{
        if(ji<=mid) add(ls,ji,l,mid,ori,aft);
        else add(rs,ji,mid+1,r,ori,aft);
        up(u);
    }
}
void query(int u,int l,int r,int jl,int jr,int type,int&ans){
    if(jl<=l&&r<=jr){
        ans+=sum[u][type];
    }else{
        if(mid>=jl){
            query(ls,l,mid,jl,jr,type,ans);
        }
        if(jr>mid){
            query(rs,mid+1,r,jl,jr,type,ans);
        }
    }
}
void Q1(int u,int l,int r,int jl,int jr,int type,int&ans){
    if(l>jr||jl>r||sum[u][type]==0) return ;
    if(l==r){
        ans=min(ans,l);
        return ;
    }else{
        Q1(ls,l,mid,jl,jr,type,ans);
        if(ans>=mid){
            Q1(rs,mid+1,r,jl,jr,type,ans);
        }
    }
}
void Q2(int u,int l,int r,int jl,int jr,int type,int&ans){
    if(l>jr||jl>r||sum[u][type]==0) return ;
    if(l==r){
        ans=max(ans,l);
        return ;
    }else{
        Q2(rs,mid+1,r,jl,jr,type,ans);
        if(ans<=mid){
            Q2(ls,l,mid,jl,jr,type,ans);
        }
    }
}
void sol() {
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    // query(1,1,n,1,n,1,ans);
    // cout<<ans;
    int ans=-1;
    Q2(1,1,n,2,5,1,ans);
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}