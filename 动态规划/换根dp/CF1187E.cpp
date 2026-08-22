#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N=2e5+10;
vector<int> e[N];
int siz[N],ans=0,sum=0;
int n;

void dfs1(int u,int fa){
    siz[u]=1;
    for(int v:e[u]){
        if(v^fa){
            dfs1(v,u);
            siz[u]+=siz[v];
        }
    }
    sum+=siz[u];
}

void dfs2(int u,int fa){
    
    // cout<<sum<<'\n';
    
    ans=max(ans,sum);
    for(int v:e[u]){
        if(v^fa){

            int sizu=n-siz[v],sizv=siz[v];


            sum=sum+sizu-sizv;
            siz[u]=n-sizv;
            siz[v]=n;
            dfs2(v,u);
            siz[v]=sizv;
            siz[u]=n;
            sum=sum+sizv-sizu;
        }
    }
}

// void sol(){

// }
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(int i=0,u,v;i<n-1;i++){
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs1(1,0);

    // cout<<sum<<'\n';
    dfs2(1,0);

    cout<<ans<<'\n';
    return 0;
}