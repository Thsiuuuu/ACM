#include <bits/stdc++.h>
using namespace std;

const int M=2e6+10;
const int N=5e5+10;
int head[N],nxt[M<<1],to[M<<1],low[N],dfn[N];
int cnt=1,idx;
void add(int x,int y){
    nxt[++cnt]=head[x];
    to[cnt]=y;
    head[x]=cnt;
}

struct bridge{
    int x,y;
    int number;
    bool operator<(const bridge&other)const{
        return number<other.number;
    }
};

vector<bridge> ans;

void Tarjan(int u,int ine){
    low[u]=dfn[u]=++idx;
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(!dfn[v]){
            Tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]) ans.push_back({u,v,i>>1});
        }else if(i!=(ine^1)){
            low[u]=min(low[u],dfn[v]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v),add(v,u);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) Tarjan(i,0);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].number<<" ";
    }
    return 0;
}