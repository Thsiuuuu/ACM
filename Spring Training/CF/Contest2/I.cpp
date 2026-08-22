#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long


const ll mod=1000000007;
const int N=1e5+3;
ll fac[N],inv[N];
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}

struct node{
    int op;
    ll val;
};

void sol() {
    int n;
    cin>>n;
    vector<node> all(n+1);
    for(int i=1;i<=n;i++){
        cin>>all[i].op>>all[i].val;
        if(all[i].op==2) all[i].val=mod-all[i].val;
    } 
    vector<ll> a(n+1,1),b(n+1,0);
    for(int i=1;i<=n;i++){
        a[i]=a[i-1],b[i]=b[i-1];
        if(all[i].op==3){
            a[i]=(a[i]*all[i].val)%mod;
            b[i]=(b[i]*all[i].val)%mod;
        }else{
            b[i]=(b[i]+all[i].val)%mod;
        }
    }
    int q;
    cin>>q;
    while(q--){
        ll x;
        int l,r;
        cin>>x>>l>>r;
        ll inv=ksm(a[l-1],mod-2);
        ll s=(b[r]-b[l-1]*a[r]%mod*inv%mod+mod)%mod,base=(x*a[r]%mod*inv%mod);
        cout<<(s+base)%mod<<'\n';
    }
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