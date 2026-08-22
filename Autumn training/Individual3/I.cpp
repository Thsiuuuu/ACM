#include <bits/stdc++.h>
using namespace std;
#define int long long  
const int mod=998244353;
/*

    这道题题意没有理解，因为对于任意的都成立，所以说，对从1出发的线段而言
    如果右端点x在n+1及其右侧，那么x右侧的端点一定是要和x左侧的端点匹配，并且是等长的
    如果x在n及其左侧，就相当于可以分成多段，并且每一段都要是相等的才可以，所以说是2*n%2*k==0的数的数量
    这里求约数可以用筛法求约数，也可以从小到大依次枚举，这样是一个调和级数的东西，时间复杂度为O(n*logn)

*/

const int N=1000010;

int p[N],vis[N],cnt;
int a[N];//记录i的最小质因子的个数
int d[N];//记录i的约数个数

// void get(int n){
//     d[1]=1ll;
//     for(int i=2;i<=n;i++){
//         if(!vis[i]){
//             p[++cnt]=i;
//             a[i]=1ll;
//             d[i]=2ll;
//         }
//         for(int j=1;i*p[j]<=n;j++){
//             int m=i*p[j];
//             vis[m]=1ll;
//             if(i%p[j]==0ll){
//                 a[m]=a[i]+1ll;
//                 d[m]=d[i]/a[m]*(a[m]+1ll);
//                 break;
//             }else{
//                 a[m]=1ll;
//                 d[m]=d[i]*2ll;
//             }
//         }
//     }
// }

void get(int N){
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            d[j]++;
        }
    }
}

void sol(){
    int n;
    cin>>n;
    vector<int> dp(2*n+1,0ll),pre(2*n+1,0ll);
    dp[0]=dp[1]=pre[0]=1ll;
    pre[1]=2ll;
    // dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i]+pre[i-1])%mod;
        dp[i]=(dp[i]+d[i]-1ll+mod)%mod;
        pre[i]=(dp[i]+pre[i-1])%mod;
    }
    cout<<dp[n];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    get(N);
    sol();
    return 0;
}