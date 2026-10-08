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
const int N=2e5+10;
ll a[N];
void sol() {
    set<ll> st;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    st.insert(0);
    for(int i=1;i<n;i++){
        st.insert({a[i]^a[i+1],a[i]&a[i+1],a[i]|a[i+1]});
        st.insert({(a[i]|a[i+1])-a[i+1],(a[i]|a[i+1])-a[i]});
    }
    cout<<st.size();
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