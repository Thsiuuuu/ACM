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
bool chk(ll x){
    ll sum=0;
    ll lb=sqrt(x);
    if(lb*lb!=x) return false;
    while(x){
        sum+=(x%10);
        x/=10;
    }
    lb =sqrt(sum);
    return lb*lb==sum;
}
void sol() {
    ll x;
    cin>>x;
    if(chk(x)) cout<<"Yes";
    else cout<<"No";
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