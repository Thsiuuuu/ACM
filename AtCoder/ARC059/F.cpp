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

const ll mod=1e9+7;


void sol() {
    int n;
    string s;
    cin>>n>>s;
    vector<vector<ll>> f(n+1,vector<ll>(n+2,0));
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            f[i][j]=(f[i-1][max(j-1,0)]+f[i-1][j+1]*2%mod)%mod;
        }
    }
    cout<<f[n][s.size()];
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