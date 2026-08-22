#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
const int N=2010;
const ll mod=1e9+9;
ll C[N][N],fac[N];
ll dp[N][N];

void sol() {
    int n,k;
    cin>>n>>k;
    vector<ll> a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    if((n^k)&1){
        cout<<"0\n";
        return ;
    }
    int m=(n+k)>>1;
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    C[0][0]=fac[0]=dp[0][0]=1;
    for(int i=1;i<N;i++){
        C[i][0]=dp[i][0]=1,fac[i]=fac[i-1]*i%mod;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    ll sum=0;
    int p=1;
    for(int i=1;i<=n;i++){
        while(p<=n&&b[p]<a[i]){
            p++;
            sum++;
        }
        for(int j=1;j<=n;j++){
            dp[i][j]=(dp[i-1][j]+(dp[i-1][j-1]*(sum-j+1)%mod))%mod;
        }
    }
    ll ans=0;
    sum=0;
    for(int i=m;i<=n;i++){
        sum=C[i][m]*fac[n-i]%mod*dp[n][i]%mod;
        if((i-m)&1){
            ans=(ans-sum+mod)%mod;
        }else{
            ans=(ans+sum)%mod;
        }
    }
    cout<<ans;
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