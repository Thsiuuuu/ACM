#include <algorithm>
#include <iostream>

using namespace std;

const int N=20001;

//根据最大子树的节点数最小判断重心


int n;
int head[N],nxt[N<<1],to[N<<1];

int cnt,siz[N],center,best;

void build(){
    cnt=1;
    fill(head,head+1+n,0);
    best=INT_MAX;
}

void addEdge(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

//当前来到u节点，父亲节点是f
void dfs(int u,int f){
    siz[u]=1;

    //以u做根节点，最大的子树有多少节点
    int maxsub=0;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=f){
            dfs(v,u);
            siz[u]+=siz[v];
            maxsub=max(maxsub,siz[v]);
        }
    }
    maxsub=max(maxsub,n-siz[u]);

    //找到编号最小的重心
    if(maxsub<best||(maxsub)==best&&u<center){
        best=maxsub;
        center=u;
    }
}

int main(){
    int t;
    while(t--){
        cin>>n;
        build();
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            addEdge(u,v);
            addEdge(v,u);
        }
        dfs(1,0);
        cout<<center<<" "<<best<<"\n";
    }
}
