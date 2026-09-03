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
const ll mod=998244353;
void sol() {
    int n;cin>>n;
    VL a(n+1,0),f(n+1),g(n+1),L(n+1),suf(n+2,1e18),pre(n+1,0);
    stack<int> stk;
    f[0]=1;
    g[0]=0;
    stk.push(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        while(stk.size()&&a[stk.top()]>a[i]) stk.pop();
        L[i]=stk.top();
        stk.push(i);
    }
    for(int i=1;i<=n;i++){
        f[i]=(pre[i-1]-pre[L[i]]+mod)%mod;
        f[i]=(f[i]+g[L[i]])%mod;
        if(L[i]==0) f[i]=(f[i]+1)%mod;
        pre[i]=(pre[i-1]+f[i])%mod;
        g[i]=(g[L[i]]+f[i])%mod;
    }
    ll ans=0;
    for(int i=n;i>=1;i--){
        suf[i]=min(suf[i+1],a[i]);
        if(suf[i]==a[i]) {
            ans=(ans+f[i])%mod;
        }
    }
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