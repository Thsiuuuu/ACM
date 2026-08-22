#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
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
const double EPS = 1e-8;
const ll mod=998244353;
ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
ll inv2=ksm(2,mod-2);
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
template <class T>
int sign(T x) {
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}

int dcmp(double val1, double val2) {
    return sign(val1 - val2);
}
template<class T>
struct Point {
    T x, y;

    Point(T a = 0, T b = 0) : x(a), y(b) {}

    friend Point operator+(Point a, Point b) {
        return Point(a.x + b.x, a.y + b.y);
    }

    friend Point operator-(Point a, Point b) {
        return Point(a.x - b.x, a.y - b.y);
    }

    friend Point operator/(Point a, double b) {
        return Point(a.x / b, a.y / b);
    }

    friend Point operator*(Point a, double b) {
        return Point(a.x * b, a.y * b);
    }

    friend Point operator*(double a, Point b) {
        return Point(b.x * a, b.y * a);
    }

    friend T operator*(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    friend bool operator==(Point a, Point b) {
        return (!sign(a.x - b.x) && !sign(a.y - b.y));
    }

    friend bool operator!=(Point a, Point b) {
        return !(a == b);
    }

    // 用%代表叉乘,因为 ^ 优先级太低了
    friend T operator%(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    double ddis() { return x * x + y * y; }

    double dis() { return sqrt(x * x + y * y); }
};
const Point<double> INFP(1e20, 1e20);

// 点到点的距离
template<class T>
double dis(Point<T> a, Point<T> b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// 点到点的距离（不开方）
template<class T>
double ddis(Point<T> a, Point<T> b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
template<class T>
struct Seg {
    Point<T> p1, p2;

    Seg() {}

    Seg(Point<T> a, Point<T> b) : p1(a), p2(b) {}

    friend double operator*(Seg a, Seg b) {
        return (a.p2 - a.p1) * (b.p2 - b.p1);
    }

    friend double operator%(Seg a, Seg b) {
        return (a.p2 - a.p1) % (b.p2 - b.p1);
    }

    friend double operator%(Seg a, Point<T> b) {
        return (a.p2 - a.p1) % (b - a.p1);
    }

    friend double operator%(Point<T> a, Seg b) {
        return (a - b.p1) % (b.p2 - b.p1);
    }

    friend bool operator==(Seg a, Seg b) {
        return (a.p1 == b.p1 && a.p2 == b.p2) || (a.p1 == b.p2 && a.p2 == b.p1);
    }

    void swap() {
        std::swap(p1, p2);
    }

    double len() { return dis(p1, p2); }
};

// 点到直线距离
template<class T>
double calPSDis1(Seg<T> a, Point<T> b) {
    return std::abs((a.p2 - a.p1) % (b - a.p1)) / a.len();
}

// 点到线段距离
template<class T>
double calPSDis2(Seg<T> a, Point<T> b) {
    int res1 = sign((b - a.p1) * (a.p2 - a.p1));
    int res2 = sign((b - a.p2) * (a.p1 - a.p2));
    if (res1 >= 0 && res2 >= 0) {
        return calPSDis1(a, b);
    }
    return std::min(dis(a.p1, b), dis(a.p2, b));
}

// 求点到线段/直线的垂足
template<class T>
Point<T> calPSFeet(Seg<T> a, Point<T> b) {
    auto vec = a.p2 - a.p1;
    return a.p1 + vec * ((b - a.p1) * vec) / (vec.x * vec.x + vec.y * vec.y);
}

// 计算线段及其延长线/直线的交点
template<class T>
Point<T> calSegCross(Seg<T> a, Seg<T> b) {
    auto res1 = (a.p2 - a.p1) % (b.p1 - a.p1);
    auto res2 = (a.p2 - a.p1) % (b.p2 - a.p1);
    auto x = (res2 * b.p1.x - res1 * b.p2.x) / (res2 - res1);
    auto y = (res2 * b.p1.y - res1 * b.p2.y) / (res2 - res1);
    return Point<T>(x, y);
}

// 判断点是否在线段上（包括端点）
template<class T>
bool isPAtS(Seg<T> a, Point<T> b) {
    Point<T> p1 = a.p1 - b;
    Point<T> p2 = a.p2 - b;
    if (sign(p1 % p2) == 0 && sign(p1 * p2) <= 0) return true;
    return false;
}

// 判断线段是否相交
template<class T>
bool isSegCross(Seg<T> a, Seg<T> b) {
    double c1 = (a.p2 - a.p1) % (b.p1 - a.p1), c2 = (a.p2 - a.p1) % (b.p2 - a.p1);
    double c3 = (b.p2 - b.p1) % (a.p1 - b.p1), c4 = (b.p2 - b.p1) % (a.p2 - b.p1);

    // 允许线段在端点处相交则添加
    if (!sign(c1) || !sign(c2) || !sign(c3) || !sign(c4)) {
        bool f1 = isPAtS(a, b.p1);
        bool f2 = isPAtS(a, b.p2);
        bool f3 = isPAtS(b, a.p1);
        bool f4 = isPAtS(b, a.p2);
        bool f = (f1 | f2 | f3 | f4);
        return f;
    }
    return (sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0);
}
// 多边形面积(凹凸都可以)
template<class T>
i128 calPolygonArea(
    const std::vector<Point<T>>& point,
    int n
) {
    i128 area = 0;
    for (int i = 0; i < n; i++)
        area += (point[i] % point[(i + 1) % n])%mod;
        while(area<0)  area+=mod;
        area%=mod;
    return area%mod;
}
// 计算平面最近点对欧式距离
template<class T>
double calPointMinDis(
    int l,
    int r,
    const std::vector<Point<T>>& point,
    std::vector<int>& t
) {
    /*
    开始递归前先按照 x 排序
    std::sort(point, point + n, [&](const Point &p1, const Point &p2) {
        return p1.x < p2.x;
    });
    */
    if (r - l == 0)
        return 1e15;
    if (r - l == 1)  // 如果递归完后直接输出距离
        return dis(point[l], point[r]);
    int mid = (l + r) >> 1;
    double ans = std::min(calPointMinDis(l, mid, point, t),
                         calPointMinDis(mid + 1, r, point, t));
    int cnt = 0;
    for (int i = l; i <= r; i++)
        // 还有一种情况是距离最小的两点刚好分在 mid 两端 ans 距离内的点
        if (point[i].x >= point[mid].x - ans && point[i].x <= point[mid].x + ans)
            t[++cnt] = i;
    std::sort(t.begin() + 1, t.begin() + cnt + 1, [&](int i, int j) {
        return point[i].y < point[j].y;
    }); // 以 y 坐标大小排序
    for (int i = 1; i <= cnt; i++)
        for (int j = i + 1; j <= cnt; j++) {
            if (point[t[j]].y >= point[t[i]].y + ans) break;
            // 两个点的垂直距离超过 ans 就不必计算了，显然不可能会成为新的 ans
            ans = std::min(ans, dis(point[t[i]], point[t[j]]));
        }
    return ans;
}
// Pick 定理：给定顶点均为整点的简单多边形，皮克定理说明了
// 其面积 A 和内部格点数目 i,边上格点数目 b 的关系：
// A = i + b / 2 - 1（没有取整,可能是小数）
// 取格点的组成图形的面积为一单位.在平行四边形格点,皮克定理依然成立。
// 套用于任意三角形格点，皮克定理则是 A = 2 * i + b - 2
template<class T>
std::array<i128, 2> pick(
    int n,
    const std::vector<Point<T>>& point
) {

    i128 sum = 0, num = 0;
    for (int i = 0; i < n; i++) {
        i128 x = std::abs(point[(i + 1) % n].x - point[i].x);
        i128 y = std::abs(point[(i + 1) % n].y - point[i].y);
        num += std::__gcd(abs(x), abs(y));
        num%=mod;
        sum += point[(i + 1) % n] % point[i];
    }
    return {((abs(sum) - num) / 2 + 1)%mod, num};
}

// andrew 找凸包
template<class T>
int andrew(std::vector<Point<T>>& point) {
    if (point.size() <= 1)
        return point.size();

    // 按照 x、y 排序
    std::sort(
        point.begin(),
        point.end(),
        [](const Point<T>& a, const Point<T>& b) {
            if (a.x != b.x)
                return a.x < b.x;

            return a.y < b.y;
        }
    );

    // 删除完全重复的点
    point.erase(
        std::unique(
            point.begin(),
            point.end(),
            [](const Point<T>& a, const Point<T>& b) {
                return a.x == b.x && a.y == b.y;
            }
        ),
        point.end()
    );

    int n =point.size();

    if (n <= 1)
        return n;

    // 最多临时保存 2n 个点
    std::vector<Point<T>> res(2 * n);

    int m = 0;

    // 求下凸壳
    for (int i = 0; i < n; i++) {
        while (
            m > 1 &&
            sign(
                (res[m - 1] - res[m - 2]) %
                (point[i] - res[m - 2])
            ) <= 0
        ) {
            --m;
        }

        // 如果想保留凸包边上的点，将 <= 0 改成 < 0
        // 最终凸包为逆时针方向
        res[m++] = point[i];
    }

    int k = m;

    // 求上凸壳
    for (int i = n - 2; i >= 0; i--) {
        while (
            m > k &&
            sign(
                (res[m - 1] - res[m - 2]) %
                (point[i] - res[m - 2])
            ) <= 0
        ) {
            --m;
        }

        res[m++] = point[i];
    }

    // 起点被重复记录，删除最后一个点
    --m;
    res.resize(m);

    // 用凸包替换原来的点集
    point = std::move(res);

    return m;
}

// 点c到线段ab的距离
template<class T>
double segdis(Point<T> a,Point<T> b,Point<T> c) {
    return std::abs((b - a) % (c - a)) / dis(a, b);
}

// 旋转卡壳求凸包直径
template<class T>
double rotate(
    int n,
    const std::vector<Point<T>>& res
) {
    // 虽然 n >= 2 时即认为凸包存在，但是旋转卡壳的时候要求 n >= 3
    if (n == 2) return dis(res[1], res[0]);
    int cur = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        while (segdis(res[i], res[(i + 1) % n], res[cur]) <=
               segdis(res[i], res[(i + 1) % n], res[(cur + 1) % n]))
            cur = (cur + 1) % n;
        ans = std::max(ans, dis(res[i], res[cur]));
        ans = std::max(ans, dis(res[(i + 1) % n], res[cur]));
    }
    return ans;
}

// 判断凸包
template<class T>
bool isConvex(
    int n,
    const std::vector<Point<T>>& point
) {
    // 默认为顺时针
    // 如果输入点的方式为逆时针输入,则将 < 改成 >
    // 认为凸包边上可以有 点 则加上 =
    for (int i = 0; i < n; i++) {
        if ((point[i] - point[(i + 1) % n]) % (point[(i + 2) % n] - point[(i + 1) % n]) > 0)
            return false;
    }
    return true;
}

//求两个凸包的闵可夫斯基和
template<class T>
std::vector<Point<T>> minkowskiSum(
    std::vector<Point<T>> a,
    std::vector<Point<T>> b
) {
    auto normalize = [](std::vector<Point<T>>& p) {
        // 删除末尾重复保存的起点
        if (p.size() > 1 && p.front() == p.back())
            p.pop_back();

        if (p.size() <= 1)
            return;

        // 保证凸包按照逆时针排列
        i128 area = 0;

        for (int i = 0; i <p.size(); i++)
            area += p[i] % p[(i + 1) % p.size()];

        if (sign(area) < 0)
            std::reverse(p.begin(), p.end());

        // 将 y 最小、其次 x 最小的点作为起点
        auto it = std::min_element(
            p.begin(),
            p.end(),
            [](const Point<T>& a, const Point<T>& b) {
                if (dcmp(a.y, b.y) == 0)
                    return a.x < b.x;

                return a.y < b.y;
            }
        );

        std::rotate(p.begin(), it, p.end());
    };

    normalize(a);
    normalize(b);

    if (a.empty() || b.empty())
        return {};

    // 一个凸包退化为点
    if (a.size() == 1) {
        for (auto& p : b)
            p = p + a[0];

        return b;
    }

    if (b.size() == 1) {
        for (auto& p : a)
            p = p + b[0];

        return a;
    }

    int n = a.size();
    int m = b.size();

    // 补上循环边需要的点
    a.push_back(a[0]);
    a.push_back(a[1]);

    b.push_back(b[0]);
    b.push_back(b[1]);

    std::vector<Point<T>> res;
    res.reserve(n + m);

    int i = 0;
    int j = 0;

    while (i < n || j < m) {
        res.push_back(a[i] + b[j]);

        bool takeA = false;
        bool takeB = false;

        if (i == n) {
            takeB = true;
        } else if (j == m) {
            takeA = true;
        } else {
            Point<T> edgeA = a[i + 1] - a[i];
            Point<T> edgeB = b[j + 1] - b[j];

            int crossSign = sign(edgeA % edgeB);

            // edgeA 极角更小
            if (crossSign > 0) {
                takeA = true;
            }
            // edgeB 极角更小
            else if (crossSign < 0) {
                takeB = true;
            }
            // 两条边方向相同，同时合并
            else {
                takeA = true;
                takeB = true;
            }
        }

        if (takeA) ++i;
        if (takeB) ++j;
    }

    return res;
}

void sol() {
    int n,m,q;cin>>n>>m>>q;
    vector<Point<i128>> a(n),b(m),na,nb;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].x=-a[i].x,a[i].y=-a[i].y;
    }
    for(int i=0;i<m;i++){
        cin>>b[i].x>>b[i].y;
    }
    vector<Point<i128>> aft;
    andrew(a);
    andrew(b);
    aft=minkowskiSum(a,b);
    n=a.size(),m=b.size();
    i128 sa=calPolygonArea(a,n),sb=calPolygonArea(b,m),sr=calPolygonArea(aft,aft.size());
    while(sr<0) sr+=mod;
    while(sa<0) sa+=mod;
    while(sb<0) sb+=mod;
    sr%=mod,sa%=mod,sb%=mod;
    i128 ba=pick(n,a)[1],bb=pick(m,b)[1];
    i128 c=sr-sa-sb;
    while(c<0) c+=mod;
    c%=mod;
    while(q--){
        i128 k;cin>>k;
        k%=mod;
        i128 s=(sb+k*k%mod*sa%mod)%mod+k*c%mod,bs=bb+ba*k%mod;
        s%=mod;
        bs%=mod;
        cout<<(s+bs+2)%mod*inv2%mod<<'\n';        
    }
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