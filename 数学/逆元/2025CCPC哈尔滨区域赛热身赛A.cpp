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
const ull mod=(1ull<<61)-1;
ull ksm(ull a,ull b){
    ull res=1;
    while(b){
        if(b&1) res=(u128)res*a%mod;
        b>>=1,a=(u128)a*a%mod;
    }
    return res;
}
void sol() {
    string s;cin>>s;
    reverse(s.begin(),s.end());
    ull x=0,cr=1;
    for(int i=0;i<s.size();i++){
        x=(x+(i128)(s[i]-'0')*cr%mod)%mod;
        cr=((u128)cr*10%mod);
    }
    x=ksm(x,mod-2);
    ull n=1;
    for(int i=2;i<=(ll)(1e6);i++){
        n=((u128)n*i)%mod;
        if((u128)n*x%mod>=1&&(u128)n*x%mod<i){
            cout<<i<<" "<<(ll)((u128)n*x%mod);
            return ;
        }
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