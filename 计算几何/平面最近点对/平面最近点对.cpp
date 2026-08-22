#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=200010;

struct Point{
    double x,y;
}a[N],b[N];

int n;

bool cmp(const Point&a,const Point&b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
double dis(const Point&a,const Point&b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double devide(int l,int r){
    double d=2e9;
    if(l==r) return d;
    
    int  mid=(l+r)>>1; Point tmp=a[mid];
    d=min(devide(l,mid),devide(mid+1,r));
    int i=l,j=mid+1,k=0,t=0;
    while(i<=mid&&j<=r){
        if(a[i].y<a[j].y) b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    while(i<=mid) b[k++]=a[i++];
    while(j<=r) b[k++]=a[j++];
    for(int i=l,j=0;i<=r;) a[i++]=b[j++];

    for(int i=0;i<k;i++){
        if(fabs(tmp.x-b[i].x)<d) b[t++]=b[i];
    }
    for(int i=0;i<t;i++){
        for(int j=i+1;j<t&&b[j].y-b[i].y<d;j++){
            d=min(d,dis(b[j],b[i]));
        }
    }
    return d;
}

int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp);
    printf("%.4lf",devide(1,n));
    return 0;
}