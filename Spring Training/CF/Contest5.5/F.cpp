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

struct node{
    int x,y,z;
    node(int x,int y,int z):x(x),y(y),z(z){}
};

void sol() {
    int a,b,c;
    cin>>a>>b>>c;
    vector<node> res;
    int cnt=max(a,b);
    for(int z=1;z<=c;z++){
        for(int i=0,x=z%a+1,y=1;i<cnt;x=x%(a)+1,y=y%(b)+1,i++){
            res.push_back(node(x,y,z));
        }
    }
    cout<<res.size()<<'\n';
    for(int i=0;i<res.size();i++){
        auto [x,y,z]=res[i];
        cout<<x<<" "<<y<<" "<<z<<'\n';
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