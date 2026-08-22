#include <bits/stdc++.h>
using namespace std;
/*



*/
#define int long long 
void sol() {
    int s,k,m;
    cin>>s>>k>>m;
    if(k>m){
        cout<<max(s-m,0ll)<<'\n';
    }else if(k==m){
        if(s>=k){
            cout<<m<<'\n';
        }else{
            cout<<s<<'\n';
        }
    }else{
        if(s>k){
            if((m/k)&1) cout<<max(k-m%k,0ll)<<'\n';
            else cout<<max(s-m%k,0ll)<<'\n';
        }else  cout<<max(s-m%k,0ll)<<'\n';
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