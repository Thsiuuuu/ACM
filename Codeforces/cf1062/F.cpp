#include <bits/stdc++.h>
using namespace std;

#define int long long 
const int N=2e5+10;
vector<int> e[N];
int siz[N],vis[N];
int n,k;
int ans=0,sum=0;

void dfs1(int u,int fa){
    siz[u]=1;
    for(int v:e[u]){
        if(v^fa){
            dfs1(v,u);
            siz[u]+=siz[v];
        }
    }
    if(siz[u]>=k){
        sum++;
    }
}

void dfs2(int u,int fa){

    ans+=sum;
    // vis[u]=1;
    for(int v:e[u]){
        if(v^fa){
            bool f1=false,f2=false;
            if(n-siz[v]<k){
                sum--;
                f1=true;
            }
            if(siz[v]<k){
                sum++;
                f2=true;
            }
            dfs2(v,u);
            if(f1){
                sum++;
            }
            if(f2){
                sum--;
            }
            siz[v]=n-siz[u];
            siz[u]=n;
        }
    }

}


void sol(){

    cin>>n>>k;
    for(int i=0,u,v;i<n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs1(1,0);
    dfs2(1,0);
    
    cout<<ans<<'\n';

    for(int i=1;i<=n;i++){
        e[i].clear();
        siz[i]=0;
        // vis[i]=0;
        ans=0;
        sum=0;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}