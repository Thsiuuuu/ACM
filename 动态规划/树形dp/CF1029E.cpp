#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const int N=2e5+10;
vector<int> e[N];
int f[N][3];
void dfs(int u,int fa,int depth){
    int s=0;
    f[u][0]=(depth>=2);
    if(e[u].size()==1){
        if(u!=1){
            f[u][1]=1;
            return ;
        }
    }
    for(int v:e[u]){
        if(v^fa){
            dfs(v,u,depth+1);
            s+=min(f[v][0],f[v][1]);
            f[u][0]+=min({f[v][0],f[v][1],f[v][2]});
            f[u][2]+=min({f[v][0],f[v][1]});
        }
    }
    f[u][1]=INT32_MAX;
    for(int v:e[u]){
        if(v^fa){
            f[u][1]=min(s-min(f[v][0],f[v][1])+f[v][0],f[u][1]);
        }
    }
}

void sol() {
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,0,0);
    // for(int i=1;i<=n;i++){
    //     cout<<f[i][0]<<" "<<f[i][1]<<" "<<f[i][2]<<'\n';
    // }
    cout<<min(f[1][0],f[1][1]);
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