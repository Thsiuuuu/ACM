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
const int N=2e5+10;
int b[21],g[N][21];
pll f[1<<21],a[N];
void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a+1,a+1+n,greater<pll>());
    for(int j=0;j<m;j++){
        for(int i=1,k=1;i<=n;i++){
            k=max(k,i);
            while(k<=n&&1ll*a[k].first*(k-i+1)<b[j]) k++;
            if(k<=n&&1ll*a[k].first*(k-i+1)>=b[j]) g[i][j]=k;
            else g[i][j]=-1;
        }
    }
    for(int i=0;i<(1<<m);i++) f[i]={-1,-1};
    f[0]={0,1};//{上一个の状态，今の決断之起點}
    for(int mask=0;mask<(1<<m);mask++){
        if(f[mask].first==-1||(f[mask].first!=(1<<m)-1&&f[mask].second==n+1)) continue;
        for(int j=0;j<m;j++){
            if((mask>>j)&1) continue;
            auto [x,y]=f[mask];
            if(g[y][j]!=-1){
                int v=g[y][j];
                if(f[mask|(1<<j)].second==-1||f[mask|(1<<j)].second>v+1 ){
                    f[mask|(1<<j)]={mask,v+1};
                }
            }
        }
    }
    if(f[(1<<m)-1].second==-1) return void(cout<<"NO\n");
    else{
        VII ans(m);
        cout<<"YES\n";
        int mask=(1<<m)-1;
        while(mask){
            int pre=f[mask].first,l=f[pre].second,r=g[f[pre].second][__builtin_ctz(mask^f[mask].first)];
            for(int i=l;i<=r;i++){
                ans[__builtin_ctz(mask^f[mask].first)].push_back(a[i].second);
            }
            mask=f[mask].first;
        }
        for(int i=0;i<m;i++){
            cout<<ans[i].size();
            for(int x:ans[i]) cout<<" "<<x;
            cout<<'\n';
        }
    }
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