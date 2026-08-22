#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 

const ll mod=998244353;
const int N=2e5+2;

ll fac[N],inv[N];

ll ksm(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod,b>>=1;
    }
    return res;
}

void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=ksm(fac[N-1],mod-2,mod);
    for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

ll C(ll n,ll m){
    if(n<m||n<0||m<0) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}




void sol() {
    ll n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    ll c=0,ans=1;
    for(int i=n;i>=1;i--){
        // cout<<i<<" "<<c<<'\n';
        if((n&1)&&i==n/2+1) c++;
        if(i<=n/2) c+=2;

        if(i==1&&c!=a[i]){
            cout<<"0\n";    
            return ;
        }else if(a[i]>c){
            cout<<"0\n";
            return ;
        }else{
            ans=ans*C(c,a[i])%mod;
            c-=a[i];
        }
    }
    cout<<ans<<'\n';   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    init();

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}