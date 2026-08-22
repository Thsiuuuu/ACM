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
ll f[52][52][2502];
void sol() {
    ll n,a;
    cin>>n>>a;
    vector<ll> x(n+1);
    f[0][0][0]=1;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=50;j++){
            for(int k=0;k<=2500;k++){
                f[i][j][k]+=f[i-1][j][k];
            }
        }
        for(int j=1;j<=50;j++){
            for(int k=2500;k>=0&&k-x[i]>=0;k--){
                f[i][j][k]+=f[i-1][j-1][k-x[i]];
            }
        }
    }
    ll ans=0;
    // for(int j=0;j<=4;j++){
    //     for(int k=0;k<=15;k++){
    //         cout<<j<<" "<<k<<' ';
    //         cout<<f[2][j][k]<<"\n";
    //     }
    // }
    for(int i=1;i<=n;i++){
        ans+=f[n][i][i*a];
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