#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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
istream& operator>>(istream& in, i128& x) {
    string s;
    in >> s;

    x = 0;
    bool neg = false;

    int start = 0;
    if (s[0] == '-') {
        neg = true;
        start = 1;
    }

    for (int i = start; i < (int)s.size(); i++) {
        x = x * 10 + (s[i] - '0');
    }

    if (neg) x = -x;

    return in;
}
const ll mod=1e9+7;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void sol() {
    ll n,m,c;cin>>n>>m>>c;
    vector<i128> p(m+1,0),sw,sa;ll W=0;sw=sa=p;
    for(int i=1;i<=m;i++){
        cin>>p[i];
        W+=p[i];
    }
    for(int i=m-1;i>=0;i--){
        sa[i]=sa[i+1]+p[i+1]*(i+1);
        sw[i]=sw[i+1]+p[i+1];
    }
    int t=-1;
    for(int i=m-1;i>=0;i--){
        if(sa[i]-i*sw[i]>(i128)c*W){
            t=i;
            break;
        }
    }
    if(t==-1){
        cout<<"0\n";
        return ;
    }
    ll b=sa[t]%mod,a=(W-sw[t]+mod)%mod ,inw=ksm(W%mod,mod-2),q=a*inw%mod,ci=0,ans=0;
    if(q==1) ci=n;
    else{
        ci=(1-ksm(q,n)+mod)%mod*ksm((1-q+mod)%mod,mod-2)%mod;
    }
    ans=((ans+ci*b%mod*inw%mod)%mod-c*ci%mod+mod)%mod;
    ans=(ans+t*ksm(q,n)%mod)%mod;
    for(int x=1;x<t;x++){
        ans=(ans-ksm((W-sw[x]+mod)%mod*inw%mod,n)+mod)%mod;
    }
    cout<<ans<<'\n';
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