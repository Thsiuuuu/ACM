#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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
const int N=2e5+10;
int a[N],n,q;
struct Seg{
    ll sum,cnt;
}seg[N<<3];
void up(int u){
    seg[u].sum=seg[ls].sum+seg[rs].sum;
    seg[u].cnt=seg[ls].cnt+seg[rs].cnt;
}
void insert(int u,int l,int r,int ji,ll num,int op){
    if(l==r){
        seg[u].sum+=op*num;
        seg[u].cnt+=op;
        return ;
    }
    if(ji<=mid) insert(ls,l,mid,ji,num,op);
    else insert(rs,mid+1,r,ji,num,op);
    up(u);
}
void dfs(int u,int l,int r,ll num,ll&ans){
    if(l==r){
        int k=1+(num)/(seg[u].sum/seg[u].cnt);
        ans+=k;
        return ;
    }
    if(seg[ls].sum<=num){
        ans+=seg[ls].cnt;
        dfs(rs,mid+1,r,num-seg[ls].sum,ans);
    }else{
        dfs(ls,l,mid,num,ans);
    }
}
void sol() {
    cin>>n>>q;
    VI all;
    ll cur=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0) all.push_back(a[i]);
        else cur-=a[i];
    }
    vector<pii> Query;
    for(int i=0;i<q;i++){
        int x,v;cin>>x>>v;
        Query.push_back({x,v});
        if(v>0) all.push_back(v);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(int i=1;i<=n;i++){
        if(a[i]>0) insert(1,1,all.size(),lower_bound(all.begin(),all.end(),a[i])-all.begin()+1,a[i],1);
    }
    for(const auto&[x,v]:Query){
        auto it =lower_bound(all.begin(),all.end(),v);
        if(a[x]>0){
            auto i1=lower_bound(all.begin(),all.end(),a[x]);
            insert(1,1,all.size(),i1-all.begin()+1,a[x],-1);
        }else{
            cur+=a[x];
        }
        if(v>0) insert(1,1,all.size(),it-all.begin()+1,v,1);
        else cur-=v;
        a[x]=v;
        if(seg[1].sum<=cur){
            cout<<seg[1].cnt+1<<'\n';
        }
        if(seg[1].sum>cur){
            ll ans=0;
            dfs(1,1,all.size(),cur,ans);
            cout<<ans<<'\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}