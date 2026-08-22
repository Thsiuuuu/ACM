#include <bits/stdc++.h>
using namespace std;
/*

    令dp[i][2]表示 1~i位置之间的木材一定运送完了，然后i位置修建第二个木厂
    首先，可以从第二个仓库的位置出发，然后进行一次dp
    但是非常逆天的是第一个仓库的位置是不需要进行状态转移的，只需要进行前缀和即可求出
    所以说先计算出第一个仓库的位置的费用，然后进行第二个仓库位置的dp
    然后再分别枚举dp[i][2]+(i+1~n)范围的木材运送价价值之和的最小值即可
*/
#define ll long long
#define i128 __int128_t 
constexpr int N=2e5+10;

int n;
ll a[N],b[N],d[N],D[N],w[N],fi1[N],L[N],LK[N];

using db = ll; //此处可根据题目需要改为double, longlong, 以及自定义的分数类
#define cross(p1, p2, p3) ((i128)(p2.x - p1.x) * (p3.y - p1.y) - (i128)(p3.x - p1.x) * (p2.y - p1.y)) // 向量p1p2与p2p3的叉积

namespace SO{
    // X(j)单调性、求解的时max还是min; 1表示单增/max(上凸壳)，0表示单减/min(下凸壳)
    const bool dx=1,dm=0;
    const int initClock(){
        // 凸壳旋转的方向，取决于x的单调性和维护的上/下凸壳（最大/小值）
        if(dm) return !dx;
        else   return dx;
    }
    const bool dc=initClock();  // 凸壳旋转的方向，1表示逆时针，0表示顺时针

    db f[N];
    struct P{
        db x,y;
        P(){}
        P(db x,db y):x(x),y(y){}
        P operator-(P p){return {x-p.x,y-p.y};}
        db det(P p){return x*p.y-y*p.x;}//叉积
    };
    deque<P> Q;
    db K(int i){return D[i];}
    db X(int j){return a[j];}
    db Y(int j){return fi1[j]+b[j];}
    db A(int i){return b[i]-D[i]*a[i];}
    db B(int i){return Q.front().y-K(i)*Q.front().x;}

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
        if(dc) return k.det(Q[1]-Q[0])<=0;//叉积为负，则是顺时针
        else return k.det(Q[1]-Q[0])>=0;
    }

    db query(int i){
        P k(1,K(i));
        while(Q.size()>=2&&checkFront(k)){
            Q.pop_front();
        }
        return B(i)-A(i);
    }

    db run(int n){
        update(0);
        for(int i=1;i<=n;i++){
            f[i]=query(i);
            update(i);
        }
        ll mn=INT64_MAX;
        for(int i=0;i<=n;i++){
            mn=min(mn,f[i]+LK[i+1]);
        }
        return mn;
    }
}
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>d[i];
        if(i==n){
            D[i]=d[i];
        }
    }

    for(int i=1;i<=n;i++){
        D[i]=D[i-1]+d[i-1];
        a[i]=a[i-1]+w[i];
        b[i]=b[i-1]+w[i]*D[i];
        fi1[i]=D[i]*a[i]-b[i];
    }
    for(int i=n;i>=0;i--){
        L[i]=L[i+1]+d[i];
        LK[i]=LK[i+1]+w[i]*L[i];
    }
    cout<<SO::run(n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}