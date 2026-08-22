#include <iostream>
#include <algorithm>


using namespace std;
#define int long long 
const int N=100001;

int n;
int cow[N],cowsum,head[N],nxt[N<<1],to[N<<1],weight[N<<1];

int cnt,best,center;

int siz[N],path[N];

void build(){
    cnt=1;
    fill(head,head+1+n,0);
    cowsum=0;
    best=INT_MAX;
}

void addEdge(int u,int v,int w){
    nxt[cnt]=head[u];
    to[cnt]=v;
    weight[cnt]=w;
    head[u]=cnt++;
    
}

void findCenter(int u,int f){
    siz[u]=cow[u];
    int maxsub=0;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=f){
            findCenter(v,u);
            siz[u]+=siz[v];
            maxsub=max(maxsub,siz[v]);
        }
    }
    maxsub=max(maxsub,cowsum-siz[u]);
    if(maxsub<best){
        best=maxsub;
        center=u;
    }
}

void setPath(int u,int  f){
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=f){
            path[v]=path[u]+weight[e];
            setPath(v,u);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    build();
    for(int i=1;i<=n;i++){
        cin>>cow[i];
    }
    for(int i=1,u,v,w;i<n;i++){
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    for(int i=1;i<=n;i++){
        cowsum+=cow[i];
    }

    findCenter(1,0);
    path[center]=0;
    setPath(center,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=cow[i]*path[i];
    }
    cout<<ans;
    return 0;
}