#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

const int N=1e6+3;
vector<ll> e[N],a(N),num(N),mn(N),siz(N);

void dfs(int u,int fa){
    if(e[u].size()==1&&u!=1) return ;
    ll curmin=1e18;
    ll sum=0;
    for(int v:e[u]){
        if(v^fa){
            dfs(v,u);
            curmin=min(curmin,mn[v]);
            num[u]+=num[v],siz[u]+=siz[v];
        }
    }
    for(int v:e[u]) if(v^fa) sum+=(num[v]-curmin*siz[v]);
    if(curmin>a[u]){
        ll del=curmin-a[u];
        if(sum>=del){
            mn[u]=curmin;
        }else{
            mn[u]=num[u]/siz[u];
        } 
    }else  mn[u]=curmin;
}

void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        e[i].clear();
        siz[i]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];mn[i]=num[i]=a[i];
    }
    for(int i=1;i<=n-1;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++) cout<<mn[i]<<" ";
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