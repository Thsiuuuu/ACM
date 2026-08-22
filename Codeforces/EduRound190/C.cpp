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
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    ll ans=0;
    ll sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1) sum1++;
        else ans+=a[i],sum2++;
    }
    if(n==1&&a[1]<=2){
        cout<<"0\n";
        return ;
    }
    if(sum2==1){
        ans+=min(ans/2,sum1);
    }else{
        for(int i=n;i>=1;i--){
            if(a[i]<4) break;
            ans+=min((a[i]-2)/2,sum1);
            sum1-=min((a[i]-2)/2,sum1); 
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