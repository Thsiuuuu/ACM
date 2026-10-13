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

void sol() {
    int n,m;cin>>n>>m;
    VL a(n+1),b(n+1);
    vector<pll> all(m+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>all[i].first>>all[i].second;//坐标，编号
    }
    VI nxt(m+1),last(n+1,m+1);
    for(int i=m;i>=1;i--){
        nxt[i]=last[all[i].second];
        last[all[i].second]=i;
    }
    int idx=1;
    ll ans=0;
    queue<int> Q;
    for(int i=1;i<=n;i++) Q.push(i);
    set<int> mp;
    for(int i=1;i<=m;i++){
        while(ans<all[i].first){
            int j=idx;  
            if(mp.size()) j=min(j,*mp.begin());
            if(j>m) break;
            ll both=min(b[all[j].second],all[i].first-ans);
            b[all[j].second]-=both;
            ans+=both;
            if(b[all[j].second]==0){
                if(j==idx) idx++;
                else mp.erase(j);
            }
        }
        if(ans<all[i].first){
            while(Q.size()){
                int u=Q.front();
                Q.pop();
                if(b[u]==0) continue;
                if(ans+b[u]<all[i].first){
                    ans+=b[u];
                    b[u]=0;
                }else{
                    b[u]-=(all[i].first-ans);
                    ans=all[i].first;
                    if(b[u]) Q.push(u);
                    break;
                }
            }
            if(ans<all[i].first) break;
        }
        if(idx==i) idx++;
        mp.erase(i);
        b[all[i].second]=a[all[i].second];
        // cout<<all[i].second<<" "<<b[all[i].second]<<'\n';
        // for(int j=1;j<=n;j++) cout<<b[j]<<" ";
        // cout<<'\n';
        // cout<<ans<<'\n';
        Q.push(all[i].second);
        if(nxt[i]<idx){
            mp.insert(nxt[i]);
        }
    }
    for(int i=1;i<=n;i++) ans+=b[i];
    // ll sum=0;
    // for(int i=1;i<=n;i++) sum+=a[i];
    // cout<<sum<<'\n';
    cout<<ans<<'\n';
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