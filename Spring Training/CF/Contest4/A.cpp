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
    int n;
    cin>>n;
    int mn=INT32_MAX;
    for(int i=0;i<n;i++){
        int  x;cin>>x;
        if(abs(x)%2==0){
            mn=min(mn,(abs(x)+1)>>1);
        }
    }
    if(mn==INT32_MAX) cout<<"-1\n";
    else cout<<mn;
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