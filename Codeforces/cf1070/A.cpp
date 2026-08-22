#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> a(n);
    int ans=0;
    int mx=-114151414;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(!i){
            mx=a[i];
        }else{
            if(mx>a[i]){
                ans++;
            }else{
                mx=a[i];
            }
        }
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