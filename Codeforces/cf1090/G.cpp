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

const ll mod=676767677;
void sol() {
    int n,m;
    cin>>n>>m;
    vector<ll> b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(b[i]==0) continue;
        if(i-1>=0&&b[i-1]<b[i]) continue;
        if(i+1<n&&b[i+1]<b[i]) continue;
        cout<<"0\n";
        return ;
    }
    vector<ll> all(m,0),cpy;
    cpy=b;
    sort(cpy.begin(),cpy.end());
    ll ans=1;
    for(int i=1,idx=0;i<m;i++){
        while(idx<n&&cpy[idx]<i) idx++;
        all[i]=idx;
    }
    for(int i=0;i<n;i++){
        if(b[i]==0) continue;
        ll mn=INT32_MAX;
        if(i+1<n) mn=min(mn,b[i+1]);
        if(i-1>=0) mn=min(mn,b[i-1]);
        // cout<<mn<<" ";
        if(
            // i==0||i==n-1||
                (b[i]==
                    mn
                    // min(b[i-1],b[i+1])
                    +1)
            ) ans=ans*all[b[i]]%mod;
        else ans=ans*(all[b[i]]-all[b[i]-1]+mod)%mod;
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