#include <bits/stdc++.h>
using namespace std;

/*

    和P2365任务安排式子一样，但是斜率不具有单调性
    斜率优化当中队首是基于单调性维护的，队尾是用来维护凸壳的，所以说队首不能出队
    因为取截距最小值的点具有单调性，在该题中表现为在该点右侧邻接点连成的向量均在i位置斜率对应直线逆时针方向，所以说可以通过叉积进行二分出最后一个符合位置的点，即为最小值点


*/

typedef long long LL;
#define i128 __int128_t
constexpr int N = 3e5 + 10;

int T, n, m;
LL S, sumF[N], sumT[N];

using db = LL; //此处可根据题目需要改为double, longlong, 以及自定义的分数类
#define cross(p1, p2, p3) ((i128)(p2.x - p1.x) * (p3.y - p1.y) - (i128)(p3.x - p1.x) * (p2.y - p1.y)) // 三个点p1p2与p2p3的叉积
namespace SO //斜率优化
{
    // K(i)、X(j)单调性、求解的时max还是min; 1表示单增/max(上凸壳)，0表示单减/min(下凸壳)
    const bool dk = 1, dx = 1, dm = 0;
    const int initClock()
    { // 凸壳旋转的方向，取决于x的单调性和维护的上/下凸壳（最大/小值）
        if (dm) // 上凸壳
            return !dx;
        else // 下凸壳
            return dx;
    }
    const bool dc = initClock(); // 凸壳旋转的方向，1表示逆时针，0表示顺时针

    db dp[N];
    struct P
    {
        db x, y;
        P() {}
        P(db x, db y) : x(x), y(y) {}
        P operator-(P p) { return {x - p.x, y - p.y}; }
        db det(P p) { return x * p.y - y * p.x; } // 叉积
    };
    deque<P> Q;
    
    // Y(j) = K(i)X(j) + B(i), B(i) = dp[i] + A(i)
    db K(int i){ return sumT[i] + S;}
    db X(int j){ return sumF[j];}
    db Y(int j){ return dp[j];}
    db A(int i){ return -sumT[i] * sumF[i] - S * sumF[n];}
    db B(int i, int pos){ return Q[pos].y - K(i) * Q[pos].x;}

    bool checkBack(P &p)
    { //  跟原本凸包旋转方向相反，则是上/下凸点
        if (dc) // 逆时针
            return cross(Q[Q.size() - 2], Q.back(), p) <= 0;
        else // 顺时针
            return cross(Q[Q.size() - 2], Q.back(), p) >= 0;
    }

    void update(int i)
    {
        P p(X(i), Y(i));
        while (Q.size() >= 2 && checkBack(p))
            Q.pop_back();
        Q.push_back(p);
    }

    bool check(P &k, P q)
    { // 和原本凸包旋转方向相同，则合法
        if (dc) // 逆时针
            return k.det(q) >= 0; //叉积为正，则是逆时针
        else // 顺时针
            return k.det(q) <= 0;
    }

    db query(int i)
    {
        P k(1, K(i)); // 斜率对应的向量
        int res = Q.size() - 1; //最后一个点一定是合法点
        int l = 0, r = Q.size() - 2;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(check(k, Q[mid + 1] - Q[mid]))
            {// Q[mid] -> Q[mid + 1]这个向量合法
                res = mid;
                r = mid - 1;
            }
            else 
                l = mid + 1;
        }
        return B(i, res) - A(i);
    }

    db run(int n)
    {
        update(0);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = query(i);
            update(i);
        }
        return dp[n];
    }
}

int main()
{
    cin >> n >> S;
    int t, f;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> f;
        sumT[i] = sumT[i - 1] + t;
        sumF[i] = sumF[i - 1] + f;
    }
    cout << SO::run(n);
}