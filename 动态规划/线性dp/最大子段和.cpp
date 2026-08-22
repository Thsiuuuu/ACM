#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*

    https://www.luogu.com.cn/problem/P1115
    首先分析出答案一定是以某个点作为结尾的时候的值
    从后向前考虑，当前位置i的dp值要不然是自己，要不然是向左延伸加上左边这段的最大值
    而左边这段的最大值就是i-1位置上dp[i-1]能取到的最大值
    所以dp[i]=max(dp[i-1]+nums[i],nums[i]);

*/


/*


    找到所有最大子段和的位置
    
    如果前一个位置的dp值是<0的，那么一定不会选，所以之后的范围的l一定是从当前位置i开始的
    否则，当前的l不变，r延展到自己的位置上
    
    如果当前的dp值就等于最大值，那么把它的左右边界记录下来就可以


*/

void check(const vector<int> &dp,int mx,vector<pair<int,int>> &ans){
    int l=0,r=0;
    if(dp[0]==mx){
        ans.push_back({l,r});
    }
    for(int i=1;i<dp.size();i++){
        if(dp[i-1]<0){
            l=r=i;
        }else{
            r++;
        }
        if(dp[i]==mx){
            ans.push_back({l,r});
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<int> nums(n),dp(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        dp[i]=nums[i];
    }
    for(int i=0;i<n;i++){
        if(i>=1){
            dp[i]=max(dp[i],nums[i]+dp[i-1]);
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<'\n';

    vector<pair<int,int>> ans;
    check(dp,*max_element(dp.begin(),dp.end()),ans);
    for(auto [l,r]:ans){
        cout<<l<<" "<<r<<'\n';
    }
      
    return 0;
}