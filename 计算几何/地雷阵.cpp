#include <bits/stdc++.h>
using namespace std;
#define double long double
#define pdd pair<double,double>
const double PI=acos(-1);
const double HPI=PI/2;
/*

    首先考虑圆的大小关系
    如果原点本身就在某个圆上了，那么一定中雷了
    同样在圆里面也是，所以要用距离进行判断。
    如果不是就需要考虑切线，特判与x轴垂直的切线，剩下的直线不妨设为y=k*x，
    然后圆心到直线的距离等于半径，就可以得出k的解

*/

struct Point{
    double x,y;
    Point(double x_=0,double y_=0):x(x_),y(y_){}
    double len2(Point other){
        return (other.x-x)*(other.x-x)+(other.y-y)*(other.y-y);
    }
};

struct Circle{
    Point p;
    double r;
    Circle(double x_=0,double y_=0,double r_=0):p(x_,y_),r(r_){}
};

bool cmp(pdd a,pdd b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<Circle> st(n);
    for(int i=0;i<n;i++){
        cin>>st[i].p.x>>st[i].p.y>>st[i].r;
    }
    vector<pdd> ang;
    for(int i=0;i<n;i++){
        auto [p,r]=st[i];
        auto [a,b]=p;
        if(a*a+b*b<=r*r){
            cout<<"0.000";
            return 0;
        }
        if(a==r){
            ang.push_back({2*atan2(b,a)-HPI,HPI});
        }else{
            double del=r*sqrt(a*a+b*b-r*r);
            double sub=a*a-r*r;
            ang.push_back({max(atan2((a*b-del)/sub,1),(double)0),min(atan2((a*b+del)/sub,1),HPI)});
        }
    }

    sort(ang.begin(),ang.end(),cmp);

    double l=0,r=0,ans=HPI;
    for(int i=0;i<ang.size();i++){
        auto [st,ed]=ang[i];
        if(st>r){
            ans-=(r-l);
            l=st,r=ed;
        }else{
            r=max(r,ed);//错误1，区间合并的时候右端点应为大的右端点
        }
    }
    ans-=(r-l);
    cout<<fixed<<setprecision(3)<<(ans/HPI);
    return 0;
}