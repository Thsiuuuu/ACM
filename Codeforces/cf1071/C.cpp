#include <bits/stdc++.h>
using namespace std;

#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end());
    int l=a[1],r=a[2]-1ll;
    int mn=INT_MAX;
    for(int i=2;i<=n;i++){
        int del=a[i]-a[1];
        if(del<=a[1]){
            cout<<l<<'\n';
            return ;
        }else{
            mn=min(mn,del);
        }
    }
    cout<<mn<<'\n';
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