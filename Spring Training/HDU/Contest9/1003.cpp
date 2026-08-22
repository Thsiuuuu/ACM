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
const int N=1e6+3;
ll a[N],b[N],c[N],d[N];
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        b>>=1,a=a*a%mod;
    }
    return res;
}

void sol() {
    int n;
    cin>>n;
    if(n==1){
        cout<<"0\n";
        return ;
    }
    c[n]=d[n]=0;
    for(int x=n-1;x>=1;x--){
        if(2*x>=n){
            a[x]=ksm(2*x,mod-2);
            b[x]=1;
            c[x]=(a[x]+c[x+1])%mod;
            d[x]=(b[x]+d[x+1])%mod;
        }else{
            ll pw=ksm(2*x,mod-2);
            a[x]=(1-c[2*x+1]+mod)*pw%mod;
            b[x]=(1-d[2*x+1]*pw%mod+mod)%mod;
            c[x]=(a[x]+c[x+1])%mod;
            d[x]=(b[x]+d[x+1])%mod;
        }
    }
    ll inv=ksm((1-c[1]+mod)%mod,mod-2);
    ll S1=d[1]*inv%mod;
    ll E1=(S1*a[1]%mod+b[1])%mod;
    cout<<E1<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}