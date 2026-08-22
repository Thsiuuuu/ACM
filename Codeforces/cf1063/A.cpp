#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=2;i<=n;i+=2){
        if((i+1<=n)&&(a[i]!=a[i+1])){
            cout<<"no\n";
            return ;
        }
    }
    cout<<"yes\n";
    // if((n-1)&1){
    //     cout<<"yes\n";
    // }else{
    // }
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