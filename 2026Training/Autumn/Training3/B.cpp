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
const int N=2e5+10;
ll a[N],n,m;
struct node{
    // ld cr;
    ll number,all;
    ld val()const{
        return (ld)all*all/number-(ld)all*all/(number+1);
    }
    bool operator<(const node&o)const{
        return val()<o.val();
    }
};
void sol(int ts) {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    priority_queue<node,vector<node>> Q;
    for(int i=1;i<=n;i++){
        Q.push({1,a[i]});
    }
    for(int i=0;i<m-n;i++){
        auto [number,sum]=Q.top();
        Q.pop();
        Q.push({number+1,sum});
    }
    ld ans=0;
    while(Q.size()){
        auto [number,sum]=Q.top();
        Q.pop();
        ans+=(ld)sum*sum/number;
    }
    ld sum=0;
    for(int i=1;i<=n;i++) sum+=a[i];
    sum=sum*sum/m/m;
    ans/=m;
    ans-=sum;
    cout<<fixed<<setprecision(10);
    cout<<"Case #"<<ts<<": "<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}