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

const int N=2e5+10;
vector<int> e[N],siz(N,1),deg(N,0);
vector<ll> f(N,0);
void sol() {
    int n;cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        e[v].push_back(u);
        deg[u]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!deg[i]) q.push(i);
    }
    ll ans=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        f[u]+=(siz[u]-1);
        ans+=f[u];
        for(auto v:e[u]){
            if(--deg[v]==0) q.push(v);
            siz[v]+=siz[u];
            f[v]+=f[u];
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