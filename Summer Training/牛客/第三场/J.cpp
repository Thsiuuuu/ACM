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
// const  int N=5e5+1;
// int fa[N],siz[N];
void sol() {
    int n,q;cin>>n>>q;
    VI dep(n+1,0),fa(n+1);
    for(int i=2;i<=n;i++){
        int u;cin>>u;
        dep[i]=dep[u]+1;
    }
    vector<priority_queue<pii>> Q(n+1);
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        Q[u].push({dep[v],v});
    }
    for(int u=n;u>=2;u--){
        if(Q[u].empty()){
            fa[u]=1;
            continue;
        }
        int p=Q[u].top().second;
        while(!Q[u].empty()&&Q[u].top().second==p){
            Q[u].pop();
        }
        fa[u]=p;
        if(Q[p].size()<Q[u].size()){
            swap(Q[p],Q[u]);
        }
        while(!Q[u].empty()){
            Q[p].push(Q[u].top());
            Q[u].pop();
        }
    }
    ll ans=0;
    for(int i=2;i<=n;i++){
        dep[i]=dep[fa[i]]+1;
        ans+=dep[i];
    }

    cout<<ans<<'\n';
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