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


const int N=5e6+10;
ll f[N];
void init(){
    // pw[0]=1;
    // for(int i=0;i<39;i++) pw[i]=pw[i-1]*3;
    f[0]=1;
    for(int i=1;i<N;i++){
        if(i%3==0) f[i]=f[i/3]+1;
        else f[i]=f[i-1]+1;
    }
}
void sol() {
    int a,b;cin>>a>>b;
    ll ans=0;
    for(int i=a;i<=b;i++) ans=max(ans,f[i]);
    for(int i=a;i<=b;i++){
        if(ans==f[i]){
            cout<<i<<' '<<ans<<'\n';
            break;
        }
    }
    cout<<ans<<'\n';
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