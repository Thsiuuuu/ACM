#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int mod=998244353;
void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1,-1),b(n+1,-1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    
    dp[1][0]=1,dp[1][1]=1;
    for(int i=1;i<=n;i++){
        if(a[i-1]<=a[i]&&b[i-1]<=b[i]){
            // cout<<i<<'\n';
            dp[i][0]=((dp[i][0]%mod)+(dp[i-1][0]%mod))%mod;
        }
        if(a[i-1]<=b[i]&&b[i-1]<=a[i]){
            // cout<<i<<'\n';
            dp[i][0]=((dp[i][0]%mod)+(dp[i-1][1]%mod))%mod;
        }
        if(a[i-1]<=b[i]&&b[i-1]<=a[i]){
            // cout<<i<<'\n';
            dp[i][1]=((dp[i][1]%mod)+(dp[i-1][0]%mod))%mod;
        }
        if(a[i-1]<=a[i]&&b[i-1]<=b[i]){
            // cout<<i<<'\n';
            dp[i][1]=((dp[i][1]%mod)+(dp[i-1][1]%mod))%mod;
        } 
    }
    cout<<(dp[n][0]+dp[n][1])%mod<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}