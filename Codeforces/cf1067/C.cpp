#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*


    一道动态规划好题，
    如果k是偶数，那么答案就是自己
    如果k是奇数，就是调整之后的最大区间和

*/
void sol(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n),pre(n),suf(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    pre[0]=a[0],suf[n-1]=a[n-1];
    for(int i=1;i<n;i++){
        pre[i]=max(pre[i-1],0ll)+a[i];
    }
    for(int i=n-2;i>=0;i--){
        suf[i]=max(suf[i+1],0ll)+a[i];
    }
    if(k&1){
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=((i-1>=0)?(max(pre[i-1],0ll)):0)+((i+1<n)?(max(suf[i+1],0ll)):0)+a[i]+b[i];
        }
        cout<<(*max_element(dp.begin(),dp.end()))<<'\n';
    }else{
        cout<<(*max_element(pre.begin(),pre.end()))<<'\n';
    }
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