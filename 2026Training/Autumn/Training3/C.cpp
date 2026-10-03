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
const int N=1010;
ll b[N],a[N],n,s[N];

void sol(int ts) {
    cin>>n;
    ll sum=0;
    for(int i = 0;i<n+1;i++){
        cin>>s[i];
        sum+=s[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    sum+=*max_element(b,b+n);
    cout<<"Case #"<<ts<<": "<<sum<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}