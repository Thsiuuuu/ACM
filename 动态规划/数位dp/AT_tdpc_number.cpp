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
const ll mod=1000000007;
ll f[10002][2][100];
string n;int d;
ll dfs(int pos,int is,int rem){
    if(pos==n.size()) return rem==0;
    if(f[pos][is][rem]!=-1) return f[pos][is][rem];
    f[pos][is][rem]=0;
    int up=is?(n[pos]-'0'):9;
    for(int x=0;x<=up;x++){
        f[pos][is][rem]=(f[pos][is][rem]+dfs(pos+1,is&&(x==up),(rem+x)%d))%mod;
    }
    return f[pos][is][rem];
}
void sol() {
    cin>>d>>n;
    for(int i=0;i<10002;i++) for(int j=0;j<2;j++) for(int k=0;k<100;k++) f[i][j][k]=-1;
    cout<<dfs(0,1,0)-1<<'\n';
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