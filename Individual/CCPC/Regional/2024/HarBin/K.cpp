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
struct node{
    ll l,r;
    ll w;
    bool operator<(const node&o) const{
        return w>o.w;
    }
};
ll n,m;
const int N=2e5+10;
ll pt[N],pw[N];
void sol() {
    cin>>n>>m;
    vector<node> all(n+1);
    for(int i=1;i<=n;i++) cin>>all[i].w>>all[i].l>>all[i].r;
    sort(all.begin()+1,all.end());
    ll totime=0,base=0,ans=0,curtime;
    for(int i=1;i<=n;i++){
        ans+=all[i].w*all[i].l;
        totime+=all[i].l;
    }
    for(int i=1;i<=n;i++){
        const auto&[l,r,w]=all[i];
        pt[i]=pt[i-1]+(r-l);
        pw[i]=pw[i-1]+(r-l)*w;
    }
    base=ans;
    curtime=m-totime;
    for(int i=1;i<=n;i++){
        const auto&[l,r,w]=all[i];
        ans+=min((r-l),m-totime)*w;
        totime+=min(m-totime,r-l);
    }
    // cout<<ans<<" "<<base<<" "<<totime<<'\n';
    // for(int i=1;i<=n;i++){
    //     cout<<pt[i]<<" "<<pw[i]<<'\n';
    // }
    for(int i=1;i<=n;i++){
        const auto&[l,r,w]=all[i];
        curtime+=l;
        auto it=upper_bound(pt,pt+i,curtime);
        if(it==pt+i){
            ans=max(ans,base-l*w+pw[i-1]+(curtime-pt[i-1])*w);
        }else{
            ans=max(ans,base-l*w+pw[it-pt-1]+(curtime-*(it-1))*all[it-pt].w);
        }
        curtime-=l;
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