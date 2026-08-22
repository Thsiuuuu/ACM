// 最遥远的距离 
// 1000ms, 262144MB

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int _=300005, _m=998244353, INF=0x3f3f3f3f3f3f3f3fLL; mt19937_64 rnd(98275314); int qpow(int a, int b) {int ret=1;while(b) {if(b&1) ret=ret*a%_m;b>>=1; a=a*a%_m;}return ret;}int inv(int a) {return qpow(a, _m-2);}int gcd(int a, int b) {return b==0?a:gcd(b, a%b);}int lcm(int a, int b) {return a/gcd(a, b)*b;}int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, a[_], cnt[_], f[_], vis[_];
queue<int> g[_];
void solve() {
    cin>>n;
    int mx=0;
    // for(int i=1;i<=n;i++){
    //     while(g[i].size()) g[i].pop();
    // }
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        g[a[i]].push(i);
        mx=max(mx, a[i]);
        cnt[a[i]]++;
    }
    for(int i=mx; i+i>mx; i--) {
        if(i+i-1==mx) {
            if(cnt[i]!=1) {
                cout<<"No\n"; return;
            }
            cnt[i]-=1;
        }
        else {
            if(cnt[i]<2) {
                cout<<"No\n"; return;
            }
            cnt[i]-=2;
        }
    }
    if(mx%2==0) {
        int sp=mx/2+1;
        if(cnt[sp]!=0) {
            cout<<"No\n"; return;
        }
    }
    for(int i=1; i+i<=n; i++) {
        if(cnt[i]) {
            cout<<"No\n"; return;
        }
    }
    cout<<"Yes\n";
    int cl=mx;
    int u=g[cl].front(); g[cl].pop();
    f[cl]=u;
    vis[u]=1;
    cl--;
    while(cl+cl>mx) {
        int v=g[cl].front();  g[cl].pop();
        cout<<u<<' '<<v<<'\n';
        u=v;
        f[cl]=u;
        vis[u]=1;
        cl--;
    }
    cl++;
    if(mx%2) cl++;
    while(cl<=mx) {
        int v=g[cl].front();  g[cl].pop();
        cout<<u<<' '<<v<<'\n';
        u=v;
        vis[u]=1;
        cl++;
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            cout<<i<<' '<<f[a[i]-1]<<'\n';
            g[a[i]].pop();
        }
    }
    for(int i=1; i<=n; i++) {
        cnt[i]=f[i]=vis[i]=0;
    }
} //yunayu_2026_target_M

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    // solve();
    int T; cin>>T; while(T--) solve();
    return 0;
} //"只要不失去你的崇高，整个世界都会向你敞开"