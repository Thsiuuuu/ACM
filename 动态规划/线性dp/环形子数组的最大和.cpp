#include <bits/stdc++.h>
using namespace std;
#define int long long 

/*

    https://leetcode.cn/problems/maximum-sum-circular-subarray/description/

    可以发现，答案一定来自下面两种情况
    1.连续的不连着首尾的子数组和
    2.连续的连着首尾的子数组和

    第一种情况直接跑最大子数组和就可以
    第二种情况正难则反，可以转化为求最小子数组和，并用sum减去它，但是最小子数组和有可能一整段都是
    那么这样会导致选的数字没有了，所以需要进行特判，如果整段数字都参与构成了最小子数组和的话，只保留最大子数组和即可

    这个题需要分析出来答案的两种可能性，然后进行dp
*/

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> nums(n),dp1(n),dp2(n);
    int sum=0;
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }

    dp1[0]=dp2[0]=nums[0];
    for(int i=1;i<n;i++){
        dp1[i]=max(dp1[i-1]+nums[i],nums[i]);
        dp2[i]=min(dp2[i-1]+nums[i],nums[i]);
    }
    int ans=INT64_MIN;
    if(*min_element(dp2.begin(),dp2.end())!=sum){
        ans=max(ans,sum-*min_element(dp2.begin(),dp2.end()));
    }
    ans=max(ans,*max_element(dp1.begin(),dp1.end()));
    cout<<ans;

    return 0;
}