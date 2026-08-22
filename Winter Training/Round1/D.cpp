#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N=110,mod=9999973;
int dp[N][N][N];

/*

    首先观察到每一行每一列最多有2个棋子
    按行做dp
    当前行可以摆0-2个
    每种摆法需要依赖之前有多少列是有0个棋子，有多少列是有1个棋子
    枚举所有状态即可

    设计状态的时候，需要能够覆盖所有的情况


*/

int c(int x){
    return x*(x-1)/2;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;

    dp[1][m][0]=1,dp[1][m-1][1]=m,dp[1][m-2][2]=(m-1)*m/2;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=m&&k<=2*i&&k<=m-j;k++){
                dp[i][j][k]=(dp[i-1][j][k]+(j+1ll)*((k>=1)?dp[i-1][j+1][k-1]:0ll)%mod+(k+1ll)*((k+1<=m)?dp[i-1][j][k+1]:0ll)%mod+(c(j+2))*((k>=2)?dp[i-1][j+2][k-2]:0ll)%mod+(c(k+2))*((k+2<=m)?dp[i-1][j][k+2]:0ll)%mod+(j+1)*(k)*((j+1<=m)?dp[i-1][j+1][k]:0ll)%mod)%mod;
            }
        }
    }
    int sum=0;
    for(int j=0;j<=m;j++){
        for(int k=0;k<=m;k++){
            sum=(sum+dp[n][j][k])%mod;
        }
    }
    cout<<sum;
    return 0;
} 