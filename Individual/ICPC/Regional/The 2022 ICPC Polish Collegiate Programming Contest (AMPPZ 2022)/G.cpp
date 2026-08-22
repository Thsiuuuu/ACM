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

VL p,v;
int n;
ld eps=1e-8;
bool ck(ld mid){
    ld Mx=-1e18,Mn=1e18;
    for(int i=0;i<n;i++){
        if(p[i]<0){
            Mx=max(Mx,p[i]+v[i]*mid);
        }else{
            Mn=min(Mn,p[i]-v[i]*mid);
        }
    }
    return Mx+eps>=Mn;
}
void sol() {
    ld v0;
    cin>>n>>v0;
    v.clear(),p.clear();
    for(int i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        p.push_back(x);
        v.push_back(y);
    }
    ld mid,t,l=0,r=1e13;
    for(int i=0;i<90;i++){
        mid=(l+r)*0.5;
        if(ck(mid)){
            r=mid;
            t=mid;
        }else{
            l=mid;
        }
    }
    cout<<t*v0<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    cout<<fixed<<setprecision(10);
    while (t--) {
        sol();
    }
    return 0;
}