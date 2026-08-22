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
    int n,m,k;cin>>n>>m>>k;
    vector<bool> is(k+1,false);
    vector<int> f(k);
    vector<int> c(k+1,0),d;
    for(int i=0;i<n;i++){
        cin>>f[i];
        is[f[i]]=true;
    }
    int sum=0;
    map<pii,int> mp;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        if(is[a]&&is[b]) sum++;
        else if(a==b) c[a]++;
        else if(!is[a]&&!is[b]){
            if(a>b) swap(a,b);
            mp[{a,b}]++;
        }else{
            if(!is[a]) c[a]++;
            else       c[b]++;
        }
    }
    d=c;
    sort(c.begin()+1,c.end(),greater<int>());
    int ans=(c[1]+((2<=k)?c[2]:0));
    // cout<<ans<<'\n';
    for(const auto&[key,val]:mp){
        // cout<<key.first<<" "<<key.second<<'\n';
        ans=max(ans,val+d[key.first]+d[key.second]);
    }
    cout<<sum+ans<<'\n';
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