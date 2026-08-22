#include <bits/stdc++.h>
using namespace std;

// #define int long long 
/*

    非常恶心的一道题
    
    首先，可以对其中的一条路径进行dp
    考虑到最长公共路径一定是以某一个点为终点，所以可以按照终点进行dp
    如果说当前的点和另外一个点相邻的边是在另外一个图里面的话，就说明这个边就是一个公共边，就可以用这个点的值去更新邻接点的值

    注意这里需要正反跑两次拓扑排序进行dp，因为不能保证路径一定是同向的

    这里需要注意，进行dp的时候是要利用拓扑排序，而不是bfs，因为要保证单向图一个点的前驱节点都得到最优解之后才可以更新当前这个点

    接下来是怎么找最短路的所有边
    一条边在最短路上，不妨令s->u->v->t，当且仅当s到u的最短路和t到v的最短路和(u,v)的距离加起来等于总共的最短路的时候，这个边是最短路上的


*/

struct Graph{
    int n,m;
    int cnt=0;
    vector<int> head,nxt,to,wgt;
    Graph(int n_,int m_):n(n_),m(m_),head(n+1,0),nxt(2*m+1,0),to(2*m+1,0),wgt(2*m+1,0){}
    
    void addEdge(int u,int v,int w){
        nxt[++cnt]=head[u];
        to[cnt]=v;
        wgt[cnt]=w;
        head[u]=cnt;
    }
};

struct Edge{
    int u,v;
    int cost;
    bool operator<(const Edge&other)const{
        return tie(u,v,cost)<tie(other.u,other.v,other.cost);
    }
};

struct node{
    int u;
    int cost;
    bool operator<(const node&other)const{
        return cost>other.cost;
    }
};

void dijkstra(const Graph &G,vector<int>&dist,int st,int ed){
    int n=G.n;
    vector<int> visited(n+1,0);
    priority_queue<node> que;

    dist[st]=0;
    que.push({st,0});
    while(que.size()){
        auto[u,cost]=que.top();
        que.pop();
        if(visited[u]==1) continue;
        visited[u]=1;
        for(int e=G.head[u],v,w;e;e=G.nxt[e]){
            v=G.to[e],w=G.wgt[e];
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                que.push({v,dist[v]});
            }            
        }
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    Graph G(n,m),G1(n,m),G2(n,m);
    vector<int> dist1(n+1,INT_MAX),dist2(n+1,INT_MAX),dist3(n+1,INT_MAX),dist4(n+1,INT_MAX);
    int a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    for(int i=0,u,v,w;i<m;i++){
        cin>>u>>v>>w;
        G.addEdge(u,v,w);
        G.addEdge(v,u,w);
    }   
    dijkstra(G,dist1,a1,b1);
    dijkstra(G,dist2,b1,a1);
    dijkstra(G,dist3,a2,b2);
    dijkstra(G,dist4,b2,a2);



    set<Edge> st;

    vector<int> in1(n+1,0),in2;
    in2=in1;

    for(int u=1;u<=n;u++){
        for(int e=G.head[u],v,w;e;e=G.nxt[e]){
            v=G.to[e],w=G.wgt[e];
            if(w+dist1[u]+dist2[v]==dist1[b1]){
                G1.addEdge(u,v,w);
                in1[v]++;
                G2.addEdge(v,u,w);
                in2[u]++;
            }
            if(w+dist3[u]+dist4[v]==dist3[b2]){
                st.insert({u,v,w});
            }
        }
    }

    vector<int> dp1(n+1,0),dp2(n+1,0);
    dp1[a1]=0;
    queue<int> que;
    que.push(a1);




    for(int u=1;u<=n;u++){
        if(in1[u]==0){
            que.push(u);
        }
    }


    while(que.size()){  
        int u=que.front();
        que.pop();
        for(int e=G1.head[u],v,w;e;e=G1.nxt[e]){
            v=G1.to[e],w=G1.wgt[e];

            if(--in1[v]==0) que.push(v);
            if(st.find({u,v,w})!=st.end()){
                // cout<<u<<" "<<v<<" "<<w<<'\n';
                dp1[v]=max(dp1[v],dp1[u]+w);
            }
        }
    }


    dp2[a1]=0;
    que.push(a1);
    for(int u=1;u<=n;u++){
        if(in2[u]==0){
            que.push(u);
        }
    }
    while(que.size()){  
        int u=que.front();
        que.pop();
        for(int e=G2.head[u],v,w;e;e=G2.nxt[e]){
            v=G2.to[e],w=G2.wgt[e];

            if(--in2[v]==0) que.push(v);
            if(st.find({u,v,w})!=st.end()){
                // cout<<u<<" "<<v<<" "<<w<<'\n';
                dp2[v]=max(dp2[v],dp2[u]+w);
            }
        }
    }


    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<'\n';
    // }

    cout<<max(*max_element(dp1.begin(),dp1.end()),*max_element(dp2.begin(),dp2.end()));

    return 0;
}