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
void sol() {
    int n,m;
    cin>>n>>m;
    vector<pii> all;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        all.push_back({x,y});
    }   
    auto [a,b]=all[0];
    int last=-1;
    int ans=0;
    bool is=true;
    for(int i=0;i<m;i++){
        auto [x,y]=all[i];
        if(x!=a&&y!=a){
            if(last==-1) last=x;
            else if(last!=x&&last!=y){
                is=false;
                break;
            }
        }
    }
    if(last==-1){
        ans+=n-1;
    }else{
        last=-1;
        ans+=is;
        is=true;
            for(int i=0;i<m;i++){
            auto [x,y]=all[i];
            if(x!=a&&y!=a){
                if(last==-1) last=y;
                else if(last!=x&&last!=y){
                    is=false;
                    break;
                }
            }
        }
        ans+=is;
    }
    last=-1;
    is=true;
        for(int i=0;i<m;i++){
        auto [x,y]=all[i];
        if(x!=b&&y!=b){
            if(last==-1) last=x;
            else if(last!=x&&last!=y){
                is=false;
                break;
            }
        }
    }
    if(last==-1){
        ans+=n-1;
    }else{
        last=-1;
        ans+=is;
        is=true;
        for(int i=0;i<m;i++){
        auto [x,y]=all[i];
        if(x!=b&&y!=b){
            if(last==-1) last=y;
            else if(last!=x&&last!=y){
                is=false;
                break;
            }
        }
    }
        ans+=is;

    }
    is=true;
    for(int i=0;i<m;i++){
        auto[x,y]=all[i];
        if(x!=a&&x!=b&&y!=a&&y!=b){
            is=false;
            break;
        }
    }
    ans-=is;
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