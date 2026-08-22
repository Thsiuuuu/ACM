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
vector<int> e[N],rt;
vector<pii> Q[N];
int siz[N],son[N];
ll ans[N];
string s[N];
map<string,int> mp[N];
void add(int u,int fa,int val,int ban,int depth){
    if(val==1){
        mp[depth][s[u]]++;
    }else{
        if(--mp[depth][s[u]]==0){
            mp[depth].erase(s[u]);
        }
    }
    for(int v:e[u]){
        if(v==fa||v==ban) continue;
        add(v,u,val,ban,depth+1);
    }
}

void dfs1(int u,int fa){
    siz[u]=1,son[u]=0;
    for(int v:e[u]){
        if(fa^v){
            dfs1(v,u);
            siz[u]+=siz[v];
            if(siz[v]>siz[son[u]]) son[u]=v;
        }
    }
}

void dfs2(int u,int fa,bool keep,int depth){
    for(int v:e[u]){
        if(v==fa||v==son[u]) continue;
        dfs2(v,u,false,depth+1);
    }
    if(son[u]){
        dfs2(son[u],u,true,depth+1);
    }
    add(u,fa,1,son[u],depth);
    for(auto &[id,k]:Q[u]){
        if(depth+k>=(N-3)) ans[id]=0;
        else ans[id]=mp[depth+k].size(); 
    }
    if(!keep){
        add(u,fa,-1,0,depth);
    }
}

void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        int r;cin>>r;
        if(r){
            e[r].push_back(i);
        }else rt.push_back(i);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int v,k;
        cin>>v>>k;
        Q[v].push_back({i,k});
    }
    for(int i=0;i<rt.size();i++){
        dfs1(rt[i],0);
        dfs2(rt[i],0,0,1);
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<"\n";
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