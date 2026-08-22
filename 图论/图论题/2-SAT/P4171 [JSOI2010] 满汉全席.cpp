#include <bits/stdc++.h>
using namespace std;
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
const int N=1e3+2;
int n,m,dfn[N],low[N],tt,tot,cnt,head[N],scc[N];
bool vis[N];
stack<int> s;

struct node{
    int to,next;
}e[N<<1];

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
    cin>>n>>m;
    tt=cnt=tot=0;
    while(s.size()) s.pop();
    for(int i=1;i<=2*n;i++){
        dfn[i]=low[i]=head[i]=scc[i]=vis[i]=0;
    }
    for(int i=0;i<m;i++){
        string s,t;cin>>s>>t;
        auto x=stoi(s.substr(1,(int)(s.size()-1))),
             y=stoi(t.substr(1,(int)(t.size()-1)));
        if(s[0]=='h'&&t[0]=='h'){
            add(x+n,y);
            add(y+n,x);
        }else if(s[0]=='m'&&t[0]=='m'){
            add(x,y+n);
            add(y,x+n);
        }else{
            if(s[0]=='m'){
                swap(s,t);
                swap(x,y);
            }
            add(y,x);
            add(x+n,y+n);
        }
    }
    for(int i=1;i<=2*n;i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        if(scc[i]==scc[i+n]){
            cout<<"BAD\n";
            return ;
        }
    }
    cout<<"GOOD\n";
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