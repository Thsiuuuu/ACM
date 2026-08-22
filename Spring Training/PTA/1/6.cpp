#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  


int sum[102];
double a[102];

void sol() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int x,y;
    while(1){
        if(x==0&&y==0) break;
        cin>>x>>y;sum[x]+=y;
    }
    double ans=0;
    for(int i=1;i<=n;i++){
        cout<<sum[i]<<'\n';
        ans+=a[i]*sum[i];
    }
    cout<<fixed<<setprecision(2)<<ans;
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