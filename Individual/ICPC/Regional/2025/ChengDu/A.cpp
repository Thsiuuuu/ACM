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
const ll M=1e9;
void out(vector<ll>& a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}
void sol() {
    int n;
    cin>>n;
    VL a(n),l(n),r(n),ans(n);
    ll L=0,R=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0){
            l[i]=0,r[i]=M/200-1;
            R+=M/200-1;
        }else if(a[i]==100){
            l[i]=M/200*(2*a[i]-1),r[i]=M;
            L+=M/200*(2*a[i]-1),R+=M;
        }else{
            l[i]=M/200*(2*a[i]-1),r[i]=M/200*(2*a[i]+1)-1;
            L+=M/200*(2*a[i]-1),R+=M/200*(2*a[i]+1)-1;
        }
    }
    if(M>=L&&M<=R){
        cout<<"yes\n";
        ll rem=M-L;
        for(int i=0;i<n;i++){
            ans[i]+=min(rem,r[i]-l[i])+l[i];
            rem-=min(rem,r[i]-l[i]);
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }else{
        cout<<"No\n";
    }
    
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