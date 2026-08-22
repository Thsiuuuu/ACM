#include <bits/stdc++.h>

using namespace std;

#define int long long 
const int mod=1e9+7;
const int N=1e5;

int dp[N],arr[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,w;
    cin>>n>>w;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    
    for(int i=1;i<=w;i++){
        for(int j=0;j<n&&arr[j]<=i;j++){
            dp[i]=(dp[i]+dp[i-arr[j]]%mod)%mod;
        }
    }
    for(int i=1;i<=w;i++){
        cout<<i<<" "<<dp[i]<<'\n';
    }
    cout<<dp[w];
    return 0;

}