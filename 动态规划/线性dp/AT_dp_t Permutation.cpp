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
const int N=3003;
const ll mod=1e9+7;
ll f[N][N],p[N][N];
int n;string s;
void sol() {
    cin>>n>>s;
    s="  "+s;
    f[1][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=f[i-1][j]+p[i][j-1];
            p[i][j]%=mod;
        }
        for(int j=1;j<=i;j++){
            if(s[i]=='<') f[i][j]=p[i][j-1];
            else f[i][j]=(p[i][i-1]-p[i][j-1]+mod)%mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=(ans+f[n][i])%mod;
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