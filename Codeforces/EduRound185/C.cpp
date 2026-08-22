#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long 

/*

    双指针，q从大到小，r从小到大，

*/

void sol(){
    int n,k;
    cin>>n>>k;
    vector<int> q(n),r(n);
    for(int i=0;i<n;i++) cin>>q[i];
    for(int i=0;i<n;i++) cin>>r[i];
    sort(q.begin(),q.end(),greater<int>());
    sort(r.begin(),r.end());
    int l=0;
    int ans=0;
    for(int i=0;i<n;i++){
        while((q[l]*(r[i]+1)+r[i]>k)&&(l<n)){
            l++;
        }
        if(l>=n) break;
        // cout<<i<<" "<<l<<'\n'; 
        ans++,l++;
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