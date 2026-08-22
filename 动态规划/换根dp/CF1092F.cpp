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

const int N=2e5+4;
vector<int> e[N];


void sol() {
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    // ll Sum=0;
    vector<ll> siz(n+1,0),f(n+1,0);
    auto dfs1=[&](auto &&self,int u,int fa,int level)->void{
        f[1]+=level*a[u];
        siz[u]=a[u];
        for(int v:e[u]){
            if(v^fa){
                self(self,v,u,level+1);
                siz[u]+=siz[v];
            }
        }
    };
    auto dfs2=[&](auto &&self,int u,int fa)->void{
        for(int v:e[u]){
            if(v^fa){
                f[v]=f[u]+siz[1]-2*siz[v];
                self(self,v,u);
            }
        }
    };
    dfs1(dfs1,1,0,0);
    dfs2(dfs2,1,0);
    // cout<<Sum<<'\n';
    cout<<*max_element(f.begin()+1,f.end());
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