#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
int dp[1010][1010];
const int mod=998244353;
void sol() {
    int n,m;
    cin>>n>>m;
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1){
                continue;
            }
            if(i>1){
                dp[i][j]=(dp[i-1][j]+dp[i][j])%mod;
            }
            if(j>1){
                dp[i][j]=(dp[i][j-1]+dp[i][j])%mod;
            }
        }
    }
    cout<<dp[n][m];
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