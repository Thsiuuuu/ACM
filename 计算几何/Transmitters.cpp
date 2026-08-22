#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=155;

struct Point{
    int x,y;
}p[N],o,a;


Point operator+(Point a,Point b){
    return Point(a.x+b.x,a.y+b.y);
}

Point operator-(Point a,Point b){
    return Point(a.x-b.x,a.y-b.y);
}

Point operator*(Point a,double t){
    return Point(a.x*t,a.y*t);
}

double operator*(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}//叉积，两个向量形式的

double cross(Point a,Point b,Point c){
    return (b-a)*(c-a);
}//叉积，把三个点转化成两个向量再计算

double operator&(Point a,Point b){
    return a.x*b.x+a.y*b.y;
}//点乘，两个向量形式的

double dot(Point a,Point b,Point c){
    return (b-a)&(c-a);
}//点乘，三个点形式的


double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

double dis(Point a,Point b){
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
    int n,m,ans;
    double r;
    while(scanf("%d%d%lf",&o.x,&o.y,&r),r>=0){
        n=ans=0,scanf("%d",&m);
        while(m--){
            scanf("%d%d",&a.x,&a.y);
            if(dis(a,o)<=r){
                p[n++]=a;//收集半径以内的点
            }
        }
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(cross(o,p[i],p[j])>=0) cnt++;
            }
            ans=max(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}