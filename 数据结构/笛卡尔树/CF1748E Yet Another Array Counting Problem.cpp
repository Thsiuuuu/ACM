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
const ll mod=1e9+7;
void sol() {
    int n,m;cin>>n>>m;
    VL a(n+1);
    VI ls(n+1,0),rs(n+1,0);
    VLL f(n+1,VL(m+1,0));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<int> stk;
    int rt;
    for(int i=1;i<=n;i++){
        int last=0;
        while(stk.size()&&a[stk.top()]<a[i]){
            last=stk.top();
            stk.pop();
        }
        if(stk.size()) rs[stk.top()]=i;
        if(last) ls[i]=last;
        stk.push(i);
    }
    while(stk.size()){
        rt=stk.top();
        stk.pop();
    }
    auto dfs=[&](auto &&self,int u)->void{
        for(int i=1;i<=m;i++) f[u][i]=1;
        if(ls[u]) self(self,ls[u]);
        if(rs[u]) self(self,rs[u]);
        if(ls[u]){
            for(int i=1;i<=m;i++) f[u][i]=(f[u][i]*f[ls[u]][i-1]%mod);
        }
        if(rs[u]){
            for(int i=1;i<=m;i++) f[u][i]=(f[u][i]*f[rs[u]][i]%mod);
        }
        for(int i=1;i<=m;i++) f[u][i]=(f[u][i]+f[u][i-1])%mod;
    };
    dfs(dfs,rt);
    cout<<f[rt][m]<<'\n';
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