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
ll s[4][N],number[N][4];
int n;
ll C(ll x){
    return x*(x-1)/2;
}
void sol() {
    cin>>n;
    map<pii,ll> c12,c13,c23;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++) {
            cin>>number[i][j];
            s[j][number[i][j]]++;
        }
        c12[{number[i][1],number[i][2]}]++;
        c13[{number[i][1],number[i][3]}]++;
        c23[{number[i][2],number[i][3]}]++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll x=number[i][1],y=number[i][2],z=number[i][3];
        ll tot=s[1][x]+s[2][y]+s[3][z]-c12[{x,y}]-c13[{x,z}]-c23[{y,z}];
        ll s1=s[1][x]-c12[{x,y}]-c13[{x,z}]+1,s2=s[2][y]-c12[{x,y}]-c23[{y,z}]+1,s3=s[3][z]-c13[{x,z}]-c23[{y,z}]+1;
        ans+=C(tot)-C(s1)-C(s2)-C(s3);
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