#include <bits/stdc++.h>
using namespace std;
/*

    唐氏写法
    这个dp还是很典型的设i位置结尾有多少种替换方式
    那么很容易得出来f[i]=f[i]+f[j],j满足[j+1,i]内或和与代数和相等
    然后手玩样例发现或与代数和如果相等，就需要每次在添加的位置上不能有重复的1，所以j一定是一段连续的区间
    然后总和至多不超过32位，所以说如果当前位只要不加0，最多32次就可以完成所有操作
    可以记录最远非零相等位置，然后用前缀和维护区间的dp就可以

*/
#define ll long long 
const ll mod=998244353;
void sol() {
    int n;
    cin>>n;
    vector<ll> a(n+1,0),f(n+2,0),pre(n+1,0),s(n+2,0);
    int cur=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=cur;
        if(a[i]){
            cur=i;
        }
    }

    f[1]=1;
    s[1]=1;
    for(int i=1;i<=n;i++){
        int j=i;
        int val=0;
        while(j&&(val&a[j])==0){
            val|=a[j];
            j=pre[j];
        }
        f[i+1]=(s[i]-s[j]+mod)%mod;
        s[i+1]=(s[i]+f[i+1])%mod;
    }
    // f[1]=f[0]=1;
    // s[0]=1,s[1]=2;
    // for(int i=2;i<=n;i++){
    //     int last=i;
    //     ll sum=a[i],Or=a[i];
    //     while(last>=1&&sum==Or){
    //         last=pre[last];
    //         // f[i]=(f[i]+f[last])%mod;
    //         sum+=a[last],Or|=a[last];
    //     }
    //     f[i]=(f[i]+s[i-1]-(last?s[last-1]:0)+mod)%mod;
    //     s[i]=(s[i-1]+f[i])%mod;
    // }
    cout<<f[n+1]<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}