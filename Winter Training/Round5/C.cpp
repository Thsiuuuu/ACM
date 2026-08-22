#include <bits/stdc++.h>
using namespace std;
/*

    首先，一个相互联通的环的内部是可以拿到每一个点的，但是如果走出了这个环，就没办法再走回来了
    这个题很明显可以采用dp去做，但是dp要求是有向无环图，所以说不能在原图上跑dp
    根据上面两个启发，可以采用缩点，把每一个强联通分量都缩为一个点，这样就把所有环都消去了，然后在新的点上面建边
    但是需要注意，因为这个题设置了起点，所以说如果起点无法访问到某一个点，那么它是不能参与进任意一个强联通分量里面的，因为无法通过起点到达这个点，再从这个点到达其他点，所以需要记录一下起点可以访问到哪里
    然后就是一张有向无环图，利用拓扑排序，从前向后跑一遍dp，记录每个强联通分量能拿到的最大值是多少，去每个酒吧所在强联通分量的最大值就可以

*/
#define int long long 

const int N=5e5+10;
vector<int> e[N],a;

int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;

int vis[N];

int dp[N];

void tarjan(int u){

    if(vis[u]==0){
        return ;
    }
    dfn[u]=low[u]=++tot;
    stk[++top]=u,instk[u]=1;
    for(int v:e[u]){
        if(!dfn[v]){
            if(vis[v]==0){
                continue;
            }
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }else if(instk[v]){
            low[u]=min(dfn[v],low[u]);
        }
    }
    if(dfn[u]==low[u]){
        int v;cnt++;
        do{
            v=stk[top--];instk[v]=0;
            scc[v]=cnt;
            siz[cnt]++;
        }while(v^u);
    }
}


void sol() {
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
    }
    
    
    a.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s,p;
    cin>>s>>p;
    vector<int> bar(p+1);
    for(int i=1;i<=p;i++){
        cin>>bar[i];
    }


    queue<int> que;
    que.push(s);
    while(que.size()){
        int u=que.front();
        que.pop();
        vis[u]=1;
        for(int v:e[u]){
            if(vis[v]==0){
                que.push(v);
            }
        }
    }



    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }

    // for(int i=1;i<=n;i++){
    //     if(vis[i]==0){
    //         continue;
    //     }
    //     cout<<i<<" 的scc"<<scc[i]<<'\n';
    // }

    vector<int> deg(cnt+1,0),val(cnt+1,0);
    vector<vector<int>> pt(cnt+1);
    
    
    for(int u=1;u<=n;u++){
        if(vis[u]==0){
            continue;
        }
        val[scc[u]]+=a[u];
        for(int v:e[u]){
            if(scc[v]!=scc[u]){
                pt[scc[u]].push_back(scc[v]);
                deg[scc[v]]++;
            }
        }
    }

    for(int u=1;u<=cnt;u++){
        if(deg[u]==0){
            que.push(u);
        }
    }

    while(que.size()){
        int u=que.front();
        que.pop();
        dp[u]+=val[u];
        for(int v:pt[u]){
            if(--deg[v]==0){
                que.push(v);
            }
            dp[v]=max(dp[v],dp[u]);
        }
    }

    int mx=0;
    for(int i=1;i<=p;i++){
        if(vis[bar[i]]==0){
            continue;
        }
        mx=max(mx,dp[scc[bar[i]]]);
    }
    cout<<mx;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}