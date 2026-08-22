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
const int N=1e6+10;
const ll mod=1000000007;
ll f[N][2];

void sol() {
    int n,k;cin>>n>>k;
    f[0][0]=f[0][1]=f[1][1]=1;
    for(int i=2;i<=n;i++){
        f[i][0]=(f[i-1][0]+f[i-1][1])%mod;
        f[i][1]=(f[i-1][0]+f[i-1][1])%mod;
        if(i>=k) f[i][1]=(f[i][1]-f[i-k][0]+mod)%mod;
    }
    cout<<f[n][1]<<'\n';
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