#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int N = 10001, M = 100010, INF = 0x3f3f3f3f;

int n,m;
int p[N];


int mar[102][102];

struct Edge
{
    int a, b, w;

    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges+m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mar[i][j];
            if(mar[i][j]!=-1) edges[m++]={i,j,mar[i][j]}; 
        }
    }

    int t=kruskal();
    cout<<t;

    return 0;
}

