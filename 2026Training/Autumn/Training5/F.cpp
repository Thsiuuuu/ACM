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
const int N=1e5+10;
ll f[N][4],a[N],n;
const ll INF=1e9;
bool vis[N*10];
int prime[N*10/2+1],cnt=0;
void init(){
    for(ll i=2;i<N*10;i++){
        if(!vis[i]) prime[cnt++]=i;
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>N*10) break;
            vis[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }
}
void ckmin(ll &A,ll B){
    if(B<A) A=B;
}
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) for(int j=0;j<4;j++) f[i][j]=1e9;
    f[1][0]=0,f[1][1]=f[1][2]=f[1][3]=1;
    for(int i=2;i<=n;i++){
        if(!vis[a[i]+a[i-1]]) ckmin(f[i][0],f[i-1][0]);
        if(!vis[a[i]+1]) ckmin(f[i][0],f[i-1][1]);
        if(a[i]&1) ckmin(f[i][0],f[i-1][2]);
        else ckmin(f[i][0],f[i-1][3]);

        if(!vis[1+a[i-1]]) ckmin(f[i][1],f[i-1][0]+1);
        ckmin(f[i][1],f[i-1][1]+1);
        ckmin(f[i][1],f[i-1][2]+1);

        if(a[i-1]&1) ckmin(f[i][2],f[i-1][0]+1);
        ckmin(f[i][2],f[i-1][1]+1);
        ckmin(f[i][2],f[i-1][3]+1);
        if(a[i-1]%2==0) ckmin(f[i][3],f[i-1][0]+1);
        ckmin(f[i][3],f[i-1][2]+1);
    }
    // for(int k=1;k<=n;k++){
    //     for(int i=0;i<2;i++) for(int j=0;j<2;j++) cout<<f[k][i][j]<<" ";
    //     cout<<'\n';
    // }
    cout<<*min_element(f[n],f[n]+4);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}