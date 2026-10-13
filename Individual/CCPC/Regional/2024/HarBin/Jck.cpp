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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){
    return uniform_int_distribution<int> (l,r)(rng);
}
// int inf=5e2;
void sol() {
    int n=rnd(4,10),m=rnd(5,10);
    cout<<n<<" "<<m<<'\n';
    for(int i=1;i<=n;i++){
        cout<<rnd(1,100)<<" ";
    }
    cout<<'\n';
    int last=0;
    vector<pair<int,int>> all;
    for(int i=0;i<m;i++){
        all.push_back({rnd(1,500),rnd(1,n)});
    }
    sort(all.begin(),all.end());
    for(const auto&[A,B]:all){
        cout<<A<<" "<<B<<'\n';
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    freopen("J.txt","w",stdout);
    cout<<t<<'\n';
    while (t--) {
        sol();
    }
    return 0;
}