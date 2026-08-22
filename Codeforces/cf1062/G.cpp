#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

    正着不好想从反面想
    原问题是修改一些数，在保证修改后是递增的情况下，代价最小
    是相当于求保留一些数，使得他们是递增的情况下，代价最大

*/


void sol(){
    int n;
    cin>>n;
    vector<int> a(n),c(n);
    vector<int> dp(n,0);
    int sum=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>c[i];
        sum+=c[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            dp[i]=max(dp[i],(a[i]>=a[j])?(dp[j]+c[i]):0ll);
        }
        dp[i]=max(dp[i],c[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<sum-ans<<'\n';
    
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}