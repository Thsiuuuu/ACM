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
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/

void sol() {
    ll n;cin>>n;
    if(n==1) return void(cout<<"1\n");
    VL a,b;
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0){
            if(i*i==n) a.push_back(i);
            else       a.push_back(i),b.push_back(n/i);
        }
    }
    reverse(b.begin(),b.end());
    ll ans=0;
    for(ll x:b) a.push_back(x);
    for(int i=1;i<a.size();i++){
        ans+=(a[i]-a[i-1])*n/a[i-1];
    }
    cout<<ans+1<<'\n';
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