#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
/*

    https://codeforces.com/contest/1084/problem/C
    从结尾考虑
    这个要分段，因为连续的a，最多只能选一个，共有len+1，表示都不选和a选一个
    状态转移方程为fi=(len+1)fi-1
    最后需要-1，去掉所有都不选

*/
struct node{
    int len;
    int num;
};

void sol(){

    string s;
    cin>>s;
    vector<node> dp;
    dp.push_back({0,1});
    for(int i=0;i<s.size();i++){
        int j=i;
        int len=0;
        while(j<s.size()&&s[j]!='b'){
            if(s[j]=='a') len++;
            j++;
        }
        if(j>i){
            dp.push_back({len,0});
        }
        i=j;
    }
    if(dp.size()>1) dp[1].num=(dp[1].len+1ll)%mod;
    for(int i=2;i<dp.size();i++){
        dp[i].num=(((dp[i].len+1ll)%mod)*dp[i-1].num)%mod;
    }
    cout<<dp[dp.size()-1].num-1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;

}