#include <bits/stdc++.h>
using namespace std;

#define int long long
void sol(){
    vector<int> cnt(102,0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=0;i<=101;i++){
        if(!cnt[i]){
            cout<<i<<'\n';
            return ;
        }
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