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
const int N=2010;
int a[N][N],n;
VI all[N],e[N];
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            cin>>a[i][j];
            a[j][i]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if((a[1][i]^i)==(a[1][j]^a[i][j])){
                e[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        sort(e[i].begin(),e[i].end(),[&](int x,int y)->bool{
            return e[x].size()>e[y].size();
        });
    }
    for(int i=1;i<=n;i++){
        if(e[i].size()) all[e[i][0]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        for(int j:all[i]){
            cout<<i<<" "<<j<<'\n';
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