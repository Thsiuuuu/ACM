#include <bits/stdc++.h>    
using namespace std;

#define int long long 
void sol(){


    int n;
    cin>>n;
    vector<int> arr(2*n+1);
    for(int i=1;i<=2*n;i++) cin>>arr[i];

    vector<int> pren(2*n+1,0),prep(2*n+1,0),presum(2*n+1,0);
    for(int i=1;i<=2*n;i++){
        pren[i]=((i&1)?-1:1)*arr[i]+pren[i-1];
        prep[i]=-pren[i];
        presum[i]=arr[i]+presum[i-1];
        // cout<<pren[i]<<" "<<prep[i]<<" "<<presum[i]<<'\n';
    }


    for(int k=1;k<=n;k++){
        if(k&1){
            cout<<(presum[2*n]-presum[2*n-k]-presum[k]+pren[2*n-k]-pren[k])<<" ";
        }else{
            cout<<(presum[2*n]-presum[2*n-k]-presum[k]+prep[2*n-k]-prep[k])<<" ";
        }
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}