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
const int N=1e6+10;
ll cnt[N<<2],sum[N<<2];
void up(int u){
    cnt[u]=cnt[ls]+cnt[rs];
    sum[u]=sum[ls]+sum[rs];
}
void add(int ji,int u,int l,int r,ll k){
    if(l==r){
        cnt[u]+=k,sum[u]+=(ji*k);
        return ;
    }
    if(ji<=mid) add(ji,ls,l,mid,k);
    else add(ji,rs,mid+1,r,k);
    up(u);
}
void query(ll &ans,int u,int l,int r,ll k){
    if(l==r){
        ans+=min(k,cnt[u])*l;
        return ;
    }
    if(cnt[ls]<=k){
        ans+=sum[ls];
        if(cnt[ls]==k) return ;
        else query(ans,rs,mid+1,r,k-cnt[ls]);
    }else{
        query(ans,ls,l,mid,k);
    }
}
void sol() {
    int n,k,m;cin>>n>>k>>m;
    vector<vector<pii>> Q(n+2);
    for(int i=0;i<m;i++){
        int l,r,c,p;cin>>l>>r>>c>>p;
        Q[l].push_back({p,c});
        Q[r+1].push_back({p,-c});
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(const auto&[p,c]:Q[i]){
            add(p,1,1,(int)1e6,c);
        }
        query(ans,1,1,(int)1e6,k);
    }
    cout<<ans<<'\n';
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