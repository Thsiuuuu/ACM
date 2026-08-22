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
vector<int> e[N],a,siz;
ll ans=0;
int n;
bool ck(ll x){
    ll sq=sqrtl(x);
    return sq*sq==x;
}

void dfs1(int u,int fa){
    bool f=ck(a[u]);
    ll sum=0;
    siz[u]=1;
    for(int v:e[u]){
        if(v^fa){
            dfs1(v,u);
            ans+=(f*siz[v]*sum);
            sum+=siz[v];
        }
    }
    siz[u]+=sum;
    sum=0;
    for(int v:e[u]){
        if(v^fa){
            ans+=(f*(ll)siz[v]*sum*(n-sum-1-siz[v]));
            sum+=siz[v];
        }
    }
    ans+=f*(ll)(siz[u]-1)*(n-siz[u]);
}

void sol() {
    // int n;
    cin>>n;
    a.assign(n+1,0);
    siz.assign(n+1,0);
    ans=0;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    cout<<ans<<'\n';
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