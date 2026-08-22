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
    int n;
    cin>>n;
    VL a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cur=0;
    VI ans;
    for(int i=n-1;i>=0;i--){
        if(a[i]>0){
            if(!(cur&1)){
                cur++;
                ans.push_back(i+1);
            }
        }else{
            if(cur&1){
                cur++;
                ans.push_back(i+1);
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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