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
// const ll INF=1e18;
// void out(){
//     int B;
//     cin>>B;
//     ll x=INF;
//     ll sum=0;
//     while(x){
//         sum++;
//         x/=B;
//     }
//     cout<<sum<<'\n';
// }
ld f[201][101][101];
#define Wo(x,y,z) [i][j][k]+=f[x][y][z]
ll n,d;
int a[3];
void sol() {
    cin>>n>>d;
    while(d&&d%2==0) a[0]++,d/=2;
    while(d&&d%3==0) a[1]++,d/=3;
    while(d&&d%5==0) a[2]++,d/=5;
    if(d>1){
        cout<<"0\n";
        return ;
    }
    f[0][0][0]=1;
    for(int tt=1;tt<=n;tt++){
        for(int i=200;~i;i--){
            for(int j=100;~j;j--){
                for(int k=100;~k;k--){
                    if(k>=1) f Wo(i,j,k-1);
                    if(i>=1) f Wo(i-1,j,k);
                    if(i>=2) f Wo(i-2,j,k);
                    if(j>=1) f Wo(i,j-1,k);
                    if(i>=1&&j>=1) f Wo(i-1,j-1,k);
                    f[i][j][k]/=6;
                }
            }
        }
    }
    ld ans=0;
    for(int i=200;i>=a[0];i--) for(int j=100;j>=a[1];j--) for(int k=100;k>=a[2];k--) ans+=f[i][j][k];
    cout<<fixed<<setprecision(7);
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    // out();
    while (t--) {
        sol();
    }
    return 0;
}