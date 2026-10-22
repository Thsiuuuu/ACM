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
    ll a,c;
    int b,d,e,p;
};
int n,m;
void sol() {
    cin>>n>>m;
    vector<node> days(n+1);
    for(int i=1;i<=n;i++){
        auto&[a,c,b,d,e,p]=days[i];
        cin>>a>>b>>c>>d>>e>>p;
    }
    vector<array<double,4>> nxt(m+1,{0,0,0,0});
    vector<array<double,4>> cur(m+1,{-1,-1,-1,-1});
    for(int i=n;i>=1;i--){
        const auto&t=days[i];
        double q=t.p/100.0;
        auto cal=[&](int k,int s) -> double {
            if(k<0) return -1;
            if(t.p==0) return nxt[k][s|2];
            if(t.p==100) return nxt[k][s|1];
            double x=nxt[k][s|1];
            double y=nxt[k][s|2];
            if(x<0||y<0) return -1;
            return q*x+(1.0-q)*y;  
        };
        for(int s=0;s<4;s++){
            for(int j=0;j<=m;j++){
                double mx=-1;
                double v=cal(j-t.b,s);
                if(v>=0) mx=max(mx,t.a+v);
                if(s==3){
                    int cost = t.d +t.e;
                    if(j>=cost&&nxt[j-cost][0]>=0){
                        mx=max(mx,t.c+nxt[j-cost][0]);
                    }
                }else{
                    v=cal(j-t.d,s);
                    if(v>=0) mx=max(mx,t.c+v);
                }
                cur[j][s]=mx;
            }
        }
        swap(nxt,cur);
    }
    if(nxt[m][0]<0) {
        cout<<"-1";
    }else{
        cout<<fixed<<setprecision(12)<<nxt[m][0]<<'\n';
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