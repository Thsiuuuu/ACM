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
ll ans[10];
void sol() {
    ll h,w;
    cin>>h>>w;
    map<pii,bool> mp1;
    map<pii,bool> vis;
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp1[{x,y}]=true;
    }   
    auto check=[&](int x,int y)->bool{
        if(vis.find({x,y})!=vis.end()) return false; 
        if(x<1||x>h||y<1||y>w){
            return false;
        }
        vis[{x,y}]=true;
        return true;
    };
    auto check2=[&](int x,int y)->bool{
        if(x<1||x>h||y<1||y>w){
            return false;
        }
        return true;
    };
    ans[0]=(h-2)*(w-2);
    for(const auto&[key,val]:mp1){
        auto [x,y]=key;
        for(int i=x-2;i<=x;i++){
            for(int j=y-2;j<=y;j++){
                if(check(i,j)){
                    bool f=true;
                    int tot=0;
                    for(int nx=i;nx<=i+2;nx++){
                        for(int ny=j;ny<=j+2;ny++){
                            if(!check2(nx,ny)){
                                f=false;
                                break;
                            }
                            if(mp1.find({nx,ny})!=mp1.end()) tot++;
                        }
                        if(!f) break;
                    }
                    if(f){
                        ans[tot]++;
                        ans[0]--;
                    }
                }
            }   
        }
    }
    for(int i=0;i<=9;i++){
        cout<<ans[i]<<'\n';
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