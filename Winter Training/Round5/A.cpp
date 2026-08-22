#include <bits/stdc++.h>
using namespace std;
/*

    概率论
    因为是等概率分布的，所以说是一个均匀分布
    因为要求期望能拿到多少钱，可以认为是一直在期望条件下发生的
    那么第一个人就是拿到了w/2，第二个人期望剩下w/2,期望拿到w/4,
    依次类推，第k个人拿到w/(2^k)

*/
#define ll long long 
const ll mod=1e9+7;

ll qmi(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*(a%mod))%mod;
        }
        b>>=1;
        a=((a%mod)*(a%mod))%mod;
    }
    return res;
}

ll fracmod(ll a,ll b){
    return (a%mod)*qmi(b,mod-2)%mod;
}

void sol() {
    ll w,n,k;
    cin>>w>>n>>k;

    ll bs=qmi(2,k);
    cout<<fracmod(w,bs);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}