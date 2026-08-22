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
    priority_queue<ll,VL,greater<ll>> q2;
    priority_queue<ll,VL,less<ll>> q1;
    ll x;int q;cin>>x>>q;
    q2.push(x);
    auto ck=[&](int x)->void{
        if(q2.size()==0||x>=q2.top()) q2.push(x);
        else q1.push(x);
        int sz1=q1.size(),sz2=q2.size();
        if(sz2-sz1>1){
            q1.push(q2.top());
            q2.pop();
        }else if(sz1-sz2>0){
            q2.push(q1.top());
            q1.pop();
        }
    };
    while(q--){
        ll a,b;cin>>a>>b;
        ck(a);
        ck(b);
        // cout<<q1.size()<<" "<<q2.size()<<'\n';
        // cout<<q1.top()<<" "<<q2.top()<<'\n';
        cout<<q2.top()<<'\n';
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