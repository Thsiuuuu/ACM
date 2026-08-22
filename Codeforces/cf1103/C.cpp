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
    ll a,b,x;
    cin>>a>>b>>x;
    if(a>b) swap(a,b);
    if(a==b){
        cout<<"0\n";
        return ;
    }
    ll ans=b-a;
    // int tim=0;
    ll ca=a,cb=b;
    vector<pll> fa,fb;
    for(int i=0;;i++){
        fa.push_back({ca,i});
        if(ca==0) break;
        ca/=x;
    }
    for(int i=0;;i++){
        fb.push_back({cb,i});
        if(cb==0) break;
        cb/=x;
    }
    for(int i=0;i<fa.size();i++){
        for(int j=0;j<fb.size();j++){
            ans=min(ans,abs(fa[i].first-fb[j].first)+fa[i].second+fb[j].second);
        }
    }
    cout<<ans<<'\n';
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