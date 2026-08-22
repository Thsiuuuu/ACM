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
void sol() {
    ll n,m,k,b;
    cin>>n>>m>>k>>b;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll S1=0,S2=0;
        for(int j=0;j<m;j++){
            ll x;
            cin>>x;
            S1+=x;
            if(x>0) S2+=(x-1);
            else S2+=(x+1);
        }
        if(S1>=k) ans++;
        else if(b&&S2>=k) ans++,b--;
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