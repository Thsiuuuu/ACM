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
ll f[1010][1010];
ll INF=1e18;
int n,m,a[1010],b[1010];
void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=n;i>=1;i--){
        if((i+m)&1) f[i][m+1]=f[i+1][m+1]+a[i];
        else f[i][m+1]=f[i+1][m+1];
    }
    for(int i=m;i>=1;i--){
        if((i+n)&1) f[n+1][i]=f[n+1][i+1]+b[i];
        else f[n+1][i]=f[n+1][i+1];
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if((i+j)%2==0) f[i][j]=max(f[i][j+1]+b[j],f[i+1][j]+a[i]);
            else f[i][j]=min(f[i][j+1],f[i+1][j]);
        }
    }
    cout<<f[1][1]<<'\n';
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