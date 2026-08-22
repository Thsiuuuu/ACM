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
int sign(ll x){
    if(x>0) return 1;
    if(x<0) return -1;
    return 0;
}
int dcmp(ll x,ll y){
    return sign(x-y);
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

    friend Point operator*(Point a, ll b) {
        return Point(a.x * b, a.y * b);
    }

    friend Point operator*(double a, Point b) {
        return Point(b.x * a, b.y * a);
    }

    friend ll operator*(Point a, Point b) {
        return a.x * b.x + a.y * b.y;
    }

    friend bool operator==(Point a, Point b) {
        return (!sign(a.x - b.x) && !sign(a.y - b.y));
    }

    friend bool operator!=(Point a, Point b) {
        return !(a == b);
    }

    // 用%代表叉乘,因为 ^ 优先级太低了
    friend ll operator%(Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }

    double ddis() { return x * x + y * y; }

    double dis() { return sqrt(x * x + y * y); }
};
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

};

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
        double area = 0;

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

// 判断点是否在线段上（包括端点）
template<class T>
bool isPAtS(Seg<T> a, Point<T> b) {
    Point<T> p1 = a.p1 - b;
    Point<T> p2 = a.p2 - b;
    if (sign(p1 % p2) == 0 && sign(p1 * p2) <= 0) return true;
    return false;
}

template<class T>
int isPointInConvexPolygon(
    const std::vector<Point<T>>& convex,
    const Point<T>& p
) {
    const int n = static_cast<int>(convex.size());

    if (n == 0) return 0;
    if (n == 1) return convex[0] == p ? 1 : 0;
    if (n == 2) return isPAtS(Seg<T>(convex[0], convex[1]), p) ? 1 : 0;

    const Point<T>& origin = convex[0];

    // 后续算法按逆时针顺序处理。若输入为顺时针，则通过下标映射反向访问，
    // 无需复制或修改原凸包。
    const bool inputIsCCW =
        sign((convex[1] - origin) % (convex[n - 1] - origin)) > 0;

    auto getPoint = [&](int i) -> const Point<T>& {
        return inputIsCCW ? convex[i] : convex[n - i];
    };

    const Point<T>& first = getPoint(1);
    const Point<T>& last = getPoint(n - 1);
    const int leftSide = sign((first - origin) % (p - origin));
    const int rightSide = sign((last - origin) % (p - origin));

    // p 不在由 origin->first 和 origin->last 构成的扇形内。
    if (leftSide < 0 || rightSide > 0) return 0;

    // 单独判断扇形的两条边，避免把它们延长线上的点误判为边界点。
    if (leftSide == 0)
        return isPAtS(Seg<T>(origin, first), p) ? 1 : 0;
    if (rightSide == 0)
        return isPAtS(Seg<T>(origin, last), p) ? 1 : 0;

    // 二分找到 p 所在的扇形三角形：origin、getPoint(left)、getPoint(right)。
    int left = 1, right = n - 1;
    while (right - left > 1) {
        const int mid = (left + right) >> 1;
        if (sign((getPoint(mid) - origin) % (p - origin)) >= 0)
            left = mid;
        else
            right = mid;
    }

    const int side = sign(
        (getPoint(right) - getPoint(left)) % (p - getPoint(left))
    );

    if (side < 0) return 0;
    if (side == 0) return 1;
    return 2;
}
void sol() {
    int n,m,q;cin>>n>>m>>q;
    vector<Point<ll>> a,b;
    for(int i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        a.push_back({x,y});
    }
    for(int i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        b.push_back({-x,-y});
    }
    andrew(a);
    andrew(b);
    vector<Point<ll>> c=minkowskiSum(a,b);
    while(q--){
        ll x,y;cin>>x>>y;
        cout<<(isPointInConvexPolygon(c,{x,y})?1:0)<<'\n';
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