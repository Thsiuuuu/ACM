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
void sol() {
    int n;cin>>n;
    VL a(n),d(n),l(n),r(n),vis(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>d[i];
        l[i]=i-1,r[i]=i+1;
    }
    l[0]=-1,r[n-1]=-1;
    VI all;
    for(int i=0;i<n;i++) all.push_back(i);
    for(int i=0;i<n;i++){
        VI si;
        for(int x:all){
            if(vis[x]) continue;
            ll sum=0;
            if(l[x]!=-1) sum+=a[l[x]];
            if(r[x]!=-1) sum+=a[r[x]];
            if(sum>d[x]){
                vis[x]=1;
                si.push_back(x);
            }
        }
        all.clear();
        for(int x:si){
            if(l[x]!=-1){r[l[x]]=r[x];all.push_back(l[x]);}
            if(r[x]!=-1){l[r[x]]=l[x];all.push_back(r[x]);}
        }
        cout<<si.size()<<' ';
    }
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