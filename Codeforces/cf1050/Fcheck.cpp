#include <bits/stdc++.h>
using namespace std;

#define int long long 
void sol(){

    int n;
    cin>>n;
    vector<vector<int>> vec(n+1);

    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        vec[i].resize(k+1);
        for(int j=1;j<=k;j++){
            cin>>vec[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=vec[i].size()-1;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<'\n';
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