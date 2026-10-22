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
const ld eps=1e-9;
int sgn(ld x){
    return fabs(x)<eps?0:(x<0?-1:1);
}
void sol() {
    ld x,y,vx,vy,y1,y2,vy1,vy2,x1,x2,vx1,vx2;
    cin>>x>>y>>vx>>vy>>y1>>y2>>vy1>>vy2>>x1>>x2>>vx1>>vx2;
    ld tt=(y2-y1)/(vy1+vy2);
    y=y1+(y2-y1)/(vy1+vy2)*vy1;
    // ld curx=x;
    if(!sgn(vx1)&&!sgn(vx2)){
        ld period=2*(x2-x1)/abs(vx);
        tt=fmod(tt,period);
    }
    while(sgn(tt)>0){
        ld dt;
        if(sgn(vx)>0){
            dt=(x2-x)/(vx-vx2);
            if(sgn(vx-vx2)<=0||sgn(dt-tt)>=0){
                dt=tt;
            }
        }else{
            dt=(x-x1)/(-vx-vx1);
            if(sgn(-vx-vx1)<=0||sgn(dt-tt)>=0){
                dt=tt;
            }
        }
        x+=vx*dt;
        tt-=dt;
        x2+=vx2*dt;
        x1-=vx1*dt;
        vx=-vx;
    }
    cout<<fixed<<setprecision(12)<<x<<" "<<y<<'\n';
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