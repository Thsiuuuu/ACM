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

const ll Lim=1e3;
ll check(ll x){
    string s=to_string(x),t=s;
    reverse(s.begin(),s.end());
    return t==s;
}

void sol() {
    for(ll n=1;n<=Lim;n++){
        bool f=true;
        cout<<n<<'\n';
        for(ll a=0;a<=n;a++){
            ll b=n-a;
            if(check(a)&&b%12==0){
                cout<<a<<" "<<b<<'\n';
                f=false;
                break;
            }
        }
        if(f) cout<<"-1\n";
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