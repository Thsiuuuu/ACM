#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int x,y;
    cin>>x>>y;
    vector<int> ans;
    for(int i=x;i>=y;i--){
        ans.push_back(i);
    }
    for(int i=y+1;i<x;i++){
        ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    for(int num:ans){
        cout<<num<<" ";
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