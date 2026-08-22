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
    ll n,a,b,x,y;
    cin>>n>>a>>b>>x>>y;
    if(x>=n) cout<<n*a<<'\n';
    else{
        n-=x;
        i128 ans=0;
        i128 t=(n)%(x+y);
        ans=n/(x+y)*max((i128)x*a,(i128)(y+x)*b)+max(t*b,(t>y)*(t-y)*a);
        ans+=x*a;
        stack<int> res;
        while(ans){
            res.push(ans%10);
            ans/=10;
        }
        while(res.size()){
            cout<<res.top();
            res.pop();
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