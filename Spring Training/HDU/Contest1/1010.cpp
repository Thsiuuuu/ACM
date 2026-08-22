#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

const ll mod=998244353;
const int N=2e5+3;
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
    // if(n==0&&m==0) return 1;
    // else if(n<m||m<0||n<0) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=ksm(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

void sol() {
    int n,m;cin>>n>>m;
    vector<ll> a(n+1,0),b(n+2,0);
    vector<bool> vis(n+2,false);
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        b[x]=y;
        vis[x]=true;
        if(x==1&&y!=n) b[x]=-1;
    }
    if(b[1]==-1){cout<<"0\n";return ;}
    b[n+1]=0,b[1]=n;
    vis[n+1]=true;
    ll rem=0,ans=1;
    for(int i=2,j=1;i<=n+1;i++){
        if(!vis[i]) continue;
        else{
            ll db=b[j]-b[i]-1,dx=i-j-1;
            if(i==n+1&&rem+db!=dx) ans=0;
            else if(rem+db<dx||b[j]<b[i]) ans=0;
            if(b[j]>b[i]){
                ans=ans*fac[i-j]%mod*C(rem+db,dx)%mod;
            }else{ans=ans*fac[i-j]%mod*C(rem,i-j)%mod;}
            rem=rem+db-dx,j=i;
        }
    }
    cout<<ans<<'\n';
}

signed main() {
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