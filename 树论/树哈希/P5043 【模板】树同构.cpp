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
const int N=52;
ull hsh[N][N];
VI e[N];
int siz[N];
int n,m,cnt=0;
const ull mask=std::mt19937_64(time(nullptr))();
ull shift(ull x){
    x^=mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=mask;
    return x;
}
ull dfs(int u,int fa){
    ull val=1;
    for(int v:e[u]){
        if(v^fa){
            val+=shift(dfs(v,u));
        }
    }
    return val;
}
void sol() {
    cin>>m;
    for(int j=1;j<=m;j++){
        cin>>n;
        siz[j]=n;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            if(x){
                e[x].push_back(i);
                e[i].push_back(x);
            }
        }
        cnt++;
        for(int i=1;i<=n;i++){
            hsh[cnt][i]=dfs(i,0);
        }
        sort(hsh[cnt]+1,hsh[cnt]+n+1);
        for(int x=1;x<=j;x++){
            if(siz[x]^siz[j]) continue;
            bool is=true;
            for(int i=1;i<=n;i++){
                if(hsh[x][i]!=hsh[j][i]){
                    is=false;
                    break;
                }
            }
            if(is){
                cout<<x<<'\n';
                break;
            }
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