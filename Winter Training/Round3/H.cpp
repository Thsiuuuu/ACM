#include <bits/stdc++.h>
using namespace std;
/*

    贡献法
    如果一个点是被其他点带着消除的，那么它不会对答案产生贡献
    如果是主动消除的，会对总的操作次数有1的贡献

    根据期望的线性性，每个贡献的和的期望等于它们期望的和
    所以说需要求出每个点的操作次数的贡献的期望，就等价于这个点主动消除的概率，主动消除只有一种取法，被动消除可能是所有能够到达它的点的方法
    所以每个点主动消除的概率等于1/num(i),num(i)为包括自己在内所有可以到达它的点
    进行n轮dfs即可，时间复杂度不超过1e4

*/

vector<vector<int>> e;
vector<int> siz;
vector<int> vis;

void dfs(int u){
    for(int v:e[u]){
        if(!vis[v]){
            vis[v]=1;
            siz[v]++;
            dfs(v);
        }
    }
}

void sol() {
    int n;
    cin>>n;
    e.resize(n+1);
    siz.resize(n+1,1);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        s=' '+s;
        for(int j=1;j<=n;j++){
            if(s[j]-'0'){
                e[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        vis.assign(n+1,0);
        vis[i]=1;
        dfs(i);
    }
    long  double sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+(1.0/siz[i]);
    }
    cout<<fixed<<setprecision(12)<<sum;
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