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
    int n;
    cin>>n;
    ll ans=0,tmp=0;
    vector<ll> a(n,0);
    vector<pll> all(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        all[i].first=a[i];
        all[i].second=i;
    }
    sort(all.begin(),all.end(),greater<pll>());
    vector<ll> suf(n+1,-1),num(n+1,0);
    for(int i=n-1;i>=0;i--){
        if(suf[a[i]]==-1) suf[a[i]]=n-i;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<suf[i]<<'\n';
    // }
    ll s1=0,s2=0;
    for(int i=0,hgt=n;hgt;hgt--){
        while(i<n&&all[i].first==hgt){
            s1+=(n-all[i].second);
            i++;
            s2+=i;
        }
        // cout<<s1<<" "<<s2<<" "<<i<<'\n';
        num[hgt]=i;
        tmp+=(s1-s2);
    }
    ans=tmp;
    // cout<<tmp<<'\n';
    for(int hgt=n;hgt;hgt--){
        if(suf[hgt]!=-1){
            ans=max(ans,tmp-suf[hgt]+num[hgt]);
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