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

const int N=1e5+10;
vector<int> e[N];
void dfs(bool &ans,int u,int fa){
    if(e[u].size()==2){
        ans=false;
        return ;
    }
    if(ans==false) return ;
    for(int v:e[u]){
        if(v^fa){
            dfs(ans,v,u);
        }
    }
}
void sol() {
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bool ans=true;
    dfs(ans,1,0);
    cout<<(ans?"YES\n":"NO\n");
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