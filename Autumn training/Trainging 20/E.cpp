#include <bits/stdc++.h>
using namespace std;


#define double long double 
struct Point{
    double x,y;
    Point(double a=0,double b=0):x(a),y(b){}
    Point operator+(Point p){
        return Point({x+p.x,y+p.y});
    }
    Point operator-(Point p){
        return Point({x-p.x,y-p.y});
    }
    Point operator%(double t){
        return Point({x*t,y*t});
    }
    
    double pw(){
        return x*x+y*y;
    }
    
    double length(){
        return sqrt(pw());
    }
    
    bool operator<(const Point p)const {
        if(x==p.x){
            return y>p.y;
        }
        return x<p.x;
    }
};

struct func{
    double a,b,c;
};//二次函数类

int n,t;
const double inf=2e9;
double mid1,mid2,v1,v2,v3,v4,l,r;

inline double cal(double x,const vector<func>& f){
    double ret=-inf;
    for(int i=0;i<n;i++){
        ret=max(ret,f[i].a*x*x+f[i].b*x+f[i].c);
    }
    return ret;
}

void sol(){

    cin>>n;
    vector<Point> p(n);
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    double a,b,c;
    cin>>a>>b>>c;
    
    for(int i=0;i<n;i++){
        Point cpy=p[i];
        p[i].x=(b*cpy.x-a*cpy.y)/sqrt(a*a+b*b);
        p[i].y=(a*cpy.x+b*cpy.y+c)/sqrt(a*a+b*b);
    }

    sort(p.begin(),p.end());
    vector<func> f(n);
    for(int i=0;i<n;i++){
        f[i].a=1,f[i].b=-2*p[i].x,f[i].c=p[i].pw();
    }

    l=p[0].x,r=p[n-1].x;
    
    while(l+1e-14<r){
        mid1=(l+l+r)/3,mid2=(l+r+r)/3;

        v1=cal(1,f),v2=cal(mid1,f),v3=cal(mid2,f),v4=cal(r,f);
        if(v1<v2) r=mid1;
        else if(v4<v3) l=mid2;
        else if(v1>v2&&v2<v3) r=mid2;
        else if(v4>v3&&v3<v2) l=mid1;
        else l=mid1,r=mid2;
    }
    cout<<sqrt(cal(l,f))<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    cout<<fixed<<setprecision(12);
    while(t--) sol();
    return 0;
}