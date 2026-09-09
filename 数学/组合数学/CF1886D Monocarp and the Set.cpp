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
const ll mod=998244353;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void sol() {
    int n,m;string s;
    cin>>n>>m>>s;
    s=" "+s;
    ll res=1;
    bool is=(s[1]!='?');
    for(int i=2;i<n;i++){
        res=(res*((s[i]=='?')?((i-1+mod)%mod):1))%mod;
    }
    cout<<res*is<<'\n';
    while(m--){
        int pos;char c;cin>>pos>>c;
        if(pos==1)  is=(c!='?');
        else{
            if(c=='?'&&s[pos]!='?') res=res*((pos-1+mod)%mod)%mod;
            if(c!='?'&&s[pos]=='?') res=res*ksm((pos-1+mod)%mod,mod-2)%mod;
        }
        s[pos]=c;
        cout<<res*is<<'\n';
    }
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