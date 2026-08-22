#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N=200010;
struct Point{
    double x,y;
}a[N],b[N];
bool cmp1(const Point&a,const Point&b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

bool cmp2(const Point&a,const Point&b){
    return a.y<b.y;
}

double dis(const Point&a,const Point&b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double devide(int l,int r){
    if(l==r) return 2e9;
    if(l+1==r) return dis(a[l],a[r]);
    int mid=(l+r)>>1;
    double d=min(devide(l,mid),devide(mid+1,r));

    int k=0;
    for(int i=1;i<=r;i++){
        if(fabs(a[i].x-a[mid].x)<d) b[++k]=a[i];
        
    }
    sort(b+1,b+1+k,cmp2);
    for(int i=1;i<k;i++){
        for(int j=i+1;j<=k&&b[j].y-b[i].y<d;j++){
            d=min(d,dis(b[i],b[j]));
        }
    }
    return d;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmp1);
    printf("%.4lf\n",devide(1,n));
    return 0; 
}
