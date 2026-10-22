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
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
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
void sol() {
    int n,q;cin>>n;
    VL l(n+1,0),prel(n+1,0);
    vector<i128> v(n+1,0),prev(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    sort(v.begin()+1,v.end(),greater<ll>());
    sort(l.begin()+1,l.end());
    for(int i=1;i<=n;i++){
        prev[i]=prev[i-1]+v[i];
        prel[i]=prel[i-1]+l[i];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        ll x;cin>>x;
        i128 ans=0;
        int L=1,R=n,mid;
        while(L<=R){
            mid=(L+R)>>1;
            if(v[mid]-(i128)x*l[mid]<=0){
                R=mid-1;
            }else {
                ans=max(ans,prev[mid]-(i128)x*prel[mid]);
                L=mid+1;
            }
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
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