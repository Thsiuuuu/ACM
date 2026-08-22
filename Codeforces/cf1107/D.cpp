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
// 区间加减想前缀和，等价于所有前缀和都相等
// 每次操作的影响是+1,0,+1类型的
// 那么a的前缀和必然小于等于b的前缀和
// 只需要选长度为2的区间就可以完成修改
void sol() {
    int n;cin>>n ;
    VL a(n+1,0),b(n+1,0);
    for(int i=0;i<n;i++) cin>>a[i+1];
    for(int i=0;i<n;i++) cin>>b[i+1];
    bool f=true;
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
        f&=(a[i]<=b[i]);
    }
    // ll sum=0;
    // for(int i=0;i<n;i++){
    //     sum+=(a[i]-b[i]);
    // }
    cout<<((f)?"yes\n":"no\n");
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