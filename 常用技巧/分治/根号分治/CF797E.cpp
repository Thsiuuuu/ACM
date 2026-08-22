#include <bits/stdc++.h>
using namespace std;
/*

    k大于sqrt(n)时候暴力查询，反之采用小范围dp的方式，即小范围dp大范围暴力
    dp逆序更新每个点在不同k的时候的可以跳转的次数即可

*/
#define ll long  long  
const int N=1e5+10;
ll dp[N][320];
void sol() {
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int block=sqrt(n);
    for(int i=n-1;i>=0;i--){
        for(int k=1;k<=block;k++){
            if(i+k+a[i]>=n){
                dp[i][k]=1ll;
            }else{
                dp[i][k]=1+dp[(i+k+(int)a[i])][k];
            }
        }
    }
    // for(int i=0;i<=n-1;i++){
    //     for(int k=1;k<=block;k++){
    //         cout<<i<<" "<<k<<" "<<dp[i][k]<<'\n';
    //     }
    // }
    int q;
    cin>>q;
    while(q--){
        int p,k;
        cin>>p>>k;
        p-=1;
        if(k<=block){
            cout<<dp[p][k]<<'\n';
        }else{
            ll sum=0;
            for(int i=p;i<n;){
                sum++;
                i=i+a[i]+k;
            }
            cout<<sum<<'\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}