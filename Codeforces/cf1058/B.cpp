#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    a[1]=1;
    int cnt=1;
    for(int i=2;i<=n;i++){
        int diff=b[i]-b[i-1];
        if(diff==i){
            a[i]=++cnt;
        }else{
            a[i]=a[i-diff];
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
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