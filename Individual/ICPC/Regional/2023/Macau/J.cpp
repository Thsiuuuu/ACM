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
const int N=5e5+10;
int n,x;
VI e[N];
bool vis[N];
int a[N],dis[N];
void sol() {
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
        e[i].push_back((i+a[i])%n);
        e[i].push_back((i+1)%n);
    }
    priority_queue<pii,vector<pii> ,greater<pii>> Q;
    for(int i=0;i<n;i++) dis[i]=1e9;
    dis[a[0]]=1;
    Q.push({1,a[0]});
    while(Q.size()){
        auto [d,u]=Q.top();Q.pop();
        if(vis[u]) continue;;
        vis[u]=1;
        for(int v:e[u]){
            if(vis[v]) continue;
            if(dis[u]+1<dis[v]){
                dis[v]=dis[u]+1;
                Q.push({dis[v],v});
            }
        }
    }
    cout<<dis[x];
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