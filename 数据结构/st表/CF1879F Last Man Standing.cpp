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
const int N=2e5+10;
struct node{
    pii mx,sx;
}st[19][N];
node Merge(const node&a,const node&b){
    array<pii,4> all={a.mx,a.sx,b.mx,b.sx};
    node res={{-1,-1},{-1,-1}};
    for(const auto &[val,id]:all){
        if(id==-1) continue;
        if(id==res.mx.second||id==res.sx.second) continue;
        if(val>res.mx.first){
            res.sx=res.mx;
            res.mx={val,id};
        }else if(val>res.sx.first){
            res.sx={val,id};
        }
    }
    return res;
}
node query(int l,int r){
    int k=__lg(r-l+1);
    return Merge(st[k][l],st[k][r-(1<<k)+1]);
}
void sol() {
    int n;cin>>n;
    VI h(n+1),a(n+1);
    int mxa=0;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mxa=max(mxa,a[i]);
    }
    for(int i=1;i<=mxa;i++) st[0][i]={{-1,-1},{-1,-1}};
    for(int i=1;i<=n;i++) st[0][a[i]]=Merge(st[0][a[i]],{{h[i],i},{-1,-1}});
    for(int k=1;(1<<k)<=mxa;k++){
        for(int  l=1;l+(1<<k)-1<=mxa;l++){
            st[k][l]=Merge(st[k-1][l],st[k-1][l+(1<<(k-1))]);
        }
    }
    VL ans(n+1,0);
    for(int x=1;x<=mxa;x++){
        pli fx,sx;fx=sx={-1,-1};
        auto cmax=[&](pli ck){
            int id=ck.second;
            if(id==-1) return ;
            if(id==fx.second||id==sx.second) return ;
            if(ck.first>fx.first){
                sx=fx,fx=ck;
            }else if(ck.first>sx.first){
                sx=ck;
            }
        };
        for(int c=1;(c-1)*x+1<=mxa;c++){
            int l=(c-1)*x+1,r=min(mxa,c*x);
            node cur=query(l,r);
            if(cur.mx.second!=-1) cmax({1ll*c*cur.mx.first,cur.mx.second});
            if(cur.sx.second!=-1) cmax({1ll*c*cur.sx.first,cur.sx.second});
        }
        if(fx.first==sx.first) continue;
        ll res=(sx.second==-1?fx.first:fx.first-sx.first);
        ans[fx.second]=max(ans[fx.second],res);
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<'\n';
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