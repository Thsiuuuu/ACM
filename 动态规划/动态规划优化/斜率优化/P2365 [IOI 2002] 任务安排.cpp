#include <bits/stdc++.h>
using namespace std;
/*

    用到了费用提前计算的思想
    如果不用需要多开一维去记录有选了几次，但是这个题中费用计算只与当前的行为有关系
    所以说可以提前计算出来费用，枚举的时候也不会漏掉每一种费用的可能性

*/
constexpr int N=5010;
#define ll long long 
using db=ll;
int n;
ll S,sumF[N],sumT[N];
#define cross(p1, p2, p3) ((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y))

namespace SO{
    db dp[N];
    struct P{
        db x,y;
        P(){}
        P(db x_,db y_):x(x_),y(y_){}
        P operator-(P p){return {x-p.x,y-p.y};}
        db det(P p){return x*p.y-y*p.x;}
    };
    deque<P> Q;
    db K(int i){return sumT[i]+S;}
    db X(int j){return sumF[j];}
    db Y(int j){return dp[j];}
    db A(int i){return -sumT[i]*sumF[i]-S*sumF[n];}
    db B(int i){return Q.front().y-K(i)*Q.front().x;}
    
    bool checkBack(P &p){
        return cross(Q[Q.size()-2],Q.back(),p)<=0;
    }

    void update(int i){
        P p(X(i),Y(i));
        while(Q.size()>=2&&checkBack(p)){
            Q.pop_back();
        }
        Q.push_back(p);
    }

    bool checkFront(P &k){
        return (Q[1]-Q[0]).det(k)>=0;
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
            dp[i]=query(i);
            update(i);
        }
        return dp[n];
    }
}

void sol() {
    cin>>n>>S;
    int t,f;
    for(int i=1;i<=n;i++){
        cin>>t>>f;
        sumT[i]=sumT[i-1]+t;
        sumF[i]=sumF[i-1]+f;
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