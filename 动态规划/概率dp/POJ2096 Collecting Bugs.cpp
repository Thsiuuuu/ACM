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
const int N=1010;
double f[N][N];
void sol() {
    int n,s;
    freopen("collect.in", "r", stdin);
    freopen("collect.out", "w", stdout);
    scanf("%d%d",&n,&s);
    
    // while(cin>>n>>s){
         for(int i=n+1;i>=0;i--){
            for(int j=s+1;j>=0;j--){
                f[i][j]=0;
            }
        }
        f[n][s]=0;
        for(ll i=n;i>=0;i--){
            for(ll j=s;j>=0;j--){
                if(i==n&&s==j) continue;
                // f[i][j]=1.0*(n-i)/n*(s-j)/s*f[i+1][j+1]+1;
                // f[i][j]+=1.0*i/n*(s-j)/s*f[i][j+1];
                // f[i][j]+=1.0*(n-i)/n*j/s*f[i+1][j];
                // f[i][j]=f[i][j]*n*s/(1.0*n*s-1.0*i*j);
                f[i][j]=1.0*(f[i][j+1]*i*(s-j)+f[i+1][j]*(n-i)*j+
                    f[i+1][j+1]*(n-i)*(s-j)+n*s)/(n*s-i*j);
            }
        }
        // printf("%.4lf\n",f[0][0]);
        printf("%.4lf",f[0][0]);
        // cout<<fixed<<setprecision(10)<<f[0][0];
    // }
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}