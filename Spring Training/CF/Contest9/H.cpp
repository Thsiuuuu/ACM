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

struct DSU{
    vector<int> fa,siz;
    DSU(int n):fa(n+1),siz(n+1,1){
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
    }
    int find(int x){
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }
    void unite(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx^fy){
            if(siz[fx]<siz[fy]) swap(fx,fy);
            siz[fx]+=siz[fy];
            fa[fy]=fx;
        }
    }
};

void sol() {
    int n;
    while(cin>>n){
        DSU dsu(n);
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            dsu.unite(i,a[i]);
        }
        vector<bool> vis(n+1,false);
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(vis[dsu.find(i)]==false){
                vis[dsu.find(i)]=true;
                ans+=(dsu.siz[dsu.find(i)]-1);
            }
        }
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