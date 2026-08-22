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
const int N=3e5+10;
int a[N],b[N],d[N];
int c[N];
vector<pii> tg[N];
void sol() {
    int sum=0;
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>d[i]>>b[i];
        if(d[i]>1){
            if(c[a[i]]++==0) sum++;
        }else{
            if(c[b[i]]++==0) sum++;
        }
        tg[d[i]].push_back({a[i],b[i]});
    }    
    cout<<sum<<'\n';
    for(int i=2;i<=m;i++){
        for(const auto&[x,y]:tg[i]){
            if(--c[x]==0) sum--;
            if(c[y]++==0) sum++;
        }
        cout<<sum<<'\n';
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