#include <bits/stdc++.h>
using namespace std;
/*



*/

const int N=3010;
char mp[N][N];
int sum[N][N];
bool vis[N][N];
bool first[N];
int n,c;


struct node{
    int x,y;
};

bool check(int x,int y){
    if(x>=1&&x<=n&&y>=1&&y<=n&&vis[x][y]==0&&(mp[x][y]=='.'||(sum[x+1][y]==0)||first[y])){
        return true;
    }
    return false;
}

void sol() {
    // int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis[i][j]=0;
            cin>>mp[i][j];
        }
    }
    for(int j=1;j<=n;j++){
        sum[n+1][j]=0;
    }
    for(int i=n;i>=1;i--){
        first[i]=0;
        for(int j=1;j<=n;j++){
            sum[i][j]=0;
            if(i+1<=n){
                sum[i][j]+=sum[i+1][j];
            }
            if(mp[i][j]=='#'){
                sum[i][j]++;
            }
            // cout<<i<<" "<<j<<" "<<sum[i][j]<<'\n';
        }
    }
    vector<int> able(n+1,0);
    queue<node> que;
    que.push({n,c});
    while(que.size()){
        auto[x,y]=que.front();
        que.pop();
        if(x==1){
            able[y]=1;
            continue;
        }
        if(first[y]==0&&(sum[x+1][y]==0)){
            first[y]=1;
            able[y]=1;
        }
        if(check(x-1,y-1)){
            vis[x-1][y-1]=1;
            que.push({x-1,y-1});
        }
        if(check(x-1,y)){
            vis[x-1][y]=1;
            que.push({x-1,y});
        }
        if(check(x-1,y+1)){
            vis[x-1][y+1]=1;
            que.push({x-1,y+1});
        }
    }
    for(int i=1;i<=n;i++){
        cout<<(able[i]||first[i]);
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}