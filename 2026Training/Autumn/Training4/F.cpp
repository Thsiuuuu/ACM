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
void sol() {
    ll n,c1,c2;
    cin>>n>>c1>>c2;
    ll ans=3*n*min(c1,c2);
    ll sum=0;
    for(int i=0;i<n;i++){
        array<char,3> ch;
        cin>>ch[0]>>ch[1]>>ch[2];
        sort(ch.begin(),ch.end());
        ll number=1e9;
        if(ch[0]==ch[1]||ch[1]==ch[2]){
            number=min(c2+c2,c2+c1);
        }
        number=min({number,3*c1,3*c2,2*c2+c1,c2+2*c1});
        // cout<<number<<'\n';
        sum+=number;
    }
    ans=min(ans,sum);
    cout<<ans;
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