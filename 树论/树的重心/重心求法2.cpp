#include <algorithm>
#include <iostream>

using namespace std;

const int N=50001;

int n;
int head[N],nxt[N],to[N];

int cnt,siz[N],maxsub[N];

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
    for(int e=head[u],v;e!=0;e=nxt[e]){
        v=to[e];
        if(v!=f){
            dfs(v,u);
            siz[u]+=siz[v];
            maxsub[u]=max(maxsub[u],siz[v]);
        }
    }
    maxsub[u]=max(maxsub[u],n-siz[u]);
}

int main(){
    cin>>n;
    build();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,0);
    int m=0;
    int centers[2];
    for(int i=1;i<=n;i++){
        if(maxsub[i]<=n/2){
            centers[m++]=i;
        }
    }
    if(m==1){
        cout<<centers[0];
    }else{
        cout<<centers[0]<<" "<<centers[1];
    }
    return 0;
}