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
const int INF=1e9;
int f[503][503][503];
void sol() {
    int n;
    string s;
    cin>>n>>s;
    s=' '+s;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) for(int k=0;k<=n;k++ )f[i][j][k]=INF;
    }
    f[0][0][0]=0;
    for(int i=1;i<=n;i++){
        if(s[i]!='T'){
            for(int j=0;j<=i;++j){
                for(int k=0;k<=j;k++) f[i][j+1][k+1]=max(f[i-1][j][k],k+1);
            }
        }
        if(s[i]!='F'){
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j;k++) f[i][j][max(k-1,0)]=min(f[i][j][max(k-1,0)],f[i-1][j][k]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            ans=max(ans,i-f[n][i][j]);
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}