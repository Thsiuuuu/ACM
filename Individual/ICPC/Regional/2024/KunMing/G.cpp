#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
void sol() {
    ll a,b;cin>>a>>b;
    queue<tuple<ll,ll,ll>> Q;
    Q.push({a,b,0});
    while(Q.size()){
        auto [x,y,step]=Q.front();
        if(x==0||y==0){
            cout<<step+1<<'\n';
            return ;
        }
        Q.pop();
        ll g=gcd(x,y);
        Q.push({x-g,y,step+1});
        Q.push({x,y-g,step+1});
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