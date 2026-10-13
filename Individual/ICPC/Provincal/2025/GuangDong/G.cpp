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
const int N=1e6+10;
ll n,q;
ll dp[N],a[N],g[N];
void sol() {
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    int idx=1;
    for(int i=1;i<=a[n];i++) {
        if(idx+1<=n&&i>=a[idx+1]) idx++;
        dp[i]=dp[i-a[idx]]+1;
    }
    for(int i=1;i<=a[n];i++){
        g[dp[i]]++;
    }
    for(int i=1;i<=a[n];i++) g[i]+=g[i-1];
    while(q--){
        ll m;cin>>m;
        cout<<g[min(m,a[n])]<<' ';
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