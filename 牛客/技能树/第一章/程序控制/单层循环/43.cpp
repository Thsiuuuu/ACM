#include <bits/stdc++.h>
using namespace std;
/*



*/
int  dp[48];
void sol() {
    dp[1]=dp[2]=1;
    int n;
    cin>>n;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}