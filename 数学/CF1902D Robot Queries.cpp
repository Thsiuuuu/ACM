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
    int n,q;cin>>n>>q;
    string s;cin>>s;
    vector<pii> pos(n+1,{0,0});
    map<pii,VI> mp;
    int x,y;x=y=0;
    mp[{0,0}].push_back(0);
    for(int i=1;i<=n;i++){
        x+=(s[i-1]=='R')-(s[i-1]=='L');
        y+=(s[i-1]=='U')-(s[i-1]=='D');
        pos[i]={x,y};
        mp[{x,y}].push_back(i);   
    }
    auto ck=[&](pii p,int l,int r)->bool{
        if(!mp.count(p)) return false;
        auto it=lower_bound(mp[p].begin(),mp[p].end(),l);
        return it!=mp[p].end()&&*it<=r;
    };
    while(q--){
        x,y;int l,r;cin>>x>>y>>l>>r;
        int fx=pos[l-1].first+pos[r].first-x,fy=pos[l-1].second+pos[r].second-y;
        bool f=ck({x,y},0,l-1)|ck({x,y},r,n)|ck({fx,fy},l,r-1);
        cout<<(f?"YES\n":"NO\n");
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