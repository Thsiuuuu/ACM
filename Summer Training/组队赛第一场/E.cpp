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
const int N=2e5+10;
VL a,f;
VI e[N];
void dfs(int u){
    ll mn=1e18;
    for(int v:e[u]){
        dfs(v);
        mn=min(mn,f[v]);
    }
    if(u!=1&&e[u].size()!=0){
        if(a[u]<mn) f[u]=(a[u]+mn)/2;
        else f[u]=mn;
    }else if(u!=1&&e[u].size()==0){
        f[u]=a[u];
    }
}
void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) e[i].clear();
    a.assign(n+1,0);
    f.assign(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        e[x].push_back(i);
    }
    dfs(1);
    ll mn=1e18;
    for(int v:e[1]) mn=min(mn,f[v]);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<f[i]<<'\n';
    // }
    // cout<<mn<<'\n';
    cout<<a[1]+mn<<'\n';
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