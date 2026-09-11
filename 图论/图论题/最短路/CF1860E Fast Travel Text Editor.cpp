#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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
struct query{
    int s,t,ans;
};
struct edge{
    int u,w;
};
void sol() {
    string s;cin>>s;
    int n=s.size();
    int m;cin>>m;
    vector<query> a(m);
    for(int i=0;i<m;i++){
        cin>>a[i].s>>a[i].t;
        --a[i].s,--a[i].t;
        a[i].ans=abs(a[i].s-a[i].t);
    }  
    int k=n-1+26*26;
    vector<vector<edge>> g(k);
    for(int i=0;i<n-1;i++){
        int j=n-1+(s[i]-'a')*26+(s[i+1]-'a');
        g[i].push_back({j,0});
        g[j].push_back({i,1});
        if(i){
            g[i].push_back({i-1,1});
            g[i-1].push_back({i,1});
        }
    }
    for(int st=n-1;st<k;st++){
        VI d(k,1e9);
        d[st]=0;
        deque<int> q;
        q.push_back(st);
        while(q.size()){
            int v=q.front();
            q.pop_front();
            for(auto it:g[v]){
                if(d[it.u]<=d[v]+it.w) continue;
                d[it.u]=d[v]+it.w;
                if(it.w==0) q.push_front(it.u);
                else q.push_back(it.u);
            }
        }
        for(int i=0;i<m;i++){
            a[i].ans=min(a[i].ans,d[a[i].s]+d[a[i].t]-1);
        }
    }
    for(int i=0;i<m;i++) cout<<a[i].ans<<'\n';
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