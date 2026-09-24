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
    int n;cin>>n;
    int cnt=0,rr=-1;
    vector<pii> all;
    vector<pii> a(n);
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end(),[&](pii&x,pii&y)->bool{
        return x.first<y.first;
    });
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j].first<=a[i].second){
                all.push_back({min(a[i].first,a[j].first),max(a[i].second,a[j].second)});
            }
        }
    }
    sort(all.begin(),all.end(),[&](pii&x,pii&y)->bool{
        return x.second<y.second;
    });
    for(int i=0;i<all.size();i++){
        if(all[i].first>rr) cnt++,rr=all[i].second;
    }
    cout<<n-2*cnt<<'\n';
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