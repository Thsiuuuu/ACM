#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n,y,r;
    cin>>n>>y>>r;
    cout<<min(y/2+r,n)<<'\n';
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