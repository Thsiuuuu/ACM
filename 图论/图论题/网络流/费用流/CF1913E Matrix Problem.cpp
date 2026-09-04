#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
template <typename Flow = long long, typename Cost = long long>
struct PrimalDualMCMF {
    const Flow INF_FLOW = 1e18;
    const Cost INF_COST = 1e18;

    struct Edge {
        int to;          // 目标点
        Flow cap;        // 残余容量
        Cost cost;       // 实际单位费用
        int rev;         // 反向边在 adj[to] 中的下标
    };

    int n;
    vector<vector<Edge>> adj;
    vector<Cost> h;          // Johnson 势能数组
    vector<Cost> dist;       // 重置边权后的最短路距离
    vector<int> prev_v;      // 最短路上点的前驱
    vector<int> prev_e;      // 最短路上边在前驱邻接表中的下标
    bool has_neg_edge;       // 标记是否有初始负权边

    PrimalDualMCMF(int n) 
        : n(n), adj(n + 1), h(n + 1, 0), dist(n + 1), 
          prev_v(n + 1), prev_e(n + 1), has_neg_edge(false) {}

    // 添加一条从 u 到 v，容量为 cap，费用为 cost 的有向边
    void addEdge(int u, int v, Flow cap, Cost cost) {
        if (cost < 0) has_neg_edge = true;
        adj[u].push_back({v, cap, cost, (int)adj[v].size()});
        adj[v].push_back({u, 0, -cost, (int)adj[u].size() - 1});
    }

    // 仅在原图有初始负权边时跑一次 SPFA 来初始化势能 h
    void init_potential(int s) {
        fill(h.begin(), h.end(), INF_COST);
        vector<bool> in_q(n + 1, false);
        queue<int> q;

        h[s] = 0;
        q.push(s);
        in_q[s] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_q[u] = false;

            for (const auto& edge : adj[u]) {
                if (edge.cap > 0 && h[edge.to] > h[u] + edge.cost) {
                    h[edge.to] = h[u] + edge.cost;
                    if (!in_q[edge.to]) {
                        q.push(edge.to);
                        in_q[edge.to] = true;
                    }
                }
            }
        }
    }

    // 运行 Dijkstra 寻找增广路
    bool dijkstra(int s, int t) {
        fill(dist.begin(), dist.end(), INF_COST);
        // 小顶堆：pair<距离, 点编号>
        using P = pair<Cost, int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dist[u] < d) continue;

            for (int i = 0; i < (int)adj[u].size(); ++i) {
                const auto& edge = adj[u][i];
                int v = edge.to;
                // 重置后的等效边权: w' = w + h[u] - h[v]
                Cost reduced_cost = edge.cost + h[u] - h[v];

                if (edge.cap > 0 && dist[v] > dist[u] + reduced_cost) {
                    dist[v] = dist[u] + reduced_cost;
                    prev_v[v] = u;
                    prev_e[v] = i;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[t] != INF_COST;
    }

    // 求解最小费用最大流，返回 pair<最大流, 最小费用>
    pair<Flow, Cost> solve(int s, int t) {
        Flow max_flow = 0;
        Cost min_cost = 0;

        // 1. 如果有初始负权边，跑一次 SPFA 初始化势能
        if (has_neg_edge) {
            init_potential(s);
        }

        // 2. 循环使用 Dijkstra 增广
        while (dijkstra(s, t)) {
            // 3. 更新所有点的势能: h[i] = h[i] + dist[i]
            for (int i = 1; i <= n; ++i) {
                if (dist[i] < INF_COST) {
                    h[i] += dist[i];
                }
            }

            // 4. 沿最短路寻找瓶颈容量
            Flow push = INF_FLOW;
            for (int v = t; v != s; v = prev_v[v]) {
                push = min(push, adj[prev_v[v]][prev_e[v]].cap);
            }

            // 5. 增广流量
            for (int v = t; v != s; v = prev_v[v]) {
                Edge& forward_edge = adj[prev_v[v]][prev_e[v]];
                Edge& reverse_edge = adj[v][forward_edge.rev];
                forward_edge.cap -= push;
                reverse_edge.cap += push;
            }

            max_flow += push;
            // 每次增广实际消耗的单位费用就是当前的势能差 (h[t] - h[s])
            min_cost += push * (h[t] - h[s]);
        }

        return {max_flow, min_cost};
    }
};
const int N=52;
int a[N][N],A[N],B[N],row[N],col[N];
void sol() {
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=m;i++) cin>>B[i];
    int rs,cs;rs=cs=0;
    for(int i=1;i<=n;i++) rs+=A[i];
    for(int i=1;i<=m;i++) cs+=B[i];
    if(rs^cs){
        cout<<"-1\n";
        return ;
    }
    PrimalDualMCMF<ll,ll> mf(n+m+2);
    int sum=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) sum+=a[i][j];
    int s=n+m+1,t=n+m+2;
    for(int i=1;i<=n;i++){
        mf.addEdge(s,i,A[i],0);
    }
    for(int i=1;i<=m;i++){
        mf.addEdge(i+n,t,B[i],0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mf.addEdge(i,j+n,1,!a[i][j]);
        }
    }
    auto[flow,cost]=mf.solve(s,t);
    if(flow^rs) cout<<"-1";
    else    cout<<sum+2*cost-rs;
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