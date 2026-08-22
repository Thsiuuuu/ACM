#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int N = 4e6 + 10, M = 1e3 + 10;
const double PI = acos(-1);

int T, n, m;

struct Complex
{
    double x, y;
    Complex operator+(const Complex &t) const
    {
        return {x + t.x, y + t.y};
    }
    Complex operator-(const Complex &t) const
    {
        return {x - t.x, y - t.y};
    }
    Complex operator*(const Complex &t) const
    {
        return {x * t.x - y * t.y, x * t.y + y * t.x};
    }

} a[N], b[N];

int rev[N], bit, tot, res[N];
void fft(Complex a[], int inv)
{
    for (int i = 0; i < tot; i++)
    {
        if (i < rev[i])
            swap(a[i], a[rev[i]]); //只需要交换一次就行了，交换两次等于没有换
    }
    for (int mid = 1; mid < tot; mid <<= 1)
    {
        auto w1 = Complex({cos(PI / mid), inv * sin(PI / mid)});
        for (int i = 0; i < tot; i += mid * 2)
        {
            auto wk = Complex({1, 0});                  //初始为w(0,mid),定义为w(k,mid)
            for (int j = 0; j < mid; j++, wk = wk * w1) //单位根递推式
            {
                auto x = a[i + j], y = wk * a[i + j + mid];
                a[i + j] = x + y, a[i + j + mid] = x - y;
            }
        } 
    }
}

void workFFT(int n, int m)
{// a[0, n], b[0, m]
    while ((1 << bit) < n + m + 1)
        bit++;
    tot = 1 << bit;
    for (int i = 0; i < tot; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    //递推(bit<<1)在bit之前，就已经被算出rev,最后一位是否为1
    fft(a, 1), fft(b, 1);
    for (int i = 0; i < tot; i++)
        a[i] = a[i] * b[i]; //点表示法直接运算
    fft(a, -1);//逆变换，点表示法转换为多项式表示法
    for (int i = 0; i <= n + m; i++)
        res[i]  = (int)(a[i].x / tot + 0.5); //向上去整
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        cin >> a[i].x;
    for (int i = 0; i <= m; i++)
        cin >> b[i].x;
    workFFT(n, m);
    for (int i = 0; i <= n + m; i++)
        cout << res[i] << ' ';
}