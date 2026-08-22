#include <bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=1e5+2;
vector<int> e[N];
int n,root,q;
int dep[N],st[N][21];
bool vis[N];
int ans=-1;

void dfs(int u,int fa){
    st[u][0]=fa,dep[u]=dep[fa]+1;
    for(int i=1;i<=20;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    for(int v:e[u]) dfs(v,u);
}

int LCA(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=20;i>=0;i--){
        if(dep[u][i]<=dep[v]) u=dep[u][i];
    }
    if(u==v) return u;
    for(int i=20;i>=0;i--){
        if(st[u][i]!=st[v][i]){
            v=st[v][i],u=st[u][i];
        }
    }
    return st[u][0];
}


void sol(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==-1) root=i;
        else e[x].push_back(i);
    }
    dfs(root,0);
    vis[0]=1;
    int cur=root;
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        if(!vis[x]){
            int u=x,v=x;
            for(int p=20;p>=0;p--){
                if(vis[st[u][p]]) continue;
                u=st[u][p];
            }
            cout<<u<<"   ||  ";
            u=st[u][0];
            while(v!=u){
                cout<<v<<" ";
                vis[v]=true;
                ans++;
                v=st[v][0];
            }
        }else{
            cur=x;
        }
        cout<<ans<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}