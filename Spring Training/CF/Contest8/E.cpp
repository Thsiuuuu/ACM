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

struct node{
    ll x,y;
    int cur;
    node(){}
    node(ll x,ll y,int cur):x(x),y(y),cur(cur){}
};

void sol() {
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vector<vector<int>> e(n+1);
    vector<ll> a(n+1),deg(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        if(v!=1){
            e[u].push_back(v);
            deg[v]++;
        }
    }
    for(int i=2;i<=n;i++){
        if(deg[i]==0){
            for(int v:e[i]){
                deg[v]--;
            }
        }
    }
    vector<node> p(n+1);
    for(int i=1;i<=n;i++){
        p[i].x=p[i].y=-1e18,p[i].cur=i;
    }
    queue<node> q;
    p[1].x=p[1].y=(ll)1e18;
    q.push(node((ll)1e18,(ll)1e18,1));
    while(q.size()){
        auto [x,y,u]=q.front();
        q.pop();
        for(int v:e[u]){
            if(y+a[u]>k-a[v]&&a[u]>p[v].y){
                p[v].x=y,p[v].y=a[u];
            }
            if(--deg[v]==0){
                q.push(p[v]);
            }
        }
    }
    if(p[n].x+p[n].y<=k-a[n]) cout<<"No\n";
    else cout<<"Yes\n";
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