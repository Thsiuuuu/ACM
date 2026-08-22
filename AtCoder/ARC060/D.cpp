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
    ll n,s;
    cin>>n>>s;
    if(n<s) cout<<"-1";
    else if(n==s) cout<<n+1;
    else{
        ll sq=sqrt(n);
        for(ll i=2;i<=sq;i++){
            ll sum=0;
            ll tmp=n;
            while(tmp){
                sum+=(tmp%i);
                tmp/=i;
            }
            if(sum==s){
                cout<<i;
                return ;
            }
        }
        ll del=n-s;
        ll ans=-1;
        for(ll i=1;i*i<n;i++){
            ll b=del/i+1;
            if(del%i==0&&b>sq&&(n%b+n/b)==s) ans=del/i+1;
        }
        cout<<ans;
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