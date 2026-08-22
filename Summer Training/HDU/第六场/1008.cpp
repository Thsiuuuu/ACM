// CuteSafari 
// 2000ms, 524288MB

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int _=1e7+5, _m=998244353, INF=0x3f3f3f3f3f3f3f3fLL; mt19937_64 rnd(98275314); int qpow(int a, int b) {int ret=1;while(b) {if(b&1) ret=ret*a%_m;b>>=1; a=a*a%_m;}return ret;}int inv(int a) {return qpow(a, _m-2);}int gcd(int a, int b) {return b==0?a:gcd(b, a%b);}int lcm(int a, int b) {return a/gcd(a, b)*b;}int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, k, cnta[30], cntb[30];
char a[_], b[_];
void solve() {
    cin>>n>>k;
    for(int i=0; i<26; i++) {
        cnta[i]=cntb[i]=0;
    }
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++) {
        cin>>b[i];
    }
    if(k==1) {
        for(int i=1; i<=n; i++) {
            cnta[a[i]-'a']++;
            cntb[b[i]-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(cnta[i]!=cntb[i]) {
                cout<<"No\n"; return;
            }
        }
        cout<<"Yes\n"; return;
    }
    if(n<2*k) {
        int buyiyang=0;
        for(int i=2; i<=n-1; i++) {
            if(a[i]!=b[i]) {
                buyiyang=1;
            }
        }
        if(buyiyang) {
            cout<<"No\n"; return;
        }
        if(a[1]!=b[1]) {
            if(!(a[1]==b[n]&&a[n]==b[1])) {
                cout<<"No\n"; return;
            }
        }
        else {
            if(a[n]!=b[n]) {
                cout<<"No\n"; return;
            }
        }
        cout<<"Yes\n"; return;
    }
    if(n>=2*k) {
        int buyiyang=0;
        for(int i=2; i<=k-1; i++) {
            if(a[i]!=b[i]) {
                buyiyang=1;
            }
        }
        for(int i=n-k+2; i<=n-1; i++) {
            if(a[i]!=b[i]) {
                buyiyang=1;
            }
        }
        if(buyiyang) {
            cout<<"No\n"; return;
        }
        for(int i=1; i<=n; i++) {
            if(i>=2&&i<=k-1) continue;
            if(i>=n-k+2&&i<=n-1) continue;
            cnta[a[i]-'a']++;
            cntb[b[i]-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(cnta[i]!=cntb[i]) {
                cout<<"No\n"; return;
            }
        }
        if(a[1]==b[1]&&a[n]==b[n]||a[1]==b[n]&&a[n]==b[1]) {
            cout<<"Yes\n"; return;
        }
        if(a[1]!=b[1]&&a[n]!=b[n]) {
            cout<<"Yes\n"; return;
        }
        if(a[1]==b[1]&&a[n]!=b[n]) {
            if(cnta[a[1]-'a']>1) cout<<"Yes\n";
            else cout<<"No\n";
            return;
        }
        if(a[n]==b[n]&&a[1]!=b[1]) {
            if(cnta[a[n]-'a']>1) cout<<"Yes\n";
            else cout<<"No\n";
            return;
        }
    }
} //yunayu_2026_target_M

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    // solve();
    int T; cin>>T; while(T--) solve();
    return 0;
} //"只要不失去你的崇高，整个世界都会向你敞开"