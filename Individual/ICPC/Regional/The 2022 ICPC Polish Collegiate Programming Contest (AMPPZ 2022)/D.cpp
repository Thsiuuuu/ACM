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

const int N=1e6+10;
vector<int> e[N],siz,cnt,num;
int all;
void dfs(int u,int fa){
    siz[u]=1;
    if(u!=1&&e[u].size()==1) num[u]=1,all++;
    for(int v:e[u]){
        if(v^fa){
            dfs(v,u);
            siz[u]+=siz[v];
            num[u]+=num[v];
        }
    }
    cnt[siz[u]]+=num[u];
}
void sol() {
    int n;cin>>n;
    siz.assign(n+1,0);
    cnt.assign(n+1,0);
    num.assign(n+1,0);
    all=1;
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    VI ans;
    dfs(1,0);
    // for(int i=1;i<=n;i++){
    //     cout<<num[i]<<' ';
    // }
    // cout<<all<<'\n';
    // cout<<'\n';
    for(int i=1;i<=n;i++){
        if(cnt[i]+1==all) ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
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