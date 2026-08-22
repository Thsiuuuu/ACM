#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define double long double
#define i128 __int128_t
#define ull unsigned long long  

struct node{
    int x,y,d;
};

vector<int> match,e[310];
bool vis[310];

bool dfs(int u){
    for(int v:e[u]){
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v]||dfs(match[v])){
            match[v]=u;
            return true;
        }
    }
    return false;
}

void sol() {
    int n;
    cin>>n;
    match.assign(n+1,0);
    vector<bool> is(n+1,true);
    vector<node> a(n+1);
    vector<int> all;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].d;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!is[i]||i==j) continue;
            if(a[j].d==a[i].d){
                if(a[j].x==a[i].x){
                    if((a[i].d==0&&a[i].y>a[j].y)||(a[i].d==2&&a[i].y<a[j].y)) is[j]=false;
                }else if(a[j].y==a[i].y){
                    if((a[i].d==1&&a[i].x>a[j].x)||(a[i].d==3&&a[i].x<a[j].x)) is[j]=false;
                }
            }
        }
    }

    ll tot=0;
    for(int i=1;i<=n;i++) tot+=is[i];
    for(int i=1;i<=n;i++){
        if(!is[i]||(a[i].d&1)==0) continue;
        for(int j=1;j<=n;j++){
            if(!is[j]||(a[j].d&1)||j==i) continue;
            if((a[i].d==3&&a[j].x<=a[i].x)||(a[i].d==1&&a[j].x>=a[i].x)){
                if(a[j].d==0&&a[j].y<=a[i].y) e[i].push_back(j);
                if(a[j].d==2&&a[j].y>=a[i].y) e[i].push_back(j);
            }
        }
        all.push_back(i);
    }
    // for(int i=0;i<all.size();i++){
    //     for(int v:e[all[i]]){
    //         cout<<all[i]<<" "<<v<<'\n';
    //     }
    // }
    ll ans=0;
    for(int i=0;i<all.size();i++){
        memset(vis,false,sizeof(vis));
        ans+=dfs(all[i]);
    }
    for(int i=0;i<all.size();i++) e[all[i]].clear();
    cout<<tot-ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}