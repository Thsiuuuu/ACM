#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const int N=1e5+2;
const ld PI=acos(-1);
struct Point{
    ld x,y;
    int idx;
}p[N];


void sol() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        p[i].idx=i+1;
    }
    sort(p,p+n,[&](const Point&a,const Point&b)->bool{
        return atan2(a.y,a.x)<atan2(b.y,b.x);
    });
    ld theta=2*PI;
    int a=-1,b=-1;
    for(int i=0;i<n;i++){
        ld tmp=abs(atan2(p[i].y,p[i].x)-atan2(p[(i+1)%n].y,p[(i+1)%n].x));
        // cout<<min(tmp,2*PI-tmp)<<"\n";
        if(min(tmp,2*PI-tmp)<theta){
            theta=min(tmp,2*PI-tmp);
            a=p[i].idx,b=p[(i+1)%n].idx;
        }
    }
    cout<<a<<" "<<b;
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