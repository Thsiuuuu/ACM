#include <bits/stdc++.h>
using namespace std;

#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    sort(arr.begin(),arr.end());
    if(x<=arr[n-1]&&x>=arr[0]){
        cout<<"yes\n";
        return ;
    }

    cout<<"no\n";
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