#include <bits/stdc++.h>
using namespace std;
#define int long long 

const  int N=4e3+20;
int dp[N][N];
int que[N];
/*


    因为把弹出队列放在了加入队列的代码里面，看了好久

*/
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m,k,t;
    cin>>n>>m>>k>>t;
    for(int i=0;i<k;i++){
        int x,y,v;
        cin>>x>>y>>v;
        dp[x][y]=v;
    }
    for(int i=2;i<=n;i++){
        int head=0,tail=-1;
        int r=1;
        for(int j=1;j<=m;j++){
            while(r<=m&&r<=j+t){
                while(head<=tail&&dp[i-1][que[tail]]<=dp[i-1][r]) tail--;
                que[++tail]=r++;
            }//加入队列需要判断能不能加
            while(head<=tail&&que[head]<j-t) head++;//弹出队列只要超过就需要弹出
            dp[i][j]+=dp[i-1][que[head]];
        }
    }
    int ans=-1;
    for(int i=1;i<=m;i++){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans;
    return 0;
}