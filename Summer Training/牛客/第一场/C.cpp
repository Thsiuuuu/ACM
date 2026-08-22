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
int n,m,q;
const int N=3e5;
int fa[N],siz[N],dir[5]={-1,0,1,0,-1};
ll to[N];
VII mp;
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx^fy){
        if(siz[fx]<siz[fy]){
            swap(fx,fy);
        }
        siz[fx]+=siz[fy];
        fa[fy]=fx;
        to[fx]=max(to[fx],to[fy]);
    }
}
int cal(int x,int y){
    return (x-1)*m+y;
}
int ck(int x,int y){
    return x&&y&&x<=n&&y<=m&&mp[x][y]!=-1;
}
void init(int x,int y,int v){
    int c=cal(x,y);
    siz[c]=1;
    fa[c]=c;
    to[c]=v;
    mp[x][y]=v;
}
void sol() {
    cin>>n>>m>>q;
    ll ans=0;
    mp.assign(n+1,VI(m+1,-1));
    // cout<<cal(2,2)<<'\n';
    while(q--){
        int op,x,y;cin>>op>>x>>y;
        ll tmp=0;
        if(op==1){
            ll v;cin>>v;
            init(x,y,v);     
            for(int i=0;i<4;i++){
                int dx=x+dir[i],dy=y+dir[i+1];
                if(ck(dx,dy)){
                    unite(cal(dx,dy),cal(x,y));
                }
            }
            tmp=siz[find(cal(x,y))]-1;
        }else{
            tmp=to[find(cal(x,y))]-mp[x][y];
        }
        ans^=tmp;
        cout<<ans<<'\n';
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