#include <bits/stdc++.h>
using namespace std;

#define int long long 

void sol(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int mx=INT64_MIN;
    int ans=0;
    for(int i=0;i<n;i++){
        int cur=min(k,a[i]);
        if(cur>mx){
            mx=cur;
            k-=cur;
        }
        ans+=mx;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}