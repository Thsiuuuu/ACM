#include <bits/stdc++.h>
using namespace std;

/*

    第一道三维计算几何
    不会判断一条线段和一个点的相对关系，可以用混合积判断
    一个点不好计算可以用原点和该点连成的向量解决


*/

#define double long double

const double PI=3.141592653589793238;
struct Point{
    double x,y,z;
    Point(double x_=0,double y_=0,double z_=0):x(x_),y(y_),z(z_){}
    Point operator+(Point a){
        return Point({x+a.x,y+a.y,z+a.z});
    }
    Point operator-(Point a){
        return Point({x-a.x,y-a.y,z-a.z});
    }
    double operator*(Point a){
        return x*a.x+y*a.y+z*a.z;
    }
    Point operator%(Point a){
        return Point({y*a.z-a.y*z,a.x*z-x*a.z,x*a.y-a.x*y});
    }
    double lp(){return (x*x+y*y+z*z);}
    double len(){return sqrt(lp());}

    void change(double r){
        x=r*x/len();
        y=r*y/len();
        z=r*z/len();
    }
};

double cha(const Point&a,const Point& b,const Point&c){
    return (a.x*(b.y*c.z-c.y*b.z)-b.x*(a.y*c.z-c.y*a.z)+c.x*(a.y*b.z-b.y*a.z));
}

void sol(){

    double r;
    cin>>r;
    Point st,ed,my;
    cin>>my.x>>my.y>>my.z;
    cin>>st.x>>st.y>>st.z;
    cin>>ed.x>>ed.y>>ed.z;

    my.change(r);
    st.change(r);
    ed.change(r);

    Point n=st%ed;
    double ck1=cha(st,my,n),ck2=cha(ed,my,n);
    if(ck1*ck2>0){
        double r1=r*fabs(acos((my*ed)/(r*r))),r2=r*fabs(acos((my*ed)/(r*r)));
        cout<<min(r1,r2)<<'\n';
    }else{
        double sita=acos((my*n)/(r*n.len()));
        sita=min(sita,PI-sita);
        sita=PI/2-sita;
        cout<<r*sita<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}