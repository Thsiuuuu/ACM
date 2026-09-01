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
const int N=1e5+10;
int tr[N<<3],n;
struct node{
    int x,r;
    bool operator<(const node&other)const{
        if(x+r==other.x+other.r) return x-r<other.x-other.r;
        return x+r<other.x+other.r;
    }
};
void up(int u){
    tr[u]=max(tr[ls],tr[rs]);
}
void add(int ji,int jv,int u,int l,int r){
    if(l==r){
        tr[u]=max(tr[u],jv);
        return ;
    }
    if(ji<=mid) add(ji,jv,ls,l,mid);
    else add(ji,jv,rs,mid+1,r);
    up(u);
}
void query(int jl,int jr,int l,int r,int u,int &ans){
    if(jl<=l&&r<=jr){
        ans=max(ans,tr[u]);
        return ;
    }
    if(jl<=mid) query(jl,jr,l,mid,ls,ans);
    if(jr>mid) query(jl,jr,mid+1,r,rs,ans);
}
void sol() {
    cin>>n;
    VI o;
    vector<node> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].r;
        o.push_back(a[i].x-a[i].r);
        o.push_back(a[i].x+a[i].r);
    }
    sort(a.begin(),a.end());
    sort(o.begin(),o.end());    
    o.erase(unique(o.begin(),o.end()),o.end());
    int res=0;
    for(int i=0;i<n;i++){
        const auto&[x,r]=a[i];
        int L=x-r,R=x+r;
        L=lower_bound(o.begin(),o.end(),L)-o.begin()+1;
        R=lower_bound(o.begin(),o.end(),R)-o.begin()+1;
        int ans=0;
        query(L+1,R-1,1,2*n,1,ans);
        res=max(res,ans+1);
        add(L,ans+1,1,1,2*n);
    }
    cout<<res<<'\n';
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