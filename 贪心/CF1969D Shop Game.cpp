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
    int n,k;cin>>n>>k;
    // vector<pll> tt;
    VI a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    priority_queue<pll,vector<pll>,less<pll>> Q2;
    priority_queue<ll,VL,less<ll>> Q1;
    ll ans=0,res=0;
    for(int i=0;i<n;i++){
        if(b[i]>a[i]){
            Q2.push({b[i],a[i]});
            res+=b[i]-a[i];
        }
    }
    if(k==0){
        cout<<res<<'\n';
        return ;
    }
    if(Q2.size()<=k){
        cout<<"0\n";
        return ;
    }
    while(Q2.size()){
        while(Q2.size()&&Q1.size()<k){
            auto[B,A]=Q2.top();
            Q2.pop();
            Q1.push(A);
            res-=B;       
        }
        if(Q1.size()==k){
            ans=max(ans,res);
        }
        if(Q1.size()){
            auto A=Q1.top();
            res+=A;
            Q1.pop();
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