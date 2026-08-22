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
list<int> ans[201];
void init(){
    ans[2].push_back(2);
    ans[2].push_back(1);
    ans[2].push_back(1);
    ans[2].push_back(2);
    ans[2].push_back(1);
    ans[2].push_back(2);
    ans[2].push_back(2);
    ans[2].push_back(1);
    for(int i=3;i<=200;i++){
        ans[i]=ans[i-1];
        ans[i].pop_front();
        ans[i].push_front(i);
        ans[i].push_front(i-1);
        ans[i].push_front(i);
        ans[i].push_back(i);
        ans[i].push_back(i);
    }
}
void sol() {
    int n;
    cin>>n;
    for(int x:ans[n]){
        cout<<x<<" ";
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}