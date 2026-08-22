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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int last=0;
    for(int i=n-1;i>=0;i--){
        int j=i;
        while(j>=0&&a[j]==a[i]){
            j--;
        }
        if(j>=0&&((i-j+last)%2==0||((a[i]-a[j])<=k))){
            cout<<"yes\n";
            return ;
        }
        if(j==-1||(a[i]-a[j])<=k) last+=(i-j);
        i=j+1;
        // else last=0;
        // cout<<i<<" "<<last<<'\n';
    }
    // cout<<"hel\n";
    if(last%2==0) cout<<"yes\n";
    else cout<<"no\n";
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