#include <bits/stdc++.h>
using namespace std;

#define int long long
/*

    https://www.luogu.com.cn/problem/P2607

    因为树形dp的本质就是搜索所有的组合并得到最优解，所以说进行断环成链的时候并不会导致漏解
    但需要注意，断环会导致原有的临边的约束被解除了，可能会出现相邻的两个点都选中的一种组合，所以说需要去人为的避免
    分析所有合法解，可以发现有三种情况，选u不选v,选v不选u，不选u不选v，可以通过两次分别返回不选u和不选v覆盖到所有的解

    也就是说，这个dp的时候，需要注意u和v不能同时选，所以需要返回dp[u][0]和dp[v][0]并取最大值
    
    基环树找环的方法：
    1.并查集找环：
        遍历所有的边，检查u和v是否已经属于同一个集合，如果不属于同一个集合，进行合并；否则，(u,v)是这个环上进行闭合的一条边，记录下u和v，并跳过这条边不建图



*/

const int N=1e6+10;
vector<int> e[N],w(N);
vector<array<int,2>> dp(N);    

struct DSU{
    int num;
    vector<int> siz,fa;
    DSU(int num){
        siz.resize(num+1),fa.resize(num+1);
        for(int i=1;i<=num;i++){
            fa[i]=i;
            siz[i]=1;
        }
    }
    int find(int x){
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }
    void unite(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy) return ;
        if(siz[fx]<siz[fy]){
            swap(fx,fy);
        }
        siz[fx]+=siz[fy];
        fa[fy]=fx;
    }
};

int dfs(int u,int fa){
    dp[u][0]=0,dp[u][1]=w[u];
    for(int v:e[u]){
        if(v^fa){
            dfs(v,u);
            dp[u][0]+=max(dp[v][0],dp[v][1]);
            dp[u][1]+=dp[v][0];
        }
    }
    return dp[u][0];
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    DSU dsu(n+1);
    vector<array<int,2>> root;
    for(int u=1,v;u<=n;u++){
        cin>>w[u]>>v;
        if(dsu.find(u)==dsu.find(v)){
            root.push_back({u,v});
        }else{
            dsu.unite(u,v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    int ans=0;
    for(auto[r1,r2]:root){
        ans+=max(dfs(r1,0),dfs(r2,0));
    }
    cout<<ans;
    return 0;
}