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

const int N=5002;
vector<int> e[N];
vector<ll> h;
int n,m;

bool check(int le,int ma){
    vector<bool> vis(n+1,false);
    vis[1]=true;
    queue<int> q;
    if(h[1]>=le&&h[1]<=ma){
        q.push(1);
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int v:e[u]){
            if(!vis[v]&&h[v]>=le&&h[v]<=ma){
                q.push(v);
                vis[v]=true;
            }
        }
    }
    return vis[2];
}   

void sol() {
    cin>>n>>m;
    h.assign(n+1,0);
    vector<ll> a;
    for(int i=1;i<=n;i++) cin>>h[i];
    a=h;
    sort(a.begin()+1,a.end());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans=INT32_MAX;
    for(int i=1,l=a[1],ridx=1,r=a[ridx];i<a.size();i++,l=a[i]){
        if(ridx>n) break;
        while(ridx<=n){
            if(!check(l,r)){
                // cout<<i<<" "<<ridx<<' ';
                // cout<<l<<" "<<r<<'\n';
                ridx++;
                if(ridx<=n) r=a[ridx];
            }else{
                ans=min(ans,r-l);
                break;
            }
        }
    }
    cout<<ans;
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