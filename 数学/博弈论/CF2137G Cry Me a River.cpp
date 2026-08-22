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
void sol() {
    int n,m,q;cin>>n>>m>>q;
    VII e(n+1);
    VI du(n+1,0);
    vector<array<int,2>> f(n+1,array<int,2>{1,1});
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        e[v].push_back(u);
        du[u]++;
    }
    while(q--){
        int op,u;cin>>op>>u;
        queue<pii> Q;
        if(op==1){
            if(f[u][0])    Q.push({u,0});
            if(f[u][1])    Q.push({u,1});
            f[u][1]=f[u][0]=0;
        }else{
            cout<<(f[u][0]?"yes\n":"no\n");
        }
        while(Q.size()){
            auto [u,cr]=Q.front();
            Q.pop();
            for(int v:e[u]){
                if(f[v][cr^1]==0) continue;
                else if(cr==1){
                    if(--du[v]==0){
                        Q.push({v,0});
                        f[v][0]=0;
                    }
                }else{
                    f[v][1]=0;
                    Q.push({v,1});
                }
            }
        }
    }

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