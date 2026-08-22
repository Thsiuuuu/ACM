#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*

    首先求最小值要考虑可不可以用bfs
    如果一个关系正向求解的时间复杂度比较高，考虑可不可以反向求

    这个就是正向求解每一个点的每一个颜色的最短距离时间复杂度很高O(n*m)
    观察数据范围，求解每一个颜色到每一个点的时间复杂度并不是很高O(k*n)<=O(100*n),
    然后对于每个点，进行排序，筛序出前s个元素即可

*/

#define int long long 
const int N=1e5+10;
int n,m,k,s;
vector<int> e[N];
int vis[N],col[N],dist[N][110];

signed main(){
    ios::sync_with_stdio(0);    cin.tie(0),cout.tie(0);

    cin>>n>>m>>k>>s;
    for(int i=1;i<=n;i++)   cin>>col[i];
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        e[u].push_back(v);  e[v].push_back(u);
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++) vis[j]=0;
        queue<int> que;
        for(int j=1;j<=n;j++){
            if(col[j]==i){
                que.push(j);
                vis[j]=1;
                dist[j][i]=0;
            }
        }
        while(que.size()){
            int fr=que.front(); que.pop();
            for(int v:e[fr]){
                if(!vis[v]){
                    dist[v][i]=dist[fr][i]+1;                   
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        sort(dist[i]+1,dist[i]+1+k);
        int sum=0;
        for(int j=1;j<=s;j++){
            sum+=dist[i][j];
        }
        cout<<sum<<" ";
    }
    return 0;
}