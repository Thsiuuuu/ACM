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

const int N=403;
const ll mod=1e9+7;
ll g[N][N],f[N][N],A[N],B[N];
int n,c;
void sol() {
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++) cin>>B[i];
    for(int i=1;i<=n;i++){
        for(ll x=A[i];x<=B[i];x++){
            ll xi=1;
            for(int k=0;k<=c;k++,xi=xi*x%mod){
                g[i][k]=(g[i][k]+xi)%mod;
            }
        }
    }
    for(int j=0;j<=c;j++){
        f[1][j]=g[1][j];    
    }    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=c;j++){
            for(int k=0;k<=j;k++){
                f[i][j]=(f[i][j]+g[i][k]*f[i-1][j-k]%mod)%mod;
            }
        }
    }
    cout<<f[n][c];
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