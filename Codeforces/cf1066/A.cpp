#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> a(n),but(n+1,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        but[a[i]]++;
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(but[i]==0){
            
        }else{
            if(but[i]>=i){
                ans+=but[i]-i;
            }else{
                ans+=but[i];
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