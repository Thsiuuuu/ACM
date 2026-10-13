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
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
const int N=2e5+10;
VI e[N];
int a[N],vis[N];
int n,m,k,cnt;
vector<pair<int,VI>> ans(N);
void sol() {
    cin>>n>>m>>k;
    if(k){
        for(int i=0;i<k;i++){
            int x;cin>>x;
            a[x]=1;
        }
    }else{
        string s;getline(cin,s);
        // cout<<s;
    }
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    queue<int> Q;
    for(int i=1;i<=n;i++){
        if(!a[i]){
            Q.push(i);
            vis[i]=1;
            break;
        }
    }
    while(Q.size()){
        auto u=Q.front();
        Q.pop();
        if(a[u]) continue;
        bool is=false;
        for(int v:e[u]){
            if(vis[v]) continue;
            else{
                Q.push(v);
                vis[v]=1;
                is=1;
                ans[cnt].first=u,ans[cnt].second.push_back(v);
            }
        }
        if(is) cnt++;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"No\n";
            return ;
        }
    }
    cout<<"Yes\n";
    cout<<cnt<<'\n';
    for(int i=0;i<cnt;i++){
        cout<<ans[i].first<<" "<<ans[i].second.size();
        for(int v:ans[i].second) cout<<" "<<v;
        cout<<'\n';
    }
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