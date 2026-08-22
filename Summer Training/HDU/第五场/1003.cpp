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
const ll mod=998244353;
istream& operator>>(istream& in, i128& x) {
    string s;
    in >> s;

    x = 0;
    bool neg = false;

    int start = 0;
    if (s[0] == '-') {
        neg = true;
        start = 1;
    }

    for (int i = start; i < (int)s.size(); i++) {
        x = x * 10 + (s[i] - '0');
    }

    if (neg) x = -x;

    return in;
}
ostream& operator<<(ostream& out, i128 x) {
    if (x == 0) return out << 0;

    if (x < 0) {
        out << '-';
        x = -x;
    }

    string s;
    while (x) {
        s += char('0' + x % 10);
        x /= 10;
    }

    reverse(s.begin(), s.end());
    return out << s;
}
int sign(i128 x){
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}
template<class T>
struct Point {
    T x, y;
    bool t=false;
    Point(T a = 0, T b = 0) : x(a), y(b) {}

    friend Point operator+(Point a, Point b) {
        return Point(a.x + b.x, a.y + b.y);
    }

    friend Point operator-(Point a, Point b) {
        return Point(a.x - b.x, a.y - b.y);
    }

    friend Point operator/(Point a, i128 b) {
        return Point(a.x / b, a.y / b);
    }

    friend Point operator*(Point a, i128 b) {
        return Point(a.x * b, a.y * b);
    }

    friend Point operator*(i128 a, Point b) {
        return Point(b.x * a, b.y * a);
    }

    friend i128 operator*(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    friend bool operator==(Point a, Point b) {
        return (!sign(a.x - b.x) && !sign(a.y - b.y));
    }

    friend bool operator!=(Point a, Point b) {
        return !(a == b);
    }

    // 用%代表叉乘,因为 ^ 优先级太低了
    friend i128 operator%(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

};
template<class T>
struct Seg {
    Point<T> p1, p2;
    int i,j;
    Seg() {}

    Seg(int i,int j,Point<T> a, Point<T> b) : i(i),j(j),p1(a), p2(b) {}

    friend double operator*(Seg a, Seg b) {
        return (a.p2 - a.p1) * (b.p2 - b.p1);
    }

    friend double operator%(Seg a, Seg b) {
        return (a.p2 - a.p1) % (b.p2 - b.p1);
    }

    friend bool operator==(Seg a, Seg b) {
        return (a.p1 == b.p1 && a.p2 == b.p2) || (a.p1 == b.p2 && a.p2 == b.p1);
    }

    void swap() {
        std::swap(p1, p2);
    }

};
void sol() {
    int n;cin>>n;
    vector<Point<i128>> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y>>p[i].t;
    }
    sort(p.begin(),p.end(),[](const Point<i128>&a,const Point<i128>&b)->bool{
        if(a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
    });
    vector<Seg<i128>> edge;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].t==p[j].t) continue;
            edge.push_back(Seg(i,j,p[i],p[j]));
        }   
    }
    sort(edge.begin(),edge.end(),[](const Seg<i128>&a,const Seg<i128>&b)->bool{
        auto [adx,ady,t1]=a.p2-a.p1;
        auto [bdx,bdy,t2]=b.p2-b.p1;
        return atan2l(ady,adx)<atan2l(bdy,bdx);
    });
    VLL low(n,VL(n)),up;up=low;
    for(int i=0;i<n;i++){
        low[i][i]=up[i][i]=1;
    }
    for(const auto&[x,y,u,v]:edge){
        for(int s=0;s<=u;s++){
            low[s][v]+=low[s][u];
            low[s][v]%=mod;
        }
    }   
    for(auto it=edge.rbegin();it!=edge.rend();it++){
        auto [x,y,u,v]=*it;
        for(int s=0;s<=u;s++){
            up[s][v]+=up[s][u];
            up[s][v]%=mod;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans+=low[i][j]*up[i][j]%mod;
            ans%=mod;
            if(p[i].t!=p[j].t){
                ans=(ans-1+mod)%mod;
            }
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}