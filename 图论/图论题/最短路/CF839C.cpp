#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*

    两种方法，1是直接搜索，然后更新记录
    2是考虑dp，dp是简单的换根dp，这里不细说了
    但是两种方法感觉差不多，重点是被这个概率卡了两周（国庆要结束了，数据结构的两个实验和py的实验还没有做）


*/

#define int long long 
const int N=1e5+10;
vector<int> e[N];

struct node{
    int u,len;
    double val;
};

double sum[N]={0};
int vis[N]={0};

signed main(){
    int n;
    scanf("%lld",&n);
    for(int i=0,u,v;i<n-1;i++){
        scanf("%lld%lld",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    e[1].push_back(0);
    queue<node> que;
    que.push({1,0,1});
    int mx=0;
    while(que.size()){
        auto [u,len,val]=que.front();
        que.pop();
        int siz=e[u].size();
        if(siz==1){
            // printf("%lld\n",u);
            sum[len]+=val;
        }
        for(int v:e[u]){
            if(v==0) continue;
            if((!vis[v])){
                vis[v]=1;
                que.push({v,len+1,(val*((double)1.0/(siz-1)))});
                mx=((mx<(len+1))?(len+1):mx);
            }
        }
    }
    double ans=0;
    for(int i=1;i<=mx;i++){
        ans+=(sum[i]*i);
        // printf("%lld %lf\n",i,sum[i]);
    }
    printf("%lf",ans);
    
    return 0;
}