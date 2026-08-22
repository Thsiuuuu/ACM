#include <bits/stdc++.h>
using namespace std;
/*

    https://leetcode.cn/problems/house-robber/description/

    从n位置开始考虑
    类似树形dp的方式
    令dp[i][0]表示i位置不选，dp[i][1]表示i位置选
    那么有
    dp[i][0]=max(dp[i][0],dp[i][1]);
    dp[i][1]=max(nums[i],nums[i]+dp[i][0]);
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n; 
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>> dp(nums.size(),vector<int>(2,0));
    dp[0][1]=nums[0],dp[0][0]=0;
    for(int i=1;i<nums.size();i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=max(nums[i],nums[i]+dp[i-1][0]);
    }
    cout<<max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    
    return 0;
}