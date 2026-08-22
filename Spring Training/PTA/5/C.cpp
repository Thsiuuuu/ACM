#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define i128 __int128_t


int n,m;
vector<vector<ll>> a(210,vector<ll>(210,-1));


void sol(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=w;
    }
    int k;
    cin>>k;
    ll mn=1e18;
    int res=0,fir=0;
    for(int cnt=1;cnt<=k;cnt++){
        int q;
        cin>>q;
        vector<int> v(q);
        vector<bool> vis(n+1,0);
        for(int i=0;i<q;i++) cin>>v[i];
        v.push_back(0);
        ll sum=0;
        bool f=true;
        vis[v[0]]=1;
        if(q!=n) continue;
        if(a[0][v[0]]==-1) continue;
        sum+=a[0][v[0]];
        for(int i=0;i<q;i++){
            if(a[v[i]][v[i+1]]==-1||vis[v[i+1]]){
                f=false;
                break;
            }else{
                vis[v[i+1]]=1;
                sum+=a[v[i]][v[i+1]];
            }
        }
        if(f){
            res++;
            if(mn>sum){
                mn=min(mn,sum);
                fir=cnt; 
            }else if(mn==sum){
            }
            // cout<<cnt<<" "<<sum<<'\n';
        }
    }
    cout<<res<<'\n'<<fir<<" "<<mn;
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