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
bitset<502> f[502];
int n,k,a[502];
void sol() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int x=500;x>=a[i];x--){
            f[x]|=((f[x-a[i]]<<a[i])|f[x-a[i]]);
        }
    }
    cout<<f[k].count()<<'\n';
    for(int i=0;i<=500;i++){
        if(f[k][i]) cout<<i<<" ";
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