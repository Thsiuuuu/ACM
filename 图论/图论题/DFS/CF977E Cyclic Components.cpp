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
vector<int> e[N];
bool is[N];

void dfs(int u,bool &f){
    if(e[u].size()!=2) f=false;
    for(int v:e[u]){
        if(!is[v]){
            is[v]=1;
            dfs(v,f);
        }
    }
}

void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(is[i]) continue;
        bool f=true;
        dfs(i,f);
        ans+=f;
        // if(x==1){
        //     cout<<i<<" "; 
        // }
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