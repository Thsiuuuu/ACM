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
    ll n,a;cin>>n>>a;
    VL v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll m;cin>>m;
    VL b(m),Q(m),Qidx(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
        Qidx[i]=i;
    }
    ll sum=0,cnt=0;
    VI idx;
    set<ll> all;
    for(int i=0;i<n;i++){
        if(v[i]<=a) sum-=v[i],cnt++;
        else {
            idx.push_back(i);
            if(cnt){
                sum+=v[i],cnt--;
            }else{
                all.insert(i);
            }
        }
    }
    sum+=v[n-1]*cnt;
    sort(idx.begin(),idx.end(),[&](int x,int y){
        return v[x]<v[y];
    });
    sort(Qidx.begin(),Qidx.end(),[&](int x,int y){
        return b[x]<b[y];
    }); 
    int cur=-1;
    for(int qidx:Qidx){
        while(cur+1<idx.size()&&v[idx[cur+1]]<b[qidx]){
            cur++;
            auto it=all.find(idx[cur]);
            if(it!=all.end()) all.erase(it);
            else{
                auto i2=all.upper_bound(idx[cur]);
                if(i2==all.end()){
                    sum+=v[n-1]-v[idx[cur]];
                }else{
                    sum+=v[*i2]-v[idx[cur]];
                    all.erase(i2);
                }
            } 
        }
        Q[qidx]=sum;
    }
    for(int i=0;i<m;i++) cout<<Q[i]<<' ';
    cout<<'\n';
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