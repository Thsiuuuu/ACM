#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
const ll mod=998244353;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
const int N=2e6+5;
ll fac[N],inv[N];
void init(){
    fac[0]=inv[0]=fac[1]=inv[1]=1;
    for(int i=2;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=2;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
void sol() {
    int n,m,c,a,b;cin>>n>>m>>c>>a>>b;
    if(m<n) cout<<"0\n";
    else{
        if((m-n)%c) cout<<"0\n";
        else{
            int w=(m-n)/c;
            ll p=a*ksm(b,mod-2)%mod;
            cout<<n*ksm(m,mod-2)%mod*fac[m]%mod*inv[w]%mod*inv[m-w]%mod*ksm(p,w)%mod*ksm((1-p+mod)%mod,m-w)%mod<<'\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}