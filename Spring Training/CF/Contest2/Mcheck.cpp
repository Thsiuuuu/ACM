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
    int n=100;
    for(int i=1;i<=n;i++){
        cout<<i<<'\n';
        for(int a=i+1;a<=1100;a++){
            for(int b=a+1;b<=1200;b++){
                if(i*(a+b)==a*b){
                    cout<<a<<" "<<b<<'\n';
                    break;
                }
            }
        }
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