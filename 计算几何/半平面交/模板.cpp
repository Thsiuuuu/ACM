#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

/*


    每次都是要使先前的所有交点在自己的左侧的，所以队尾队首都要进行维护，这个过程是缩小凸包的过程
    然后最后如果已经到了最终的凸包，还有额外的直线的话，也不会被去除，因此需要额外的去除


*/

const int N=510;
const double eps=1e-12;

struct Point{
    double x,y;
    Point(){}
    Point(double a,double b){x=a;y=b;}
    Point operator+(Point b){return Point(x+b.x,y+b.y);}
    Point operator-(Point b){return Point(x-b.x,y-b.y);}
    Point operator*(double b){return Point(x*b,y*b);}
    double operator%(Point b){return x*b.y-y*b.x;}
}p[N];

struct Line{
    Point s,e;double ang;
    Line(){}
    Line(Point a,Point b){s=a,e=b;ang=atan2((b-a).y,(b-a).x);}
    bool operator<(Line& b){
        return fabs(ang-b.ang)>eps?ang<b.ang:(e-s)%(b.e-s)<0;    
    }//按极角排序，极角相同就优先选左边，不同优先极角小的
    Point cross(Line &b){
        Point u=s-b.s,v=e-s,w=b.e-b.s;
        double t=w%u/(v%w);
        return s+v*t;
    }//求两直线交点
    bool right(Line&b,Line&c){
        Point p=b.cross(c);
        return (e-s)%(p-s)<0;
    }//判断两直线交点是否在另外一个直线右侧
}a[N],q[N];
int n,m,t;

double half_plane(){
    sort(a+1,a+n+1);
    int h=1,t=1;q[1]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i].ang-a[i-1].ang<eps) continue;
        while(h<t&&a[i].right(q[t],q[t-1])) t--;
        while(h<t&&a[i].right(q[h],q[h+1])) h++;
        q[++t]=a[i];
    }
    while(h<t&&q[h].right(q[t],q[t-1])) t--;
    q[++t]=q[h];
    int k=0;double res=0;
    for(int i=h;i<t;i++) p[++k]=q[i].cross(q[i+1]);
    for(int i=2;i<k;i++) res+=(p[i]-p[1])%(p[i+1]-p[1]);
    return res/2;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    scanf("%d",&t);
    while(t--){
        cin>>m;
        for(int i=1;i<=m;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=1;i<=m;i++) a[++n]={p[i],p[i%m+1]};
    }
    printf("%.3lf\n",half_plane());
    return 0;
}