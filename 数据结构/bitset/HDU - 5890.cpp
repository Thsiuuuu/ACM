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
int ans[51][51][51];
bitset<88> f[11];
int a[52],n;
bool ck(int x,int y,int z){
    for(int i=1;i<=10;i++) f[i].reset();
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        if(i==x||i==y||i==z) continue;
        if(a[i]>87) continue;
        for(int k=10;k>=1;k--){
            f[k]|=(f[k-1]<<(a[i]));
        }
    }
    return f[10][87];
}
void sol() {
    cin>>n;
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++) cin>>a[i];
    int q;cin>>q;
    while(q--){
        array<int,3> p;
        for(int i=0;i<3;i++) cin>>p[i];
        sort(p.begin(),p.end());
        int& res=ans[p[0]][p[1]][p[2]];
        if(res==-1) res=ck(p[0],p[1],p[2]);
        cout<<((res)?"Yes\n":"No\n");
    }
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