#include <bits/stdc++.h>
using namespace std;
/*

    钦定类问题
    恰好转化为至少

*/
#define int long long 
int n,k;
int fac[1000001],inv[1000001];
int ksm(int a,int b,int mod=1e9+7){
    int res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
const int mod=1e9+7;
int C(int n,int m){
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}


void sol() {
    cin>>n>>k;
    int ans=0;
    
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    inv[n]=ksm(fac[n],mod-2);
    for(int i=n-1;i>=0;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    for(int i=k;i<=n;i++){
        int z=(i-k)&1?-1:1;
        ans=(ans+mod+z*(C(i,k)*C(n,i)%mod)*(ksm(2,ksm(2,n-i,mod-1))-1)%mod)%mod;
    }
    cout<<ans;
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