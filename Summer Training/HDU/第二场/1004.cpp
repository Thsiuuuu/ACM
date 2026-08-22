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
const int N=2e5+10;
ll ans[N],cur[N];
bool is[N];
struct P1{
    ll a,b;
    int idx;
    bool operator<(const P1&o)const{
        return b>o.b;
    }
};
struct P2{
    ll a,b,c;
    int idx;
    bool operator<(const P2&o)const{
        return b>o.b;
    }
};
void sol() {
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        is[i]=1;
        cur[i]=0;
    }
    for(int i=1;i<=m;i++){
        ans[i]=0;
    }
    vector<vector<P2>> all(n+1);
    for(int i=1;i<=m;i++){
        ll a,b,c;cin>>a>>b>>c;
        all[a].push_back({a,b,c,i});
    }
    priority_queue<P1,vector<P1>> Q1;
    priority_queue<P2,vector<P2>> Q2;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(cur[i]<all[i].size()){
            Q2.push(all[i][0]);
            cur[i]++;
            is[i]=0;
        }
    }
    ll tim=1;
    while(cnt<m){
        if(Q1.size()){
            tim=Q1.top().b;
            while(Q1.size()&&Q1.top().b==tim){
                auto[a,b,idx]=Q1.top();
                Q1.pop();
                if(cur[a]<all[a].size()&&is[a]){
                    Q2.push({a,all[a][cur[a]].b,all[a][cur[a]].c,all[a][cur[a]].idx});
                    cur[a]++;
                    is[a]=0;
                }
            }
        }
        while(Q1.size()<k&&Q2.size()){
            auto[a,b,c,idx]=Q2.top();
            Q2.pop();
            is[a]=1;
            Q1.push({a,max(b,tim)+c,idx});
            ans[idx]=max(b,tim);
            cnt++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    cout<<'\n';
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