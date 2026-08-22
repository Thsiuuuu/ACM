#include <iostream>
#include <algorithm>

using namespace std;

/*

    很显然如果有两个重心，则这两个重心的最大子树都是最小的

    这个时候需要拆掉一条边使得只存在一个重心，那么就是要破坏掉重心最大子树上的点
    使得他们变得一大一小，这个时候拆叶节点是最简单的
    比如拆左边，那么因为恰好左边少了1，右边多了1，那么重心就是右边那个点了


*/


const int N=100001;

int n;
int head[N],nxt[N<<1],to[N<<1],cnt;

int siz[N],maxsub[N],centers[2];

int leaf,leafFather;

void build(){
    cnt=1;
    fill(head,head+1+n,0);
}

void addEdge(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

void dfs(int u,int f){
    siz[u]=1;
    maxsub[u]=0;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=f){
            dfs(v,u);
            siz[u]+=siz[v];
            maxsub[u]=max(maxsub[u],siz[v]);
        }
    }
    maxsub[u]=max(maxsub[u],n-siz[u]);
}

void find(int u,int f){
    for(int e=head[u];e;e=nxt[e]){
        if(to[e]!=f){
            find(to[e],u);
            return ;
        }
    }
    leaf=u;
    leafFather=f;
}

int centerCnt(){
    int m=0;
    for(int i=1;i<=n;i++){
        if(maxsub[i]<=n/2){
            centers[m++]=i;
        }
    }
    return m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        build();
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            addEdge(u,v);
            addEdge(v,u);
        }
        dfs(1,0);
        if(centerCnt()==1){
            cout<<centers[0]<<" "<<to[head[centers[0]]]<<"\n";
            cout<<centers[0]<<" "<<to[head[centers[0]]]<<"\n";
        }else{
            find(centers[1],centers[0]);
            cout<<leafFather<<" "<<leaf<<"\n";
            cout<<centers[0]<<" "<<leaf<<"\n";
        }
    }
    return 0;
}