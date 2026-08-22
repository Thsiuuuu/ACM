#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const int N=31;
int a[N][N];
int n,m,k;
int dir[5]={-1,0,1,0,-1};
int cpy[N][N];

/*

    0-base的
    mask=0,留在方格当中的
    low最底层

*/

bool check(int mask){
    vector<int> di(k,0),tot(k,0),low(k,0);
    vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
    cout<<mask<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cpy[i][j]=a[i][j];
            if(a[i][j]&&(mask&(1<<(a[i][j]-1)))) cpy[i][j]=0;
            cout<<cpy[i][j]<<" ";
        }
        cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!cpy[i][j]||vis[i][j]) continue;
            else{
                queue<pii> q;
                q.push({i,j});
                vis[i][j]=true;
                low[cpy[i][j]]=j;
                while(q.size()){
                    auto [x,y]=q.front();
                    q.pop();
                    if(y>low[cpy[i][j]]) low[cpy[i][j]]=y,di[cpy[x][y]-1]=0;
                    if(low[cpy[i][j]]==y) di[cpy[x][y]-1]++;
                    for(int k=0;k<4;k++){
                        int px=x+dir[k],py=y+dir[k+1];
                        if(px<1||px>n||py<1||py>m||cpy[px][py]==0) continue;
                        else if((cpy[px][py]!=cpy[x][y])){
                            tot[cpy[x][y]-1]++;
                        }else{
                            if(!vis[px][py]){
                                q.push({px,py});
                                vis[px][py]=1;  
                            }
                        }
                    }
                }
            }
        }
    }
    // cout<<mask<<" ";
    for(int i=0;i<k;i++){
        if((mask&(1<<i))==0){
            for(int j=1;j<=m;j++){
                if(cpy[low[i]][j]!=i) continue;
                for(int w=0;w<4;w++){
                    int px=low[i]+dir[w],py=j+dir[w+1];
                    if(px==0) tot[i]++;
                    if(py==0) tot[i]++;
                    if(px>n) tot[i]++;
                    if(py>m) tot[i]++;
                }
            }
            if(tot[i]<(di[i]+1)/2) return false; 
        } 
    }
    // cout<<"true\n";
    return true;
}

void sol() {
    int ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            k=max(k,a[i][j]);
        }
    }
    for(int mask=0;mask<(1<<(k));mask++){
        // cout<<mask<<'\n';
        if(ans>=__builtin_popcount(mask)) continue;
        if(check(mask)) ans=__builtin_popcount(mask);
    }
    cout<<ans<<'\n';
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