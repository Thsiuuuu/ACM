#include <bits/stdc++.h>
using namespace std;
/*

    二分查找
    一个步数可以那么比它步数多的都可以沿用它的方案，所以答案具有单调性，考虑二分
    二分的上界和下界易得是2d和d，因为最多是停一步走一步，停的步数更多也没有用了，最少是不停直接走到头
    紧接着就是怎么判断可行了，必然要有d步行走和mid-d步休息，
    需要把休息的位置放的合理一些，
    容易想出x,x,x,x+1,x+1,x+1这种方式，反证法易证，任意交换一个次序都会让代价变大
    这样就可以算出走到终点的最小代价，如果最后剩余数量>=1那么就是可以的

*/
#define ll long long 
bool check(ll mid,ll d,ll h){
    ll x=mid-d+1;
    ll cost=(d/x+1)*(d/x+2)/2*(d%x)+(d/x*(d/x+1)/2*(x-d%x))-x+1;
    return h-cost>0;
}

void sol() {
    ll h,d;
    cin>>h>>d;
    ll ans=0;
    if(h==1){
        cout<<2*d<<'\n';
    }else{
        ll l=d,r=2*d,mid;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(check(mid,d,h)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}