#include <bits/stdc++.h>
using namespace std;
/*

    A B两张图上分别判断：一个空点周围是否恰好有一个非空节点

    因为数量具有传递性，所以单纯的从相邻关系考虑不可以
    但是答案的边一定是割边，割边不一定是答案
    如果采用树形dp的方式统计子树的和的话，就可以轻松的解决
    割边算法本身就是基于dfs序建了一颗dfs树
    那么不难想到，如果割边之后一个子树A/B为满或0的话，一定是一个答案边
    因为断开之后必然会造成某一侧为0


*/

const int M=1e6+10;
const int N=1e5+10;
int low[N],dfn[N],idx;
int n,m,k,l;
int  A[N],B[N];//,Anew[N],Bnew[N];
vector<int> ans1,ans2;
vector<int> e[N];
// bool st[M<<1],
// int head[N],to[M<<1],nxt[M<<1];
// int cnt=1;
// int scc[N],siz;
// int stk[N],instk[N],top;

// struct node{
//     int v;
//     int oriu,oriv;
// };

// vector<node> e[N];
// set<pair<int,int>> ans;

// void add(int a,int b){
//     nxt[++cnt]=head[a];
//     to[cnt]=b;
//     head[a]=cnt;
// }

// void tarjan(int u,int ine){
//     dfn[u]=low[u]=++idx;
//     stk[++top]=u,instk[u]=1;
//     for(int i=head[u];i;i=nxt[i]){
//         int v=to[i];
//         if(!dfn[v]){
//             tarjan(v,i);
//             low[u]=min(low[u],low[v]);
//             if(low[v]>dfn[u]){
//                 st[i]=st[i^1]=true;        
//             }
//         }else if(i!=(ine^1)){
//             low[u]=min(low[u],dfn[v]);
//         }
//     }
//     if(low[u]==dfn[u]){
//         int v;++siz;
//         do{
//             v=stk[top--];
//             instk[v]=0;
//             scc[v]=siz;
//         }while(v^u);
//     }
// }


// void sol() {
//     cin>>n>>m>>k>>l;
    
//     for(int i=1;i<=k;i++){
//         int x;
//         cin>>x;
//         A[x]=true;
//     }
//     for(int i=1;i<=l;i++){
//         int x;
//         cin>>x;
//         B[x]=true;
//     }
//     for(int i=1;i<=m;i++){
//         int a,b;
//         cin>>a>>b;
//         add(a,b),add(b,a);
//     }
//     for(int i=1;i<=n;i++){
//         if(!dfn[i]){
//             tarjan(i,0);
//         }
//     }
//     for(int u=1;u<=n;u++){
//         if(A[u]) Anew[scc[u]]=true;
//         if(B[u]) Bnew[scc[u]]=true;
//         for(int i=head[u];i;i=nxt[i]){
//             int v=to[i];
//             if(st[i]){
//                 e[scc[u]].push_back({scc[v],u,v});
//                 e[scc[v]].push_back({scc[u],v,u});
//             }else{
//                 if(A[v]) Anew[scc[v]]=true;
//                 if(B[v]) Anew[scc[v]]=true;
//             }
//         }
//     }
//     for(int u=1;u<=siz;u++){

//         int ua,ub,va,vb;
//         ua=ub=va=vb=-1;
//         int Anumber,Bnumber;
//         Anumber=Bnumber=0;
//         for(auto [nwv,u,v]:e[u]){
//             if(Anew[nwv]){
//                 if(v>=u) swap(v,u);
//                 ua=u,va=v;
//                 Anumber++;
//             }else if(Bnew[nwv]){
//                 if(v>=u) swap(v,u);
//                 ub=u,vb=v;
//                 Bnumber++;
//             }
//         }
//         if(Anumber==1){
//             ans.insert({ua,va});
//         }
//         if(Bnumber==1){
//             ans.insert({ub,vb});
//         }
//     }
//     cout<<ans.size()<<'\n';
//     for(auto [u,v]:ans){
//         cout<<u<<" "<<v<<'\n';
//     }
// }

void tarjan(int u,int fa){
    dfn[u]=low[u]=++idx;
    for(int v:e[u]){
        if(!dfn[v]){
            if(v^fa){
                tarjan(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>dfn[u]){
                    if(!A[v]||!B[v]||A[v]==l||B[v]==k){
                        ans1.push_back(v),ans2.push_back(u);
                    }
                }
                A[u]+=A[v],B[u]+=B[v];
            }
        }else if(v^fa){
            low[u]=min(low[u],dfn[v]);
        }
    }
}

void sol(){
    cin>>n>>m>>l>>k;
    for(int i=1;i<=l;i++){
        int x;
        cin>>x;
        A[x]=1;
    }
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        B[x]=1;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b),e[b].push_back(a);
    }
    tarjan(1,0);
    cout<<ans1.size()<<'\n';
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" "<<ans2[i]<<'\n'; 
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