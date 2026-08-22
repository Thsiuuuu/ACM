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
    ll y;
    cin>>y;
    for(int i=0;i<=100;i++){
        ll x=y-i;
        string s=to_string(x);
        ll tmp=0;
        for(int i=0;i<s.size();i++){
            tmp+=(s[i]-'0');
        }
        if(tmp==i){
            cout<<x<<'\n';
            return;
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