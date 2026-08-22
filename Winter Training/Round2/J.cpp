#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+7232,mod=1e9+7;
long long n,a[N];
long long inv[N],deinv[N],ans;

/*

    类似于推格子
    最开始没注意到题干a_i是递减的
    
    每个格子总依赖于左侧和上侧
    即dp[i][j]=dp[i-1][j]+dp[i][j-1]
    
    并且每个格子的数量实际上就是组合数
    然后就是如何求出每一列每一行的组合数的和了

    这个是朱世杰恒等式的变形
    但是也可以手推
    要对第二维进行化简，组合数想到组合数的递推公式，可以把第二维的求和化成一个最终的组合数
    利用首项是1，可以化成Cn0的值

*/
long long po(long long x,long long y)
{
    long long sum=1;
    while(y) 
    {
        if(y&1) sum=sum*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return sum;
}
long long C(long long n,long long m)
{
    if(m<0) return 0;//记得特判，不然会RE
    return inv[n]*deinv[m]%mod*deinv[n-m]%mod;
}
int main()
{
	scanf("%lld",&n);++n;
    for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
    inv[0]=1;deinv[0]=1;
    for(long long i=1;i<=N-10;i++)//预处理逆元
    {
        inv[i]=inv[i-1]*i%mod;
        deinv[i]=po(inv[i],mod-2);
    }
    for(long long i=1;i<=n;i++) ans=(ans+C(a[i]+i-1,a[i]-1))%mod;//公式
    printf("%lld\n",ans);
}

