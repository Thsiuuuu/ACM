#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

    这个题列出式子就是
    sum-sum1+sum2
    sum,sum1,sum2分别表示所有奇数位置的和，[l,r]范围内奇数位置的和以及偶数位置的和，l和r奇偶性不同（奇偶性不同才可以使区间长度是偶数，从而交换奇偶位置）
    然后这个等价于求对奇数位置所有的数取相反数，偶数位置保持不变的最大子段和
    最大的限制是l和r奇偶性不同，所以说最小的长度一定是b[i]+b[i-1]，长度为2，如果可以向左延伸的话，就加上dp[i-2]
    即dp[i]=max(b[i]+b[i-1],b[i]+b[i-1]+dp[i-2])
    这么转移可以保证，每个以i为右端点的最优dp值长度一定是偶数的
*/

void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1),dp(n+1,0);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        if((i&1)){
            b[i]=-b[i];
            sum+=a[i];
        }
    }
    dp[1]=dp[0]=0;
    for(int i=2;i<=n;i++){
        dp[i]=max(b[i]+b[i-1],dp[i-2]+b[i]+b[i-1]);
    }
    int ans=sum;
    for(int i=2;i<=n;i++){
        ans=max(ans,sum+dp[i]);
    }
    cout<<ans<<'\n';
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