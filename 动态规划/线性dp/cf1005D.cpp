#include <bits/stdc++.h>
using namespace std;
#define int long long  
/*

    暴力解容易得出
    时间复杂度O(n^2)

    对第二层的枚举进行优化
    手玩样例发现，对于i位置而言，可以枚举的范围一定在[i-2,i]
    因为111 222 3xx 112总共这4种情况
    并且如果说不选这3位选择放长线钓大鱼
    那么如果是3的倍数的话，一定可以拆成2份
    如果不是3的倍数，那么贡献是0份


    此题dp一定是递增的

*/

void sol(){
    string s;
    cin>>s;
    s=' '+s;
    int n=s.size();
    vector<int> pre(n,0),dp(n,0);
    for(int i=1;i<n;i++){
        pre[i]=s[i]-'0'+pre[i-1];
    }
    // for(int i=1;i<n;i++) cout<<i<<" "<<pre[i]<<'\n';
    for(int i=1;i<n;i++){
        for(int j=max(i-3ll,0ll);j<i;j++){

            dp[i]=max(dp[i],dp[j]+(((pre[i]-pre[j])%3ll)?0ll:1ll));
        }
    }
    // for(int i=1;i<n;i++) cout<<i<<" "<<dp[i]<<'\n';
    // cout<<ans;
    cout<<dp[n-1];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    t=1;
    while(t--){
        sol();
    }
    return 0;
}