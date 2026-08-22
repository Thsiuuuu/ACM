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
void sol() {
    int n;cin>>n;
    vector<int> r1,r2,r3,r4;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x%2==0&&x%3!=0) r1.push_back(x);
        else if(x%2!=0&&x%3!=0) r2.push_back(x);
        else if(x%2!=0&&x%3==0) r3.push_back(x);
        else r4.push_back(x);
    }
    for(auto x:r1) cout<<x<<" ";
    for(auto x:r2) cout<<x<<" ";
    for(auto x:r3) cout<<x<<" ";
    for(auto x:r4) cout<<x<<" ";
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