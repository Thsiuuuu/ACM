#include <bits/stdc++.h>  
using namespace std;
#define int long long 
const int  MN=INT64_MIN;
const int N=2e5+10;
int que[N];
/*


    单调队列优化dp

*/
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n+1),dp(n+2,MN);
    dp[0]=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    int head=0,tail=-1;
    for(int i=1;i<=n;i++){
        if(i-l>=0){
            cout<<dp[que[tail]]<<" ";
            while(head<=tail&&dp[que[tail]]<=dp[i-l]) tail--;
            que[++tail]=i-l;
            while(head<=tail&&que[head]<i-r) head++;
            dp[i]=dp[que[head]]+a[i];
        }
    }

    int ans=INT64_MIN;
    for(int i=n+1-r;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    
    cout<<ans;
    return 0;
}