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
int n,m;
ll a[1001][1001];
void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    stack<pll> stk;
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]>0) stk.push({j,a[i][j]});
            else if(a[i][j]<0){
                while(stk.size()){
                    ll mn=min(abs(a[i][j]),stk.top().second);
                    a[i][j]+=mn;
                    stk.top().second-=mn;
                    if(stk.top().second==0) stk.pop();
                    if(a[i][j]==0) break;
                }
                if(a[i][j]<0) ans-=a[i][j];
            }
        }
        while(stk.size()){
            if(i==n){
                ans+=stk.top().second;
            }else{
                a[i+1][stk.top().first]+=stk.top().second;
            }
            stk.pop();
        }
    }
    cout<<ans<<'\n';
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