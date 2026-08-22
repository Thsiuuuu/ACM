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
ll sg[1010];
int a[3];
void sol() {
    for(int i=0;i<3;i++) cin>>a[i];
    for(int L=1;L<=1000;L++){
        set<int> s;
        for(int i=0;i<3;i++){
            if(a[i]>L) continue;
            else{
                for(int j=1;a[i]+j-1<=L;j++){
                    int xr=0;
                    if(j-1>0) xr^=sg[j-1];
                    if(a[i]+j<=L) xr^=sg[L-a[i]-j+1];
                    s.insert(xr);
                }
            }
        }
        for(int x=0;;x++){
            if(s.find(x)==s.end()){
                sg[L]=x;
                break;
            }
        }
    }
    int n;cin>>n;
    while(n--){
        int x;cin>>x;
        cout<<(sg[x]==0)+1<<'\n';
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