#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define i128 __int128_t
#define VL vector<ll>
#define VI vector<int>


/*


    这个记忆化搜索时间复杂度$O(n+26m)$，n点的数量,m边的数量

*/

const int N=3e5+10;
ll mx[N][26];//dp,f_{u,i}表示节点u为起点的所有路径中，字母i能得到的最多的次数
VI e[N];
int du[N],num[N];
bool vis[N];
void dfs(int u){
    for(int v:e[u]){
        if(!vis[v]) dfs(v);
        vis[v]=true;
        /*
        
            记忆化搜索，如果节点v没有访问，就去dfs，然后存到mx数组里面。
            访问了的话，直接更新就好
        
        */
        for(int i=0;i<26;i++){
            // cout<<i<<" "<<(num[u]==i)<<'\n';
            mx[u][i]=max(mx[u][i],mx[v][i]);
        }
    }
    mx[u][num[u]]+=1;
    //路径要把自己的字母num[u]也算进去
}
void sol(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        char c;cin>>c;
        num[i+1]=c-'a';
    }
    bool f=false;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        if(u==v) f=true;//自环为-1
    }
    if(f){
        cout<<"-1\n";
        return ;
    }
    for(int i=1;i<=n;i++){
        /*
        
            把每个点的所有出边排序，去重
            然后跑拓扑，有环就不行。
        
        */
        sort(e[i].begin(),e[i].end());
        e[i].erase(unique(e[i].begin(),e[i].end()),e[i].end());
        for(auto j:e[i]){
            du[j]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(du[i]==0) q.push(i);
    }
    while(q.size()){
        auto u=q.front();
        q.pop();
        for(int v:e[u]){
            if(--du[v]==0){
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(du[i]>0){
            cout<<"-1";
            return ;
        }
    }
    /*
    
        这里可以建反边拓扑排序，但是有点麻烦?
        直接记忆化搜索，
    
    */
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            vis[i]=true;
        }
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        // cout<<num[i]<<" ";
        for(int j=0;j<26;j++){
            // cout<<i<<" "<<j<<' '<<mx[i][j]<<'\n';
            ans=max(ans,mx[i][j]);
        }
    }
    cout<<ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}