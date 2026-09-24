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
const int N=1e3+2;
int fa[1<<12][N],siz[1<<12][N];
int find(int x,int i){
    return x==fa[i][x]?x:fa[i][x]=find(fa[i][x],i);
}
void unite(int x,int y,int i){
    int fx=find(x,i),fy=find(y,i);
    if(fx==fy) return ;
    if(siz[i][fx]<siz[i][fy]) swap(fx,fy);
    siz[i][fx]+=siz[i][fy];
    fa[i][fy]=fx;
}
void add(int u,int v,int mask){
    if(find(u,mask)==find(v,mask)) return ;
    unite(u,v,mask);
    for(int i=0;i<12;i++){
        if((mask>>i)&1) add(u,v,mask^(1<<i));
    }
}
void sol() {
    int n,q;cin>>n>>q;
    for(int i=0;i<(1<<12);i++){
        for(int x=1;x<=n;x++){
            siz[i][x]=1,fa[i][x]=x;
        }
    }   
    ll ans=0;
    while(q--){
        char op;int u,v;cin>>op>>u>>v;
        if(op=='+'){
            int w;cin>>w;add(u,v,w);
        }else{
            if(find(u,0)!=find(v,0)){
                ans-=1;    
                continue;
            }
            int mask=0;
            for(int i=11;i>=0;i--){
                if(find(u,mask|(1<<i))==find(v,mask|(1<<i))) mask|=(1<<i);
            }
            ans+=mask;
        }   
    }
    cout<<ans<<'\n';
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