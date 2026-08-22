#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN = 101;
const int MAXM = 10001;

int path[MAXM];
int dist[MAXN][MAXN];
int n, m, ans;

// 初始时设置任意两点之间的最短距离为无穷大，表示任何路不存在
void build() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] =(i==j)?0:INT_MAX;
        }
    }
}

void floyd() {
    // O(N^3)的过程
    // 枚举每个跳板
    // 注意，跳板要最先枚举！跳板要最先枚举！跳板要最先枚举！
    for (int bridge = 0; bridge < n; bridge++) { // 跳板
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // i -> .....bridge .... -> j
                // distance[i][j]能不能缩短
                // distance[i][j] = min ( distance[i][j] , distance[i][bridge] + distance[bridge][j])
                if (dist[i][bridge] != INT_MAX 
                        && dist[bridge][j] != INT_MAX
                        && dist[i][j] > dist[i][bridge] + dist[bridge][j]) {
                    dist[i][j] = dist[i][bridge] + dist[bridge][j];
                }
            }
        }
    }
}

int main() {


    cin>>n;

    build();


    for(int i=1;i<=n;i++){
        int u,k;
        cin>>u>>k;
        while(k--){
            int v,c;
            cin>>v>>c;
            dist[u][v]=c;
        }
    }

    floyd();

    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[0][i]<<"\n";
    }

    return 0;
}