#include <iostream>
#include <algorithm>

const int N=5e4+10;


using namespace std;

#define int long long 
int head[N],to[N<<1],nxt[N<<1];

int  cnt,siz[N],maxsub[N],ans=1145141919,n,path[N],sum=0;


void build(){
    cnt=1;
    fill(head,head+1+n,0);
    fill(path,path+n+1,0);
}

void addEdge(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

void dfs1(int u,int fa){
    maxsub[u]=0;
    siz[u]=1;
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=fa){
            dfs1(v,u);
            siz[u]+=siz[v];
            maxsub[u]=max(maxsub[u],siz[v]);
        }
    }
    maxsub[u]=max(maxsub[u],n-siz[u]);//求父节点所在子树大小的时候应该是总结点数减去自己和自己以下的节点数
}

void dfs2(int u,int fa){

    
    for(int e=head[u],v;e;e=nxt[e]){
        v=to[e];
        if(v!=fa){
            path[v]=path[u]+1;
            sum+=path[v];
            dfs2(v,u);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    build();
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }

    dfs1(1,0);
    for(int i=1;i<=n;i++){
        if(maxsub[i]<=n/2){
            ans=min(ans,i);
            break;
        }
    }

    path[ans]=0;
    dfs2(ans,0);

    cout<<ans<<" "<<sum;

    return 0;
}