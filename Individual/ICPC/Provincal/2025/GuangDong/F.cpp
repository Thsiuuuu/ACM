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

int is[20],cnt[20];
void sol() {
    ll n,a,b;cin>>n>>a>>b;
    ll m;cin>>m;
    for(int i=0;i<20;i++) is[i]=cnt[i]=0;
    ll curtime=0,curcnt=0;
    int ans=0;
    // cout<<"hel\n";
    priority_queue<ll,VL,greater<ll>> Q; 
    
    for(int i=0;i<m;i++){
        ll t;char p;string v;cin>>t>>p>>v;
        int curx=p-'A';
        if(is[curx]) continue;
        if(v=="ac"){
            curtime+=t+cnt[curx]*20,curcnt++;
            is[curx]=1;
        }else if(v=="rj"){
            cnt[curx]++;
        }else{
            is[curx]=1;
            Q.push(t+cnt[curx]*20);
        }
    }
    if(curcnt>a||(curcnt==a&&curtime<b)) return void(cout<<"0\n");
    while(Q.size()){
        auto val=Q.top();
        Q.pop();
        ans++,curcnt++,curtime+=val;
        if(curcnt>a||(curcnt==a&&curtime<b)) return void(cout<<ans<<"\n");
    }
    cout<<"-1\n";
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