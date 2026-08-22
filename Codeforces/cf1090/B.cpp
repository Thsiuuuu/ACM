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
    vector<int> a(7,0);
    int sum=0;
    for(int i=1;i<=7;i++){
        cin>>a[i];
        sum-=a[i];
    }
    int mx=-700;
    for(int i=1;i<=7;i++){
        mx=max(sum+2*a[i],mx);
    }
    cout<<mx<<'\n';
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