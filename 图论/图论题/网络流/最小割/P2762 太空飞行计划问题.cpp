#include <bits/stdc++.h>
using namespace std;
/*



*/

#define ll long long 
const int N=102,M=2e4+10;
int n,m,tot=1,head[N],to[M],nxt[M],dep[N],cur[N];
ll val[M];
bool vis[N];
vector<int> ans1,ans2;

void add(int u,int v,ll w){
    to[++tot]=v,nxt[tot]=head[u],head[u]=tot,val[tot]=w;
}

void addedge(int u,int v,ll w){
    add(u,v,w),add(v,u,0);
}

int bfs(int s,int t){
    memset(dep,0,sizeof(dep));
    memcpy(cur,head,sizeof(head));
    queue<int> q;
    q.push(s),dep[s]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i];
            if(val[i]&&!dep[v]) q.push(v),dep[v]=dep[u]+1;
        }
    }
    return dep[t];
}

ll dfs(int u,int t,ll flow){
    if(u==t) return flow;
    ll ans=0;
    for(int &i=cur[u];i&&ans<flow;i=nxt[i]){
        int v=to[i];
        if(val[i]&&dep[v]==dep[u]+1){
            ll x=dfs(v,t,min(val[i],flow-ans));
            if(x) val[i]-=x,val[i^1]+=x,ans+=x;
        }
    }
    if(ans<flow) dep[u]=-1;
    return ans;
}

ll dinic(int s,int t){
    ll ans=0;
    while(bfs(s,t)){
        ll x;
        while((x=dfs(s,t,1e18))) ans+=x;
    }
    return ans;
}

void check(int u){//求出在S集合的最少点数
    vis[u]=1;
    for(int i=head[u];i;i=nxt[i]){
        int v=to[i];
        if(!vis[v]&&val[i]){
            if(v<=m) ans1.push_back(v);
            else ans2.push_back(v);
            check(v);
        }
    }
}

void sol() {

    cin>>m>>n;
    
    ll sum=0;
    string line;
    getline(cin,line);
    for(int i=1;i<=m;i++){
        string ss,token;
        getline(cin,ss);
        vector<string> number;
        istringstream iss(ss);
        while(iss>>token){
            number.push_back(token);
        }
        sum+=stol(number[0]);
        for(int j=0;j<number.size();j++){
            if(!j) addedge(0,i,stol(number[0]));
            else addedge(i,m+stol(number[j]),INT64_MAX);
        }
    }
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        addedge(m+i,n+m+1,x);
    }


    ll number=dinic(0,n+m+1);
    check(0);
    for(int x:ans1) cout<<x<<' ';
    cout<<'\n';
    for(int x:ans2) cout<<x-m<<' ';
    cout<<'\n'<<sum-number;
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