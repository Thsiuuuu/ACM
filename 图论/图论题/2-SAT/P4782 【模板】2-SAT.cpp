#include <bits/stdc++.h>
using namespace std;
const int N=2e6+2;
int n,m,dfn[N],low[N],t,tot,cnt,head[N],a[N],ans[N];
bool vis[N];
stack<int> s;

struct node{
    int to,next;
}e[N];

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
            a[cur]=cnt;
        }while(cur^u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,a,b;cin>>u>>a>>v>>b;
        if(a==1&&b==1){
            add(u+n,v);
            add(v+n,u);
        }else if(a==0&&b==1){
            add(u,v);
            add(v+n,u+n);
        }else if(a==1&&b==0){
            add(u+n,v+n);
            add(v,u);
        }else{
            add(u,v+n);
            add(v,u+n);
        }
    }
    for(int i=1;i<=2*n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        ans[i]=(a[i]<a[i+n]?1:0);
        if(a[i]==a[i+n]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    cout<<"POSSIBLE\n";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;   
}
