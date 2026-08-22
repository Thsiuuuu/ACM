#include <bits/stdc++.h>
using namespace std;
/*



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
    ll b;
    cin>>n>>b;
    vector<ll> s1,s2;
    for(int i=0;i<n-1;i++){
        ll x;
        cin>>x;
        if(x<=0) s1.push_back(x);
        else s2.push_back(x);
    }
    sort(s1.begin(),s1.end(),greater<int>());
    sort(s2.begin(),s2.end());
    bool f=false;
    for(int i=0;i<s2.size();i++){
        f=true;
        b+=s2[i];
    }
    if(f) cout<<b;
    if(!f){
        if(llabs(s1[0])>b) cout<<"-1";
        else cout<<b-llabs(s1[0]);
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