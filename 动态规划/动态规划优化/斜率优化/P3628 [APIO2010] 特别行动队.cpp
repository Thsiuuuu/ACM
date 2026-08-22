#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long  
#define i128 __int128_t
#define db ll
const int N=1e6+3;
ll S[N],a,b,c;
int n;
#define cross(p1, p2, p3) ((i128)(p2.x - p1.x) * (p3.y - p1.y) - (i128)(p3.x - p1.x) * (p2.y - p1.y)) 

namespace SO{
    const bool dx=1,dm=1;
    const int initClock(){
        if(dm) return !dx;
        else return dx;
    }
    const bool dc=initClock();

    db dp[N];
    struct P{
        db x,y;
        P(){}
        P(db x,db y):x(x),y(y){}
        P operator-(P p){return {x-p.x,y-p.y};}
        db det(P p){return x*p.y-y*p.x;}
    };
    
    deque<P> Q;
    db K(int i){return 2*a*S[i];}
    db X(int j){return S[j];}
    db Y(int j){return dp[j]+a*S[j]*S[j]-b*S[j]+c;}
    db A(int i){return -(b*S[i]+a*S[i]*S[i]);}
    db B(int i){return Q.front().y-K(i)*Q.front().x;}

    bool checkBack(P &p){
        if(dc) return cross(Q[Q.size()-2],Q.back(),p)<=0;
        else return cross(Q[Q.size()-2],Q.back(),p)>=0;
    }

    void update(int i){
        P p(X(i),Y(i));
        while(Q.size()>=2&&checkBack(p)){
            Q.pop_back();
        }
        Q.push_back(p);
    }

    bool checkFront(P &k){
        if(dc) return k.det(Q[1]-Q[0])<=0;
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
            dp[i]=query(i);
            update(i);
        }
        return dp[n];
    }
}

void sol() {
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++){
        cin>>S[i];
        S[i]+=S[i-1];
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