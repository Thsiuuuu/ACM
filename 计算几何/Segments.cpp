#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

const int N=210;
struct Point{
    double x,y;
};
Point a[N],b[N],p[N];
int n;

/*


    这个题首先可以转化成找到一条直线使得它穿过所有的直线
    然后可以考虑极端情况，如果穿过所有线段，那么这个直线必然经过其中两个线段的端点

    所以可以枚举所有经过端点的直线，然后对于每条直线，再枚举所有线段

*/

const double esp=1e-8;

double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

bool check(){
    for(int i=0;i<n*2;i++){
        for(int j=i+1;j<n*2;j++){
            if(fabs(p[i].x-p[j].x)<=esp&&fabs(p[i].y-p[j].y)<=esp) continue;
            bool flag=true;
            for(int k=0;k<n;k++){
                if(cross(p[i],p[j],a[k])*(cross(p[i],p[j],b[k]))>0){
                    flag=false;
                    break;
                }
            }
            if(flag) return true;
        }
    }
    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
            p[cnt].x=a[i].x,p[cnt++].y=a[i].y;
            p[cnt].x=b[i].x,p[cnt++].y=b[i].y;
        }
        if(check()){
            printf("Yes!\n");
        }else{
            printf("No!\n");
        }
    }
}