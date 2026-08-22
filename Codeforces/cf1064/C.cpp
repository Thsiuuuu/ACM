#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node{
    int val;
    int u,v;
    bool operator<(const node&others)const{
        return others.val<val;
    }
};
void sol(){
    int n;
    cin>>n;
    vector<int> a(n),vis(n+1,0),pre(n),nx(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i]=(i-1+n)%n;
        nx[i]=(i+1)%n;
    }
    priority_queue<node> que;
    for(int i=0;i<n;i++){
        que.push({max(a[i],a[(i+1ll)%n]),i,(i+1ll)%n});
    }
    int k=0;
    int ans=0;
    while(k<n-1){
        auto[val,u,v]=que.top();
        que.pop();
        if(vis[u]||vis[v]){
            continue;
        }
        if(val==a[u]){
            vis[v]=1;
            nx[u]=nx[nx[u]];
            pre[nx[v]]=u;
            que.push({max(a[u],a[nx[u]]),u,nx[u]});
        }else{
            vis[u]=1;
            pre[v]=pre[u];
            nx[pre[v]]=v;
            que.push({max(a[pre[v]],a[v]),pre[v],v});
        }
        ans+=val;
        k++;
    }
    cout<<ans<<'\n';
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