#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

#define x first
#define y second

using namespace std;

const int  N=100010;
const double PI=acos(-1);
int n;
struct Point{
    double x,y;
}p[N];
struct Circle{
    Point p;
    double r;
}C;

Point operator+(Point a,Point b){
    return Point(a.x+b.x,a.y+b.y);
}
Point operator-(Point a,Point b){
    return Point(a.x-b.x,a.y-b.y);
}
Point operator*(Point a,double t){
    return {a.x*t,a.y*t};
}

Point operator/(Point a,double t){
    return {a.x/t,a.y/t};
}

double operator*(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}

Point rotate(Point a,double b){
    return {a.x*cos(b)-a.y*sin(b),a.x*sin(b)+a.y*cos(b)};
}

double dis(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

Point cross(Point a,Point u,Point b,Point v){
    double t=(a-b)*v/(v*u);
    return a+u*t;
}

pair<Point,Point> midperp(Point a,Point b){
    return {(a+b)/2,rotate(b-a,PI/2)};
}//求中垂线

Circle cover(Point a,Point b){
    return {(a+b)/2,dis(a,b)/2};
}//覆盖两点的圆

Circle cover(Point a,Point b,Point c){
    auto u=midperp(a,b),v=midperp(a,c);
    auto p=cross(u.x,u.y,v.x,v.y);
    return {p,dis(p,a)};
}//覆盖三点的圆，利用中垂线求