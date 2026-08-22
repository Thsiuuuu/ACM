#include <bits/stdc++.h>
using namespace std;
/*



*/

#define ll long long 
const ll mod=1e9+7;
const int N=410;

ll C[N][N];

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}

void sol() {
    ll n,m,c;
    cin>>n>>m>>c;
    ll a=min(n,m),b=max(n,m);
    ll bei=1;

    C[0][0]=1;
    for(int i=1;i<=400;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;;
        }
    }
    for(int i=b-a+1;i<=b;i++){
        bei=bei*i%mod;
    }
    bei=bei*ksm(a,b-a)%mod;
    ll ans=0;
    for(int i=0;i<=c;i++){
        ll mul=ksm(c-i,b)*(c-i+1,n*m-b)%mod*C[c][i]%mod;
        if(i&1){
            mul=mod-mul;
        }
        ans=(ans+mul)%mod;
    }
    cout<<bei*(ans-1+mod)%mod;
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