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
ll f[N],a[N],n;

void sol(int ts) {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=0;
    for(int i=1;i<=n+1;i++){
        f[i]=a[i]-a[i-1];
    }   
    int j=4;
    for(int i=1;i<=n+1;i++){
        if(f[i]<0) {
            cout<<"Case #"<<ts<<": No\n";
            return ;
        }
        if(!f[i]) continue;
        while(j<=n+1){
            if(f[j]>=0||j-i<3){
                j++;
                continue;
            }
            ll mut=min(-f[j],f[i]);
            f[j]+=mut,f[i]-=mut;
            if(f[j]==0) j++;
            if(f[i]==0) break;
        }
        if(f[i]) {
            cout<<"Case #"<<ts<<": No\n";
            return ;
        }
    }
    cout<<"Case #"<<ts<<": Yes\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}