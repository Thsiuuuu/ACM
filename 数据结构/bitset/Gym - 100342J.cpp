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
bitset<1501> b[1501],a[1501];//a存自己的入边，b存自己的出边
void sol() {
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            if(c=='+'){
                b[j][i]=1;
                a[i][j]=1;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(b[i][j]==0) continue;
            ans+=(a[i]&b[j]).count();
        }
    }
    cout<<ans/3;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    freopen("triatrip.in","r",stdin);
    freopen("triatrip.out","w",stdout);
    while (t--) {
        sol();
    }
    return 0;
}