// Matrix 
// 2000ms, 2048MB

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int _=5005, _m=998244353, INF=0x3f3f3f3f3f3f3f3fLL; mt19937_64 rnd(98275314); int qpow(int a, int b) {int ret=1;while(b) {if(b&1) ret=ret*a%_m;b>>=1; a=a*a%_m;}return ret;}int inv(int a) {return qpow(a, _m-2);}int gcd(int a, int b) {return b==0?a:gcd(b, a%b);}int lcm(int a, int b) {return a/gcd(a, b)*b;}int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m, a[_][_], c[_+_], cnt[_+_], h[_][_];
// void draw() {
//     cout<<"############\n";
//     for(int i=1; i<=n; i++) {
//         for(int j=1; j<=m; j++) {
//             cout<<a[i][j]<<' ';
//         }
//         cout<<'\n';
//     }
//     cout<<"############\n";
// }
void solve() {
    cin>>n>>m;
    for(int i=1; i<=n+m; i++) {
        c[i]=cnt[i]=0;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>a[i][j];
            c[i+j]+=a[i][j];
            cnt[i+j]++;
            h[i][j]=0;
        }
    }
    if(n==1) {
        int t=a[1][1];
        for(int i=1; i<=m; i++) {
            if(a[1][i]!=t) {
                cout<<-1<<'\n'; return;
            }
        }
        cout<<0<<'\n'; return;
    }
    if(m==1) {
        int t=a[1][1];
        for(int i=1; i<=n; i++) {
            if(a[i][1]!=t) {
                cout<<-1<<'\n'; return;
            }
        }
        cout<<0<<'\n'; return;
    }
    int x=c[3]-c[2], __=x-a[1][1];
    for(int i=4; i<=n+m; i++) {
        if(x*cnt[i]-c[i]!=__) {
            cout<<-1<<'\n'; return;
        }
    }
    h[1][1]=__; a[1][1]=x;
    for(int s=2; s<n+m; s++) {
        for(int j=1; j<=m&&s-j>=1&&s-j<=n; j++) {
            int i=s-j;
            // cout<<i<<' '<<j<<'\n';
            if(i==n) {
                // draw();
                if(a[i][j+1]+h[i][j]>x) {
                    cout<<-1<<'\n'; return;
                }
                a[i][j+1]+=h[i][j];
                h[i][j+1]+=h[i][j];
                // draw();
            }
            else if(j==m) {
                if(a[i+1][j]+h[i][j]!=x) {
                    // draw();
                    cout<<-1<<'\n'; return;
                }
                a[i+1][j]+=h[i][j];
                h[i+1][j]+=h[i][j];
            }
            else {
                if(a[i+1][j]>a[i][j]||a[i][j+1]>a[i][j]) {
                    cout<<-1<<'\n'; return;
                }
                if(a[i+1][j]+h[i][j]<x) {
                    // cout<<i<<' '<<j<<'\n';
                    // draw();
                    cout<<-1<<'\n'; return;
                }
                int yu=a[i][j]-a[i+1][j];
                int na=h[i][j]-yu;
                if(na<0) {
                    cout<<-1<<'\n'; return;
                }
                if(a[i][j+1]+na>x) {
                    cout<<-1<<'\n'; return;
                }
                a[i+1][j]+=yu;
                a[i][j+1]+=na;
                h[i+1][j]+=yu;
                h[i][j+1]+=na;
            }
        }
    }
    cout<<__<<'\n';
} //yunayu_2026_target_M

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    // solve();
    int T; cin>>T; while(T--) solve();
    return 0;
} //"只要不失去你的崇高，整个世界都会向你敞开"