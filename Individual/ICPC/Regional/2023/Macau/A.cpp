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
const int N=4010;
int a[N],b[N],row[N],col[N],n;
char mp[N][N],is[N][N];
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='+') a[i]++,b[j]++,is[i][j]='1';
            else is[i][j]='0';
        }
    }
    for(int i=1;i<=n;i++){
        cin>>row[i];
    }
    for(int i=1;i<=n;i++) cin>>col[i];
    for(int i=1;i<=n;i++){
        if(a[i]<row[i]||b[i]<col[i]){
            return void(cout<<"No\n");
        }
        if(a[i]-n>row[i]||b[i]-n>col[i]){
            return void(cout<<"No\n");
        }
    }
    priority_queue<pll,vector<pll>,less<pll>> Q;
    for(int i=1;i<=n;i++){
        if(a[i]==row[i]) continue;
        Q.push({a[i]-row[i],i});
    }
    for(int i=1;i<=n;i++){
        if(b[i]==col[i]) continue;
        if(Q.empty()) {
            return void(cout<<"No\n");
        } 
        vector<pll> all;
        while(Q.size()){
            auto [val,id]=Q.top();Q.pop();
            if(--val>0) all.push_back({val,id});
            if(mp[id][i]=='-') is[id][i]='1';
            else is[id][i]='0';
            if(--b[i]==col[i]) break;
        }
        if(b[i]!=col[i]) {
            return void(cout<<"No\n");
        }
        for(auto P:all) Q.push(P); 
    }
    if(Q.size()) return void(cout<<"No\n");
    cout<<"Yes\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<is[i][j];
        cout<<'\n';
    }
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