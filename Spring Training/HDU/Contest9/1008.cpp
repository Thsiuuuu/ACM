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
    i128 ans=0;
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"0\n";
        return ;
    }
    sort(a.begin(),a.end(),greater<ll>());
    i128 cur=a[0];
    for(int i=0;i+1<n;i++){
        ans+=cur;
        cur+=a[i+1];
    }
    
    stack<int> all;
    while(ans){
        all.push((int)(ans%10));
        ans/=10;
    }
    while(all.size()){
        cout<<all.top();
        all.pop();
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