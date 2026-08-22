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
    ll w,b;
    cin>>w>>b;
    
    for(int j=0;j<=b;j++) f[0][j]=0;
    for(int i=1;i<=w;i++) f[i][0]=1;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=b;j++){
            f[i][j]+=i/((double)(i+j));
            if(j>=3) f[i][j]+=j/(double)(i+j)*(j-1)/(double)(i+j-1)*(j-2)/(double)(i+j-2)*f[i][j-3];
            if(j>=2&&i>=1) f[i][j]+=j/(double)(i+j)*(j-1)/(double)(i+j-1)*(i)/(double)(i+j-2)*f[i-1][j-2];
        }
    }
    cout<<fixed<<setprecision(9)<<f[w][b];
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