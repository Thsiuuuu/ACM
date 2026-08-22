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
void sol() {
    int n;
    while(cin>>n){
        vector<ll> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n==1){
            cout<<"1\n";
        }else{
            ll del=a[n]-a[n-1];
            ll ans=n-1;
            for(int i=n-1;i>=2;i--){
                if(a[i]-a[i-1]==del) ans--;
                else break;
            }
            cout<<ans<<'\n';
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