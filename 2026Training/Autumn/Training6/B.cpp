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

const ld PI =acos(-1.0L);
const int M=250003;
// const ld eps=1e-9;
int cb[M+10];
// ld ans[M+10];
ll ans[M+10];
struct Complex
{
    ld x, y;
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

} q[1<<19],B[1<<19],B2[1<<19],p[1<<19],A[1<<19],A2[1<<19];

int rev[M<<2], bit, tot,pos[M+10];
void fft(Complex a[], int inv)
{
    for (int i = 0; i < tot; i++)
    {
        if (i < rev[i])
            swap(a[i], a[rev[i]]); //只需要交换一次就行了，交换两次等于没有换
    }
    for (int mid = 1; mid < tot; mid <<= 1)
    {
        auto w1 = Complex({cosl(PI / mid), inv * sinl(PI / mid)});
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
// void workFFT(ld *res,Complex* fa,Complex* fb)
// {// a[0, n], b[0, m]
//     //递推(bit<<1)在bit之前，就已经被算出rev,最后一位是否为1
//     for(int i=0;i<tot;i++) a[i]=b[i]=Complex{0,0};
//     for(int i=0;i<=M;i++){
//         a[i]=fa[i],b[i]=fb[i];
//     }
//     fft(a, 1), fft(b, 1);
//     for (int i = 0; i < tot; i++)
//         a[i] = a[i] * b[i]; //点表示法直接运算
//     fft(a, -1);//逆变换，点表示法转换为多项式表示法
//     for (int i = 0; i <=2*M-6; i++)
//         res[i]  = a[i].x/tot;
// }
// void update(){
//     for(int i=0;i<=M;i++) sum[i]=0;
// }
// void add(int op){
//     for(int i=0;i<=M;i++) sum[i]+=op*res[M-i];
// }
void sol() {
    int n,Q;cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>pos[i];
        cin>>cb[pos[i]];
    }
    for(int i=1;i<=n;i++){
        int x=pos[i];
        ld c=cb[x];
        q[M-x].x=1,B[M-x].x=c,B2[M-x].x=c*c;
    }
    while ((1 << bit) < 2*M )
        bit++;
    tot = 1 << bit;
    for (int i = 0; i < tot; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));

    fft(q,1);
    fft(B,1);
    fft(B2,1);
    for(int i=1;i<=n;i*=3){
        int L=i,R=min(n+1,L*3);
        fill(p,p+tot,Complex{0,0});
        fill(A,A+tot,Complex{0,0});
        fill(A2,A2+tot,Complex{0,0});
        for(int j=L;j<R;j++){
            int x=pos[j];
            ld c=cb[x];
            p[x].x=1,A[x].x=c,A2[x].x=c*c;
        }
        fft(p, 1);
        fft(A, 1);
        fft(A2, 1);
        for (int k = 0; k < tot; k++)
        {
            Complex t1 = A2[k] * q[k];
            Complex t2 = A[k] * B[k];
            Complex t3 = p[k] * B2[k];

            t2.x *= 2;
            t2.y *= 2;

            A2[k] = t1 - t2 + t3;
        }
        fft(A2,-1);
        for(int d=1;d<=M;d++){
            if(ans[d]>0) continue;
            ld val = A2[M - d].x / tot;
            if(llroundl(val)>0) ans[d]=3*L;
        }
    }
    for(int i=0;i<Q;i++){
        int x;cin>>x;
        cout<<(ans[x]*1.0)/2<<'\n';
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