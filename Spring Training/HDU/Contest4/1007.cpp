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
    int n,s;
    cin>>n>>s;
    int numbers=0,number0=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==s) numbers++;
        else if(x==0) number0++;
    }
    if(numbers>=1&&number0+numbers==n) cout<<"YES\n";
    else cout<<"NO\n";
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