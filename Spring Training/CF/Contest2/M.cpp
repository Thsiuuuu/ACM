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
    ll n;cin>>n;
    if(n==1){
        cout<<"-1\n";
    }else{
        for(int i=1;i<=5;i++){
            if(i&1) cout<<n<<" ";
            else if(i==2) cout<<(n+1)<<" ";
            else cout<<n*(n+1)<<" ";
        }
        cout<<'\n';
    }
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