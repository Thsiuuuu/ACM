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
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
void sol() {
    int n,k;cin>>n>>k;
    string ans(k,'N');
    vector<pii> all(k);
    for(int i=0;i<k;i++){
        cin>>all[i].first>>all[i].second;
    }
    int s;cin>>s;
    // VI pp(s);
    vector<bool> is(n+1,true);
    for(int i=0;i<s;i++){
        int x;cin>>x;
        is[x]=false;
    }
    for(int i=k-1;i>=0;i--){
        auto [a,b]=all[i];
        if(is[a]&&!is[b]){
            is[b]=true;
            ans[i]='T';
        }
    }
    bool f=true;
    for(int i=1;i<=n;i++){
        f&=is[i];
    }
    cout<<(f?"TAK\n":"NIE\n");
    if(f){
        cout<<ans<<'\n';
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