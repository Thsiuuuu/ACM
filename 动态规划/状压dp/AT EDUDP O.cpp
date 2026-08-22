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
int n;
const ll mod=1e9+7;
ll f[22][(1<<22)];
bool is[21][21];
void sol() {
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>is[i][j];
        }
    }
    f[0][0]=1;
    for(int i=0;i<n;i++){
        for(int mask=0;mask<(1<<n);mask++){
            if(__builtin_popcount(mask)!=i+1) continue;
            for(int j=0;j<n;j++){
                if(!is[i][j]||!(mask&(1<<j))) continue;
                f[i+1][mask]+=f[i][mask^(1<<j)];
                f[i+1][mask]%=mod;
            }
        }
    }
    cout<<f[n][(1<<n)-1];
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