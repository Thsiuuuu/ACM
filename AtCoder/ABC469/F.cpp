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
const int N=2e5+10,M=1e6+10;
int fa[N],siz[N],id[M];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x),y=find(y);
    if(siz[x]<siz[y]) swap(x,y);
    siz[x]+=siz[y];
    fa[y]=x;
}
void sol() {
    int n;cin>>n;
    int up=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        up=max(up,x);
        id[x]=i;
    }
    for(int i=1;i<=n;i++){
        siz[i]=1,fa[i]=i;
    }
    int cnt=n;
    ll ans=0;
    for(int x=up/2;x>=1&&cnt>1;x--){
        ll fir=-1;
        for(ll y=x;y<=up;y+=x){
            if(id[y]){
                // cout<<fir<<'\n';
                if(fir==-1) fir=id[y];
                else{
                    if(find(fir)^find(id[y])){
                        unite(fir,id[y]);
                        ans+=x;
                        cnt--;
                    }
                }
            }
        }
    }
    cout<<ans;
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