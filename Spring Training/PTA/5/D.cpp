#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define i128 __int128_t


vector<int> e[510];

void sol(){
    int n,m;
    cin>>n>>m;
    map<map<int,int>,int> mp;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int a,b;
    cin>>a>>b;
    int res=0;
    queue<pair<map<int,int>,int>> Q;
    map<int,int> fir;
    fir[a]=1;
    mp[fir]=1;
    Q.push(fir);
    bool f=true;
    while(Q.size()){
        auto [cur,u]=Q.front();Q.pop();
        if(u==b){
            res++;
            continue;
        }
        for(int v:e[u]){
            pair<map<int,int>,int> tmp=;
            tmp[v]=1;;
            if(mp.find(tmp)!=mp.end()){

                continue;
            }
            else mp[tmp]=1;
            Q.push(tmp);
        }
    }

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