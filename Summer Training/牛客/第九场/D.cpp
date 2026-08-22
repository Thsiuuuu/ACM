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
const ll INF=-1e9;
VI e[N];
int n,m;
map<int,int> cnt[N];
vector<pll> all[N];
int dep[N];
void dfs1(int u,int fa){
    dep[u]=dep[fa]+1;
    for(int v:e[u]){
        if(v^fa){
           dfs1(v,u); 
        }
    }
}
void dfs2(int u,int fa){
    for(int v:e[u]){
        if(v==fa) continue;
        dfs2(v,u);
    }
    int son=0;
    for(int v:e[u]){
        if(v==fa) continue;
        if(cnt[son].size()<cnt[v].size()) son=v;
    }
    if(son) swap(cnt[son],cnt[u]);
    vector<int> nt;
    for(auto&[shi,ren]:all[u]){
        auto it=cnt[u].find(shi);
        if(it==cnt[u].end()) cnt[u][shi]=ren;
        else if(it->second!=-1){
            it->second=-1;
            nt.push_back(it->first);
        }
    }
    for(int v:e[u]){
        if(v==fa||v==son) continue;
        for(auto&[shi,ren]:cnt[v]){
            auto it=cnt[u].find(shi);
            if(it==cnt[u].end()) cnt[u][shi]=ren;
            else if(it->second!=-1){
                it->second=-1;
                nt.push_back(it->first);
            }
        }
    }
    for(int x:nt) cnt[u].erase(x);
}
void sol() {
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    for(int i=1;i<=m;i++){
        int x,s;cin>>x>>s;
        all[x].push_back({s+dep[x]-1,i});
        //要维护<time,idx>去哪都艾萨你进去
    }
    dfs2(1,0);
    string ans(m+1,'0');
    for(const auto&[key,val]:cnt[1]){
        ans[val]='1';
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i];
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