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

const ll Mx=1e18;

bool check(ll a,ll b,ll x,ll y,ll mid){
    return ((i128)x*mid>=a)&&((i128)y*mid>=b);
}

void sol() {
    int n;
    cin>>n;
    ll a=0,b=0;
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        if(i==1) a=x,b=y;
        else{
            ll l=1,r=Mx/min(x,y);
            ll mid;
            ll ans;
            while(l<=r){
                mid=(l+r)>>1;
                if(check(a,b,x,y,mid)){
                    ans=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            // cout<<i<<" "<<ans<<'\n';
            a=x*ans,b=y*ans;
        }
    }
    cout<<a+b;
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