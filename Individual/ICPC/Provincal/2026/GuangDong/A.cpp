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
ll n,k;
vector<pll> all;
bool ck(ll mid){
    vector<pll> has;
    for(int i=0;i<n;i++){
        if(all[i].first<=mid){
            auto [a,b]=all[i];
            has.push_back({b-(mid-a),b+(mid-a)});
        }
        else break;
    }
    if(has.size()==0) return false;
    sort(has.begin(),has.end(),[&](const pll&A,const pll&B)- >bool{
        if(A.first==B.first) return A.second<B.second;
        else return A.first<B.first;
    });     
    if(has[0].first>0) return false;
    ll r=has[0].second;
    for(const auto &[left,right]:has){
        if(r+1<left) return false;
        else r=max(r,right);
    }
    return r>=k;
}
void sol() {
    cin>>n>>k;
    ll mx=0;
    for(int i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        all.push_back({x,y});
        mx=max(mx,x);
    }
    sort(all.begin(),all.end(),[&](const pll&A,const pll&B) - >bool{
        return A.first<B.first;
    }); 
    ll l=0,r=k+mx,mid,ans=-1;
    while(l<=r){
        mid=(l+r)>>1;
        if(ck(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
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