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
    int n,m;cin>>n>>m;
    VII a(n+1,VI(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int cur=-1;
    VII w(n+2,VI(m+2,0));
    VII pre(m*n+1),suf(m*n+1),pos(m*n+1);
    for(int i=1;i<=n;i++){
        map<int,int>mp;
        for(int j=1;j<=m;j++){
            if(!mp.count(a[i][j])){
                mp[a[i][j]]=1;
                pos[a[i][j]].push_back(i);
                pre[a[i][j]].push_back(min(j,(pre[a[i][j]].size()?pre[a[i][j]].back():(int)(1e9))));
            }
        }
    }
    for(int i=n;i>=1;i--){
        map<int,int>mp;
        for(int j=m;j>=1;j--){
            if(!mp.count(a[i][j])){
                mp[a[i][j]]=1;
                suf[a[i][j]].push_back(max(j,(suf[a[i][j]].size()?suf[a[i][j]].back():(int)(-1))));
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        reverse(suf[i].begin(),suf[i].end());
    }
    auto add=[&](int x1,int x2,int y1,int y2)->void{
        w[x1][y1]++,w[x2+1][y1]--,w[x1][y2+1]--,w[x2+1][y2+1]++;
    };
    for(int x=1;x<=n*m;x++){
        for(int i=0;i+1<pos[x].size();i++){
            if(pre[x][i]<suf[x][i+1]){
                add(pos[x][i],pos[x][i+1],pre[x][i],suf[x][i+1]);
            }   
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            w[i][j]=w[i][j]+w[i][j-1]+w[i-1][j]-w[i-1][j-1];
            cout<<(w[i][j]>0);
        }
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