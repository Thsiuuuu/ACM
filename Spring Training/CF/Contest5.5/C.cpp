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
    int n,x;
    ll k;
    cin>>n>>x>>k;
    k%=(2*n);
    deque<int> l,r;
    for(int i=1;i<(n+1)/2;i++){
        l.push_front(i);
    }
    for(int i=(n+1)/2+1;i<=n;i++){
        r.push_back(i);
    }
    int cur=(n+1)/2;
    for(int cnt=0;cnt<k;cnt++){
        if(x==0){
            l.push_back(cur);
            cur=l.front();
            l.pop_front();
        }else{
            r.push_back(cur);
            cur=r.front();
            r.pop_front();
        }
        x^=1;
    }
    vector<int> ans;
    while(l.size()){
        ans.push_back(l.back());
        l.pop_back();
    }
    ans.push_back(cur);
    while(r.size()){
        ans.push_back(r.front());
        r.pop_front();
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
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