#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

/*


    采用了二分查找的方法
    先把边界都建好，通过叉积看看一个点是在这个线的左侧还是右侧
    注意右边界是n+1,因为有可能碰到左侧编号是n的隔板


*/

const int N=5010;
struct Point{
    int x,y;
}a[N],b[N],p;

int n;
int ans[N];
int cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int find(Point p){
    int l=0,r=n+1;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(cross(b[mid],a[mid],p)<=0) l=mid;
        else r=mid;
    }
    return l;
}

signed main(){
    int x1,y1,x2,y2,u,l,m;
    bool num1=1;
    while(scanf("%lld",&n),n){
        scanf("%lld%lld%lld%lld%lld",&m,&x1,&y1,&x2,&y2);
        a[0].x=x1,a[0].y=y1,b[0].x=x1,b[0].y=y2;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld",&u,&l);
            a[i].x=u,a[i].y=y1,b[i].x=l,b[i].y=y2;
        }
        memset(ans,0,sizeof(ans));
        while(m--){
            scanf("%lld%lld",&p.x,&p.y);
            ans[find(p)]++;
        }
        for(int i=0;i<=n;i++){
            printf("%lld: %lld\n",i,ans[i]);
        }
        printf("\n");
    }
    return 0;
}