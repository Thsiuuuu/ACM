#include <bits/stdc++.h>
using namespace std;
/*

    判断任意两对夫妻之间是否有完全的矛盾即可

    上面记于2025/10/9 18:28

    更新：于2026/7/25正式学了2-SAT，一拖再拖终于学了。。。
    很简单的建图，然后跑2-SAT就可以
    记于2026/7/25 23:55:46
*/
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
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
const int N=2e3+2;
int n,m,dfn[N],low[N],tt,tot,cnt,head[N],scc[N];
bool vis[N];
stack<int> s;

struct node{
    int to,next;
}e[N*N];

void add(int u,int v){
    e[++tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
}

void tarjan(int u){
    dfn[u]=low[u]=++tt;
    s.push(u);
    vis[u]=1;
    for(int i=head[u],v;i;i=e[i].next){
        v=e[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int cur;
        ++cnt;
        do{
            cur=s.top();
            s.pop();
            vis[cur]=0;
            scc[cur]=cnt;
        }while(cur^u);
    }
}

void sol(){
    while(cin>>n>>m){
        for(int i=1;i<=2*n;i++){
            head[i]=scc[i]=dfn[i]=low[i]=vis[i]=0;
        }
        tot=tt=cnt=0;
        while(s.size() ) s.pop();
        for(int i=0;i<m;i++){
            int u,v,a,b;cin>>u>>v>>a>>b;
            u++,v++;
            if(a&&b){
                add(u,v+n);
                add(v,u+n);
            }else if(!a&&!b){
                add(u+n,v);
                add(v+n,u);
            }else{
                if(b){
                    swap(u,v);
                    swap(a,b);
                }
                add(u,v);
                add(v+n,u+n);
            }
        }
        for(int i=1;i<=2*n;i++){
            if(!dfn[i]) tarjan(i);
        }
        bool f=true;
        for(int i=1;i<=n;i++){
            if(scc[i]==scc[i+n]){
                cout<<"NO\n";
                f=false;
                break;
            }
        }
        if(f){
            cout<<"YES\n";
        }
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