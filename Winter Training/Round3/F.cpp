#include <bits/stdc++.h>
using namespace std;
/*

    自己写的非常使的一个做法
    手玩样例，发现坐标有一个特点，坐标中1的数量就是该点到原点的边数，所以说可以用bfs更新每个点和原点的距离
    然后以三维为例，一个点它的所有相邻的且距离比它小于1的点一定可以通过一条边到达它，也就是说如果把每一维度都抽象成一个坐标轴的话，必然可以通过该点的某一维度进行投影，即某一位置的坐标由1->0
    所以说每一个相邻且距离比它小于1的点，一定是它在某一个坐标轴的投影，类似于高维前缀和，这一个投影一定是它的子集，把所有子集并起来就是它自己
    但是需要注意判断，因为可以构造出hack样例，需要特别判断每一对点之间是否恰好有一位不同，并且是否所有的点恰好构成一个排列

*/

struct node{
    int idx,level;
};

void sol() {
    
    // cout<<log2(32768)<<'\n';
    int n,m;
    cin>>n>>m;
    if(__builtin_popcount((unsigned int)n)!=1){
        cout<<"-1\n";
    }else{
        // cout<<"Hel\n";
        // int high=0;
        // for(int i=0;i<=16;i++){
        //     if((1<<i)&n){
        //         high=i;
        //         break;
        //     }
        // }
        vector<int> deg(n+1,0);
        vector<vector<int>> e(n+1);
        for(int i=1,u,v;i<=m;i++){
            cin>>u>>v;
            deg[u]++,deg[v]++;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(deg[i]!=log2(n)){
                cout<<"-1\n";
                return ;
            }
        }
        vector<int> ans(n,-1),visited(n,0),len(n,0);
        len[0]=ans[0]=0,visited[0]=1;
        queue<node> que;
        
        int del=1;
        for(int v:e[0]){
            len[v]=1,ans[v]=del;
            que.push({v,1});
            visited[v]=1;
            del=(del<<1);
        }
        while(que.size()){
            auto [idx,level]=que.front();
            que.pop();
            for(int v:e[idx]){
                if(!visited[v]){
                    visited[v]=1;
                    len[v]=level+1;
                    que.push({v,len[v]});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<len[i]<<" ";
        // }

        for(int i=0;i<n;i++){
            if(len[i]<=1){
                visited[i]=1;
            }
            if(len[i]==2){
                visited[i]=1;
                que.push({i,len[i]});
            }
        }

        visited.assign(n,0);
        while(que.size()){
            auto [idx,level]=que.front();
            que.pop();
            ans[idx]=0;
            for(int v:e[idx]){
                if(ans[v]!=0&&__builtin_popcount((unsigned int)ans[v])==level-1){
                    ans[idx]|=ans[v];
                }
                if(visited[v]==0&&len[v]==level+1){
                    que.push({v,len[v]});
                    visited[v]=1;
                }
            }
        }
        vector<int> check=ans;
        sort(check.begin(),check.end());
        check.erase(unique(check.begin(),check.end()),check.end());
        if(check.size()<ans.size()){
            cout<<"-1\n";
            return ;
        }
        for(int i=0;i<n;i++){
            for(int v:e[i]){
                if(__builtin_popcount((unsigned int)(ans[v]^ans[i]))!=1){
                    cout<<"-1\n";
                    return ;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
    
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