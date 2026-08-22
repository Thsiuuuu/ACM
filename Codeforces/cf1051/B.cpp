#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),b(k);
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    for(int i=0;i<k;i++) cin>>b[i];
    sort(a.begin()+1,a.end(),greater<int>());
    sort(b.begin(),b.end());
    int l=1;
    for(int i=0;i<b.size();i++){
        if(l+b[i]-1>n) break;
        else{
            ans-=(a[l+b[i]-1]);
            l+=b[i];
        }
    }
    cout<<ans<<'\n';

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}