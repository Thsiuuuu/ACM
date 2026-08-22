#include <bits/stdc++.h>
using namespace std;
/*

    只需要判断割边是否存在?
    很显然一个没有割边的极大图内部边都是有向的一定是联通的，只需要按照dfs序即可
    对于由割边串联形成的新图而言，两个极大图需要保持联通，就意味着它们在无向图的情况之下也是联通的
    所以它们之间的边并不是割边，这样的图不存在

*/

const int M=3e5+10;
const int N=1e5+10;
struct edge{
    int u=0,v=0;
}e[M];
int head[N],to[M<<1],ne[M<<1],cnt=1;
int dfn[N],low[N],idx;
bool f=false;

void add(int a,int b){
    ne[++cnt]=head[a];
    to[cnt]=b;
    head[a]=cnt;
}

void tarjan(int u,int ine){
    dfn[u]=low[u]=++idx;
    for(int i=head[u];i;i=ne[i]){
        if((i^ine)!=1){
            int v=to[i];
            if(!(e[i>>1].u|e[i>>1].v)){
                e[i>>1]={u,v};
            }
            // cout<<u<<" "<<v<<'\n';
            if(!dfn[v]){
                tarjan(v,i);
                low[u]=min(low[u],low[v]);
                if(low[v]>dfn[u]){
                    f=true;
                }
            }else{
                low[u]=min(low[u],dfn[v]);
            }
        }
    }
}


void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    tarjan(1,0);
    if(f){
        cout<<"0";
    }else{
        // for(int u=1;u<=n;u++){
        //     for(int i=head[u];i;i=ne[i]){
        //         int v=to[i];
        //         cout<<u<<" "<<v<<" "<<i<<'\n';
        //     }
        // }
        for(int i=1;i<=m;i++){
            cout<<e[i].u<<" "<<e[i].v<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}