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



void sol() {
    int n;ll c,k;cin>>n>>c>>k;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        ll sum=0;
        if(a[i]<=c){
            sum+=min(c-a[i],k);
        }else{
            break;
        }
        k-=sum;
        c+=a[i]+sum;
    }
    cout<<c<<'\n';
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