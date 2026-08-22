#include <bits/stdc++.h>
using namespace std;

#define int long long 


vector<vector<int>> e(7);
vector<int> visited(7,0),a(7);
int ans=0,cur=0;

void dfs(int level,int u){
    if(level==6){
        ans=max(cur,ans);
        return ;
    }
    for(int v:e[u]){
        if(!visited[v]){
            cur=cur*10+a[v];
            visited[v]=1;
            dfs(level+1,v);
            cur=cur/10;
            visited[v]=0;
        }
    }
}

void sol(){


    int st;
    for(int i=1;i<=6;i++){
        cin>>a[i];
    }

    int val=0;
    for(int i=1;i<=6;i++){
        if(a[i]>val){
            val=a[i];
            st=i;
        }
    }

    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(i&1){
                if(j==i||j==(i+1)){continue;}
                else e[i].push_back(j);
            }else{
                if(j==i||(j==(i-1))){continue;}
                else e[i].push_back(j);
            }
        }
    }


    cur=val;
    visited[st]=1;
    dfs(1,st);

    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}