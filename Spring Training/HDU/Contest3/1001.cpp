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

const ll mod=998244353;
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

ll C(ll n,ll m){
    if(n==0&&m==0) return 1;
    else if(n<m||m<0||n<0) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}



void sol() {
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n+1,0),b(n+2,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n+1;i++) cin>>b[i];
    sort(a.begin()+1,a.end(),greater<ll>());
    sort(b.begin()+1,b.end(),greater<ll>());
    i128 sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i]*b[i];
    }
    if(sum>=m) cout<<"0\n";
    else{
        sum=0;
        ll ans=INT64_MAX;
        for(int i=1;i<=n;i++) sum+=a[i]*b[i+1];
        for(int i=1;i<=n+1;i++){
            ans=min(ans,(ll)ceil((ld)(m-sum)/b[i]));
            if(i+1<=n+1){
                sum-=a[i]*b[i+1];
                sum+=a[i]*b[i];
            }
        }
        cout<<ans<<'\n';
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