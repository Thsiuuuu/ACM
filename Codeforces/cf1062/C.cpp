#include <bits/stdc++.h>
using namespace std;

#define int long long 

void sol(){
    int n;
    cin>>n;
    int f1=0,f2=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]&1) f1=1;
        else f2=1;
    }
    if(f1&f2){
        sort(a.begin(),a.end());
        for(int x:a) cout<<x<<" ";
    }else{
        for(int x:a) cout<<x<<" ";
    }
    cout<<'\n';
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