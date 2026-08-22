#include <iostream>
#include <algorithm>


#define int long long 

using namespace std;

//递推代替递归，避免超时

const int N=46;
int dp[N]={0};

void pro(int n){
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++) dp[i]=dp[i-2]+dp[i-1];
    cout<<dp[n];
}


signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;

    pro(n);

    return 0;

}