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
const int N=1e3+10;
const ll mod=998244353;
ll f[N][N],F[N*100];
ll b[N];
int k,n;
ll ans=0;
void sol() {
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+1+n);
    ll Lim=(b[n]-b[1])/(k-1);
    f[0][0]=1;
    for(int x=1;x<=Lim;x++){
        int p=0;
        for(int i=1;i<=n;i++){
            f[i][0]=1;
            while(p+1<i&&b[p+1]<=b[i]-x){
                p++;
            } 
            for(int j=1;j<=k;j++){
                f[i][j]=f[p][j-1];
                f[i][j]=(f[i][j]+f[i-1][j])%mod;
            }
        }
        F[x]=f[n][k];
    }

    for(int x=1;x<=Lim;x++){
        ans=(ans+x*((F[x]-F[x+1]+mod)%mod%mod))%mod;
    }
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