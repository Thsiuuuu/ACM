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

const int N=2010;
int a[N][N];
int dx[3]={-1,0,1},dy[3]={-1,0,1};

void sol() {
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }    
    
    vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
    vector<int> all;
    for(int i=1;i<=m;i++){
        queue<pii> Q;
        Q.push({1,i});
        vis[1][i]=1;
        while(Q.size()){
            auto [x,y]=Q.front();
            Q.pop();
            if(x==n||y==1) all.push_back(a[1][i]);
            for(int px:dx){
                for(int py:dy){
                    int ax=px+x,ay=py+y;
                    if(ax<=0||ax>n||ay<=0||ay>m||vis[ax][ay]||a[ax][ay]!=a[1][i]) continue;
                    Q.push({ax,ay});
                    vis[ax][ay]=1;
                }
            }
        }
    }   
    for(int i=1;i<=n;i++){
        queue<pii> Q;
        Q.push({i,m});
        vis[i][m]=1;
        while(Q.size()){
            auto [x,y]=Q.front();
            Q.pop();
            if(x==n||y==1) all.push_back(a[i][m]);
            for(int px:dx){
                for(int py:dy){
                    int ax=px+x,ay=py+y;
                    if(ax<=0||ax>n||ay<=0||ay>m||vis[ax][ay]||a[ax][ay]!=a[i][m]) continue;
                    Q.push({ax,ay});
                    vis[ax][ay]=1;
                }
            }
        }
    }   
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    int ans=0;
    for(int i=0;i<all.size();i++){
        if(all[i]!=i) break;
        else ans++;
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