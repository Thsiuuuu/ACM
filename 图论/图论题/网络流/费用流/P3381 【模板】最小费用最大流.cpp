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
struct DinicMCMF {
    const Flow INF_FLOW = 1e18;
    const Cost INF_COST = 1e18;

    struct Edge {
        int to;          // 目标点
        Flow cap;        // 残余容量
        Cost cost;       // 单位费用
        int rev;         // 反向边在邻接表中的下标
    };

    int n;
    vector<vector<Edge>> adj;
    vector<Cost> dist;
    vector<int> cur;
    vector<bool> in_queue;
    vector<bool> vis;

    DinicMCMF(int n) : n(n), adj(n + 1), dist(n + 1), cur(n + 1), in_queue(n + 1), vis(n + 1) {}

    // 添加有向边 (u -> v, 容量 cap, 单位费用 cost)
    void addEdge(int u, int v, Flow cap, Cost cost) {
        adj[u].push_back({v, cap, cost, (int)adj[v].size()});
        adj[v].push_back({u, 0, -cost, (int)adj[u].size() - 1});
    }

    // SPFA 寻找单位费用最短路
    bool spfa(int s, int t) {
        fill(dist.begin(), dist.end(), INF_COST);
        fill(in_queue.begin(), in_queue.end(), false);
        queue<int> q;

        dist[s] = 0;
        q.push(s);
        in_queue[s] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue[u] = false;

            for (const auto& edge : adj[u]) {
                if (edge.cap > 0 && dist[edge.to] > dist[u] + edge.cost) {
                    dist[edge.to] = dist[u] + edge.cost;
                    if (!in_queue[edge.to]) {
                        q.push(edge.to);
                        in_queue[edge.to] = true;
                    }
                }
            }
        }
        return dist[t] != INF_COST;
    }

    // DFS 多路增广
    Flow dfs(int u, int t, Flow push, Cost &total_cost) {
        if (u == t || push == 0) return push;
        vis[u] = true;
        Flow flow = 0;

        for (int &i = cur[u]; i < (int)adj[u].size(); ++i) {
            Edge &edge = adj[u][i];
            int v = edge.to;

            // 必须是最短路 DAG 上的边，且该点未在当前 DFS 搜索路径上
            if (!vis[v] && edge.cap > 0 && dist[v] == dist[u] + edge.cost) {
                Flow tr = dfs(v, t, min(push, edge.cap), total_cost);
                if (tr > 0) {
                    edge.cap -= tr;
                    adj[v][edge.rev].cap += tr;
                    total_cost += tr * edge.cost;
                    flow += tr;
                    push -= tr;
                    if (push == 0) break;
                }
            }
        }
        vis[u] = false; // 回溯
        return flow;
    }

    // 返回 pair<最大流, 最小费用>
    pair<Flow, Cost> solve(int s, int t) {
        Flow max_flow = 0;
        Cost min_cost = 0;

        while (spfa(s, t)) {
            fill(cur.begin(), cur.end(), 0);
            fill(vis.begin(), vis.end(), false);
            Flow flow = 0;
            while ((flow = dfs(s, t, INF_FLOW, min_cost)) > 0) {
                max_flow += flow;
            }
        }
        return {max_flow, min_cost};
    }
};
void sol(){
    int n,m,s,t;
    cin>>n>>m>>s>>t;
	DinicMCMF<ll,ll> mcmf(n);
    for(int i=0;i<m;i++){
		int u,v;ll cap,cost;
        cin>>u>>v>>cap>>cost;
        mcmf.addEdge(u,v,cap,cost);
    }
    auto [maxflow,mincost]=mcmf.solve(s,t);
    cout<<maxflow<<" "<<mincost<<'\n';
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