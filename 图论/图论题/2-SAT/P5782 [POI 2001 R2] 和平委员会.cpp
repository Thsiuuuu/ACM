#include <bits/stdc++.h>
using namespace std;
const int N=2e4+2;
const int M=4e4+10;
int n,m,dfn[N],low[N],t,tot,cnt,head[N],scc[N],ans[N];
bool vis[N];
stack<int> s;
struct node{
    int to,next;
}e[M];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
}

void tarjan(int u){
    dfn[u]=low[u]=++t;
    s.push(u);
    vis[u]=1;
    for(int i=head[u],v;i;i=e[i].next){
        v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int cur;
        ++cnt;
        do{
            cur=s.top();
            s.pop();
            vis[cur]=0;
            scc[cur]=cnt;
        }while(cur^u);
    }
}
int cal(int x){
    return (x&1)?x+1:x-1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        add(a,cal(b));
        add(b,cal(a));
    }
    for(int i=1;i<=2*n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=2*n;i+=2){
        ans[(i+1)/2]=(scc[i]<scc[i+1]?i:i+1);
        if(scc[i]==scc[i+1]){
            cout<<"NIE\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
    return 0;   
}
