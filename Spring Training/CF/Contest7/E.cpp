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

const double PI=acos(-1);
double f(ll t,ll m,ll k){
    return (double)(t-k*m)*(t-k*m)/((double)(4*k*tan(PI/k)));
}

void sol() {
    ll t,m;
    cin>>m>>t;
    ll r=t/m,l=3;
    if(r<3){
        cout<<"0\n";
        return ;
    }
    ll lmid,rmid;
    while(l<r){
        ll mid=(l+r)>>1;
        lmid=mid,rmid=mid+1;
        if(f(t,m,lmid)<f(t,m,rmid)) l=lmid+1;
        else r=rmid-1;
    }
    cout<<fixed<<setprecision(7)<<f(t,m,l)<<'\n';
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