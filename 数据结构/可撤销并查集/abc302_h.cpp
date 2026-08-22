#include <bits/stdc++.h>
using namespace std;
/*

    2.这种二选一的可以先连上一条边，表示只能选其中一个
    然后求的是从顶点1出发，到每个节点最多能拿多少种不同的小球
    1.这个可以采用类似递推的想法，dfs然后求
    3.然后就是怎么求，因为每次建边的过程实际就是合并两个联通块的过程，新联通块分成树和图，树就是边数，图就是点数
    4.代码实现层面，因为dfs需要撤销影响，且是合并联通块，所以要采用可撤销并查集

*/

const int MAXN=2e5+10;
int arr[MAXN][2];
int head[MAXN],nxt[MAXN<<1],to[MAXN<<1],cnt;

int father[MAXN],siz[MAXN],edgecnt[MAXN];

int rollback[MAXN][2],opsize=0;

int ans[MAXN],ball=0;

void addEdge(int u,int v){
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}

int find(int i){
    while(i^father[i]) i=father[i];
    return i;
}

void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(siz[fx]<siz[fy]){
        swap(fx,fy);
    }
    father[fy]=fx;
    siz[fx]+=siz[fy];
    edgecnt[fx]+=edgecnt[fy]+1;
    rollback[++opsize][0]=fx;
    rollback[opsize][1]=fy;
}

void undo(){
    int fx=rollback[opsize][0],fy=rollback[opsize--][1];
    father[fy]=fy;
    siz[fx]-=siz[fy];
    edgecnt[fx]-=edgecnt[fy]+1;
}

void dfs(int u,int fa){
    int fx=find(arr[u][0]),fy=find(arr[u][1]);
    bool added=false,uni=false;
    if(fx==fy){//是一个联通块的情况下,只有是树才能增加答案
        if(edgecnt[fx]<siz[fx]){
            ball++;
            added=true;
        }
        edgecnt[fx]++;
    }else{
        if(edgecnt[fx]<siz[fx]||edgecnt[fy]<siz[fy]){
            ball++;
            added=true;
        }
        uni=true;
        unite(fx,fy);
    }
    ans[u]=ball;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v^fa){
            dfs(v,u);
        }
    }
    if(added){
        ball--;
    }
    if(uni){
        undo();
    }else{
        edgecnt[fx]--;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i][0]>>arr[i][1];
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    for(int i=1;i<=n;i++){
        father[i]=i;
        siz[i]=1;
        edgecnt[i]=0;
    }
    dfs(1,0);
    for(int i=2;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}