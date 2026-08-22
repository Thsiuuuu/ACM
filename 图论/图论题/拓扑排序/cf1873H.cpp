#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
/*

    可以利用拓扑排序解决，形似警察抓小偷的问题
    二者的相对关系共有三种情况
    第一种，二者都在环上，肯定抓不到
    第二种，小偷在环上，警察在链上，那么一定抓不到，我总能根据警察的策略决定我的策略
    第三种，小偷在链上，警察在环上，需要分类讨论
    如果警察在小偷到达环上之前就能到达环和链的交点，那么一定可以抓到它
    反之不行
    所以可以利用拓扑排序找到环进行判断

*/


#define int long long
using pii=pair<int,int>;
struct node{
    int x,l,fa;
};
const int N=2e5+10;
vector<int> e[N];
int deg[N];
bool vis[N]={false};//,vis2[N]={false},vis3[N]={false};

pii find(int x){
    queue<node> que;
    que.push({x,0,0});
    while(!que.empty()){
        auto [u,l,fa]=que.front();
        que.pop();
        for(int v:e[u]){
            if(!vis[v]){
                return {v,l+1};
            }
            if(v!=fa){
                que.push({v,l+1,u});
            }
        }
    }
}//找到一个点所在链上最近和环的交点，并且返回距离

int dis(int x,int y){
    queue<node> que;
    que.push({x,0,0});
    while(!que.empty()){
        auto [u,l,fa]=que.front();
        que.pop();
        if(u==y){
            return l;
        }
        for(int v:e[u]){
            if(v!=fa&&vis[v]==false){
                que.push({v,l+1,u});
            }
        }
    }
}//找到环上两点间的最短距离

void sol(){

    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if(a==b){
        cout<<"no\n";
        for(int i=1;i<=n;i++){
            e[i].clear();
            deg[i]=0;
            vis[i]=false;
        }
        return ;
    }
    queue<int> que;
    for(int i=1;i<=n;i++){
        // cout<<i<<" "<<deg[i]<<'\n';
        if(deg[i]==1){
            que.push(i);
            vis[i]=true;//访问过的节点打上true标记
        }
    }
    while(!que.empty()){
        int u=que.front();
        // cout<<u<<'\n';
        que.pop();
        for(int v:e[u]){
            if((--deg[v]==1)&&vis[v]==false){
                que.push(v);
                vis[v]=true;
            }
        }
    }
    bool flag=false;//true是小偷必胜
    if(!(vis[a]|vis[b])){
        // cout<<"1\n";
        flag=true;
    }else if(vis[a]==true&&vis[b]==false){
        // cout<<'2\n';
        flag=true;
    }else if(vis[a]==false&&vis[b]==true){

        auto [cro,l2]=find(b);
        int l1=dis(a,cro);
        // cout<<l1<<" "<<l2<<'\n';
        if(l1>l2){
            flag=true;
        }
    }else{
        // cout<<"4\n";
        auto [cro1,l1]=find(a);
        auto [cro2,l2]=find(b);
        int dist=dis(cro1,cro2);
        if(dist+l1>l2){
            flag=true;
        }
    }
    if(flag){
        cout<<"yes\n";
    }else{
        cout<<"no\n";
    }
    for(int i=1;i<=n;i++){
        e[i].clear();
        deg[i]=0;
        vis[i]=false;
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}