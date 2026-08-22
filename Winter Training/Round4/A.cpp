#include <bits/stdc++.h>
using namespace std;
/*

    差了最后一点点
    首先n个选m个位置相同，Cnm
    然后剩下的都不相同，(n-1)种选法，如果被选的这个数和1进行互换的话，是f(n-2)
    如果不互换，相当于2位置不选2,3位置不选3... k位置不选1... n位置不选n
    等价于放n-1个位置让他们互不相同，是f(n-1)

*/
#define int long long 
const int mod=1e9+7;
const int N=1e6+3;
int fac[N],infac[N],dp[N];

int qmi(int a,int b){
    int res=1;
    a%=mod;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

void init(int n){
    fac[0]=infac[0]=1;
    dp[0]=1,dp[1]=0,dp[2]=1;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%mod;
        if(i>=3){
            dp[i]=(i-1)*((dp[i-1]+dp[i-2])%mod)%mod;
        }
        
    }
    infac[n]=qmi(fac[n],mod-2);
    for(int i=n-1;i>=1;i--){
        infac[i]=infac[i+1]*(i+1)%mod;
    }
}

int cal(int n,int m){
    if(m<0||m>n){
        return 0;
    }
    return fac[n]*infac[m]%mod*infac[n-m]%mod;
}

void sol() {
    int n,m;
    cin>>n>>m;
    if(m>n||m==n-1){
        cout<<"0\n";
    }else{
        cout<<((cal(n,m)*dp[n-m]))%mod<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init(N-1);
    int t = 1;
    cin >> t;
    // for(int i=1;i<=N;i++){
    //     cout<<i<<" "<<dp[i]<<'\n';
    // }
    while (t--) {
        sol();
    }
    return 0;
} 