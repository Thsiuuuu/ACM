#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int dp=0;
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        dp=max(dp,a[i]);
        if(i%2==0) a[i]=dp;
    }
    int ans=0;
    for(int i=1;i<=n;i+=2){
        int mn=1145141919810;
        if(i-1>0) mn=min(mn,a[i-1]);
        if(i+1<=n) mn=min(mn,a[i+1]);
        // if(a[i]-mn+1>0) cout<<i<<" "<<a[i]<<'\n';
        ans+=max(a[i]-mn+1,0ll);
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