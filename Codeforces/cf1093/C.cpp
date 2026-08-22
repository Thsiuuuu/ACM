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
void sol() {
    ll a,b;
    cin>>a>>b;
    ll S=a+2*b;
    for(ll i=1;i<=1e5&&(3*i+1<=S);i++){
        if((S-i)%(2*i+1)==0){
            ll j=(S-i)/(2*i+1);
            if(b<=(i*j+min(i,j))){
                cout<<i<<" "<<(S-i)/(2*i+1)<<'\n';
                return ;
            }
        }
    }
    cout<<"-1\n";
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