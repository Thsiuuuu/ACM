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
const ll mod=19930726;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
int n;ll k;
string s;
void Manacher(const string&s,VI& d1){
    int n=s.size();
    d1.assign(n,0);
    for(int i=0,l=0,r=-1;i<n;i++){
        int k=(i>r)?1:min(d1[l+r-i],r-i+1);
        while(i-k>=0&&i+k<n&&s[i-k]==s[i+k]) k++;
        d1[i]=k--;
        if(i+k>r) r=i+k,l=i-k;
    }
}
void sol() {
    cin>>n>>k>>s;
    VI d1;
    Manacher(s,d1);
    VL cnt(n+1,0);
    for(int i=0;i<n;i++){
        cnt[2*d1[i]-1]++;
    }
    for(int i=n-(!(n&1));i>=0;i-=2){
        if(i+2<=n) cnt[i]+=cnt[i+2];
    }
    ll ans=1;
    for(int i=n-(!(n&1));i>=0;i-=2){
        if(k>=cnt[i]) k-=cnt[i],ans*=ksm(i,cnt[i]),ans%=mod;
        else if(k) ans*=ksm(i,k),ans%=mod,k=0;
    }
    if(k) cout<<"-1";
    else cout<<ans;
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