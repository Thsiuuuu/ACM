#include <bits/stdc++.h>
using namespace std;

int st[110][110];
char mp[110][110];
int dx[9]={-1,0,1,0,-1,1,1,-1,-1};
struct node{
    int x,y,z;
};

void dfs(int cx,int cy,)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int x,y,mx,my;
    cin>>x>>y>>mx>>my;
    int ans=0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='.'){
                st[i][j]=1;
                ans++;
            }
        }
    }
    queue<node> que;
    que.push({mx,my,0});
    while(que.size()){
        auto[cx,cy,level]=que.front();
        que.pop();
        if(ans==0){
            cout<<level;
            return 0;
        }
        for(int i=0;i<=7;i++){
            if(cx+dx[i]>=1&&cx+dx[i]<=x&&cy+dx[i+1]>=1&&cy+dx[i+1]<=y&&mp[cx+dx[i]][cy+dx[i+1]]=='.'&&st[cx+dx[i]][cy+dx[i+1]]==1){
                ans--;
                que.push({cx+dx[i],cy+dx[i+1],level+1});
                st[cx+dx[i]][cy+dx[i+1]]=0;
            }
        }
    }
}