#include <bits/stdc++.h>
using namespace std;
#define double long double

/*

    Andrew算法求凸包，然后检测每个点是不是在凸包里面就可以了

    凸包性质：凸包用最小的周长围住了所有的点

*/

const double eps=1e-9;
struct Point{
    double x,y;
    Point(double x_=0,double y_=0):x(x_),y(y_){

    }
    Point operator+(const Point&other)const{
        return Point{x+other.x,y+other.y};
    }
    Point operator-(const Point&other)const{
        return Point{x-other.x,y-other.y};
    }
    double operator*(const Point&other)const{
        return x*other.x+y*other.y;
    }
    double operator%(const Point&other)const{
        return x*other.y-other.x*y;
    }
};
int n,m,top;
vector<Point> p,s;

double cross(Point a,Point b,Point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int dcmp(double x){
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}

bool OnSegment(Point P1,Point P2,Point Q){
    return (dcmp((P1-Q)%(P2-Q))==0&&dcmp((P1-Q)*(P2-Q))<=0);
}//判断点是否在线上

bool InPolygon(Point P){
    bool flag=false;
    Point P1,P2;//遍历每一条边，找交点，如果检查的点处在一条边的两个点之间，就继续判断，同时排除平行边
    for(int i=1,j=top-1;i<=top-1;j=i++){
        P1=s[i],P2=s[j];
        if(OnSegment(P1,P2,P)) return false;
        if((dcmp(P1.y-P.y)>0!=dcmp(P2.y-P.y)>0)&&(dcmp(P.x-(P.y-P1.y)*(P1.x-P2.x)/(P1.y-P2.y)-P1.x)<0)){
            flag=!flag;
        }//前者检查点处在一条边的两个点之间，同时排除平行边，只计算相邻边交点一次。后者判断检查的点是否在交点的左侧
    }
    return flag;
}

double dis(Point a,Point b){ //距离
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(Point a, Point b){ //比较
    return a.x!=b.x ? a.x<b.x : a.y<b.y;  
}
void Andrew(){
    top=0;
    sort(p.begin()+1,p.begin()+n+1,cmp); //排序
    for(int i=1; i<=n; i++){ //下凸包
        while(top>1&&cross(s[top-1],s[top],p[i])<=0)top--;
        s[++top]=p[i];
    }
    int t=top;
    for(int i=n-1; i>=1; i--){ //上凸包
        while(top>t&&cross(s[top-1],s[top],p[i])<=0)top--;
        s[++top]=p[i];
    }

    
    // if(top>1) top--;
    // double res=0; //周长
    // for(int i=1; i<top; i++) res+=dis(s[i],s[i+1]);
    // return res;
}

void sol(){

    cin>>n>>m;
    p.assign(n+2,Point());
    s.assign(n+2,Point());
    vector<Point> city(m+1);
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    for(int i=1;i<=m;i++){
        cin>>city[i].x>>city[i].y;
    }
    Andrew();
    int mnidx=1;
    double mnx=s[1].x,mny=s[1].y;
    for(int i=2;i<=top;i++){
        if(mnx>s[i].x){
            mnx=s[i].x,mny=s[i].y;
            mnidx=i;
        }else if(dcmp(mnx-s[i].x)==0&&mny<s[i].y){
            mnx=s[i].x,mny=s[i].y;
            mnidx=i;
        }
    }

    for(int i=mnidx,cnt=0;cnt<top;i++,cnt++){
        if(i==top){
            i=1;
        }
        cout<<(int)s[i].x<<" "<<(int)s[i].y<<'\n';
    }
    for(int i=1;i<=m;i++){
        cout<<(int)city[i].x<<" "<<(int)city[i].y<<" is ";
        if(InPolygon(city[i])) cout<<"unsafe!\n";
        else cout<<"safe!\n";
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        cout<<"Case "<<test<<'\n';
        sol();
    }
  
    return 0;
}