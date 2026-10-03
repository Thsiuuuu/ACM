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
const int N=1e6+10;
ll f[N],a,b,m;
ll ceil(ll up,ll down){
    return (up+down-1)/(down);
}
void sol() {
    cin>>a>>b>>m;
    for(int i=1;i<=m;i++) f[i]=0;
    ll ans=0;
    f[0]=2;
    for(int i=0;i<=m;i++){
        ans=max(ans,f[i]+(m-i)/a);
        if(i+b<=m) f[i+b]=max(f[i+b],f[i]+b/a+1);
        if(i+ceil(b,a)*a<=m) f[i+ceil(b,a)*a]=max(f[i+ceil(b,a)*a],f[i]+(1+ceil(b,a)));
    }
    cout<<ans*160<<'\n';
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