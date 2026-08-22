#include <bits/stdc++.h>
using namespace std;
/*

    最开始按人数不可以，改为按时间dp

*/
#define ll long long
#define i128 __int128_t 
constexpr int N=4e6+200;

int n,m;
ll sum[N],cnt[N];
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

    db dp[N];
    struct P{
        db x,y;
        P(){}
        P(db x,db y):x(x),y(y){}
        P operator-(P p){return {x-p.x,y-p.y};}
        db det(P p){return x*p.y-y*p.x;}//叉积
    };
    deque<P> Q;
    db K(int i){return i;}
    db X(int j){return cnt[j];}
    db Y(int j){return dp[j]+sum[j];}
    db A(int i){return -i*cnt[i]+sum[i];}
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

    db run(int R,int mx){
        for(int i=m;i<=R;i++){
            update(i-m);
            dp[i]=query(i);
        }
        return *min_element(dp+mx,dp+R+1);
    }
}
void sol() {
    cin>>n>>m;
    int t,mx=-1;
    for(int i=1;i<=n;i++){
        cin>>t;
        t+=m;
        mx=max(mx,t);
        ++cnt[t];
        sum[t]+=t;
    }

    int R=mx+m-1;

    for(int i=1+m;i<=R;i++){
        cnt[i]+=cnt[i-1];
        sum[i]+=sum[i-1];
    }
    cout<<SO::run(R,mx);
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