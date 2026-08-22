#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
using db = ll; //此处可根据题目需要改为double, longlong, 以及自定义的分数类
#define cross(p1, p2, p3) ((i128)(p2.x - p1.x) * (p3.y - p1.y) - (i128)(p3.x - p1.x) * (p2.y - p1.y)) // 向量p1p2与p2p3的叉积
const int N=2e5+10;
ll h[N],c;
int m;
namespace SO{
    // X(j)单调性、求解的时max还是min; 1表示单增/max(上凸壳)，0表示单减/min(下凸壳),dk0/1表示从小到大/从大到小
    const bool dx=0,dm=0,dk=0;
    const int initClock(){
        // 凸壳旋转的方向，取决于x的单调性和维护的上/下凸壳（最大/小值）
        if(dm) return !dx;
        else   return dx;
    }
    const bool dc=initClock();  // 凸壳旋转的方向，1表示逆时针，0表示顺时针

    vector<db> f;
    struct P{
        db x,y;
        P(){}
        P(db x,db y):x(x),y(y){}
        P operator-(P p){return {x-p.x,y-p.y};}
        db det(P p){return x*p.y-y*p.x;}//叉积
    };
    deque<P> Q;
    db K(int i){return 2*h[i];}
    db X(int j){return h[j];}
    db Y(int j){return f[j]+h[j]*h[j];}
    db A(int i){return -h[i]*h[i]-c;}
    db B(int i){return Q.front().y-K(i)*Q.front().x;}//把这个当成等号左边那一坨

    bool checkBack(P &p){
        //  跟原本凸包旋转方向相反，则是上/下凸点
        if(dc) return cross(Q[Q.size()-2],Q.back(),p)<=0;//逆时针
        else return cross(Q[Q.size()-2],Q.back(),p)>=0;//顺时针
    }

    void update(int i){
        P p(X(i),Y(i)); 
        while(Q.size()>=2&&checkBack(p)){
            Q.pop_back();
        }
        Q.push_back(p);
    }

    bool checkFront(P &k){
        // k转到头部向量，和原本凸包旋转方向相反
        if(dk==dc){
            if(dm)  return k.det(Q[1]-Q[0])>=0;
            else return k.det(Q[1]-Q[0])<=0;//叉积为负，则是顺时针
        }
        else {
            int siz=Q.size();
            if(dm)  return k.det(Q[siz-2]-Q[siz-1])>=0;
            else return k.det(Q[siz-2]-Q[siz-1])<=0;
        }
    }

    db query(int i){
        P k(1,K(i));
        while(Q.size()>=2&&checkFront(k)){
            if(dk==dc)   Q.pop_front();
            else Q.pop_back();
        }
        if(dk==dc)   return Q.front().y-K(i)*Q.front().x-A(i);
        else return Q.back().y-K(i)*Q.back().x-A(i);
    }

    db run(){
        f.resize(m+1,1e18);
        f[m]=0;
        update(m);
        for(int j=m-1;j>=1;j--){
            f[j]=query(j);
            update(j);
        }
        return f[1];
    }
}
void sol() {
    cin>>m>>c;
    for(int i=1;i<=m;i++) cin>>h[i];
    cout<<SO::run();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}