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

const ll mod=998244353;
void sol() {
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());

    ll res=0;
    string cur=a[1];
    bool f=false;
    for(int i=0;i<cur.size();i++){
        if(!f&&(cur[i]-'0')) f=true,res=cur[i]-'0';
        else if(f) res=(res*10%mod+cur[i]-'0')%mod;
    }
    cout<<res*n%mod<<'\n';
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