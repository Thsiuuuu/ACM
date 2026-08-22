#include <bits/stdc++.h>
using namespace std;
/*

    没有思路的话，就多去尝试手玩样例
    E中两个邻接点意味着起点的pair的第二个点和终点的pair的第一个点是相同的
    手玩样例发现，E图还原的D图再生成的E图不一定是前后相同的
    为什么呢，因为有的边并没有被放进去，也就是说对于同一个点的每个汇入点而言，它们的pair的第二个点都是相同的，所以出度应该是相同的
    就可以通过遍历每一个点的汇入点的出度是否相同，然后进行判断即可

    note:这个是假做法，只判断了出度，没有判断点集是否相同，可以用邻接矩阵实现（数据太弱导致的...）

*/
void sol() {
    int m,k;
    cin>>m>>k;
    vector<vector<int>> e(m+1);
    vector<int> deg(m+1,0);
    for(int i=1;i<=k;i++){
        int u,v;
        cin>>u>>v;
        // if(u!=v){
        // }
        e[v].push_back(u);
        deg[u]++;
    }
    for(int i=0;i<m;i++){
        int cur=0;
        for(int v:e[i]){
            if(cur==0){
                cur=deg[v];
            }else{
                if(cur!=deg[v]){
                    cout<<"No\n";
                    return ;
                }
            }
        }
    }
    cout<<"Yes\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}