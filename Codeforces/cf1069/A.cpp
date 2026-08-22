#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> num(1010,0);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        num[a[i]]++;
        if(num[a[i]]==1){
            sum++;
        }
    }
    sort(a.begin(),a.end());
    auto fd=lower_bound(a.begin(),a.end(),sum);
    if(fd!=a.end()){
        cout<<*fd<<'\n';
    }else{
        cout<<((int)1e18-(*fd))<<'\n';
    }
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