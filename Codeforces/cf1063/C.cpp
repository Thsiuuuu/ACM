#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pair<int,int> pii
const int MX=1145141919810;
const int MN=-MX;

/*


    一道好题
    观察到可以发生转移的只有n个路径，并且每个路径的最大值和最小值都是确定的
    问题是怎么找有多少个(l,r)
    两个变量可以先固定一个，考虑枚举l，那么就是要找一个区间[L_i,R_i]，使得L_i>=l下，R_i最小
    如果强行枚举，时间复杂度是O(n^2)的
    因为正序枚举下有些区间会逐渐不符合题意，需要舍弃，很难处理
    如果逆序枚举，就是不断加入新的区间的过程，可以不断的更新
    比如每一个路径的最近右端点一定是确定了的，设为[l,r]，那么对于l-1位置而言，自己本身的右端点可能是答案，同时l位置的右端点也有可能是答案，所以不断更新后缀即可。
    逆序枚举就是不断加入新的区间，然后更新最近右端点

    卡点：
    主要是没想到枚举l

*/
void sol(){
    int n;
    cin>>n;
    vector<vector<int>> a(2,vector<int>(n+1,MX));

    for(int i=1;i<=n;i++) cin>>a[0][i];
    for(int i=1;i<=n;i++) cin>>a[1][i];

    vector<vector<int>> premin(2,vector<int>(n+2,MX)),premax(2,vector<int>(n+2,MN));
    vector<vector<int>> sufmin(2,vector<int>(n+2,MX)),sufmax(2,vector<int>(n+2,MN));
    vector<int> dp(2*n+2,MX);
    
    for(int i=1;i<=n;i++){
        premin[0][i]=min(premin[0][i-1],a[0][i]);
        premax[0][i]=max(premax[0][i-1],a[0][i]);
        // premin[1][i]=min(premin[1][i-1],a[1][i]);
        // premax[1][i]=max(premax[1][i-1],a[1][i]);
    }
    for(int i=n;i>=1;i--){
        sufmin[1][i]=min(sufmin[1][i+1],a[1][i]);
        sufmax[1][i]=max(sufmax[1][i+1],a[1][i]);
    }

    for(int i=1;i<=n;i++){
        int l=min(premin[0][i],sufmin[1][i]);
        int r=max(premax[0][i],sufmax[1][i]);
        dp[l]=min(dp[l],r);
    }

    for(int i=2*n;i>=1;i--){
        dp[i]=min(dp[i],dp[i+1]);
    }
    int ans=0;
    for(int i=1;i<=2*n;i++){
        if(dp[i]^MX) ans+=(2*n-dp[i]+1);
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