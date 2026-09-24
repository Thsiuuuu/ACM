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
const int N=5e5+10;
array <VI,9> e[N];
int n,m,k;
int cnt=0;
void dfs(VI &a,int len){
    if(a.size()==0) return ;
    for(int w=1;w<9;w++){
        if(cnt==k) return ;
        VI all;
        for(int u:a){
            if(cnt==k) return ;
            for(int v:e[u][w]){
                if(cnt==k) return ;
                cout<<len+1<<'\n';
                cnt++;
                all.push_back(v);
            }
        }
        if(cnt==k) return ;
        dfs(all,len+1);
    }
}
void sol() {
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;cin>>x>>y>>z;
        e[x][z].push_back(y);
    }
    VI all;
    for(int i=1;i<=n;i++) all.push_back(i);
    dfs(all,0);
    while(cnt++<k) cout<<"-1\n";
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