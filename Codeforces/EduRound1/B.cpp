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
    string s;
    cin>>s;
    int m;
    cin>>m;
    s=' '+s;
    while(m--){
        int l,r,k;
        cin>>l>>r>>k;
        k%=(r-l+1);
        if(k){
            s.replace(l,r-l+1,s.substr(r-k+1,k)+s.substr(l,r-k-l+1));
        }
    }
    cout<<s;
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