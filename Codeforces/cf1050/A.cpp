#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>x>>n;
        if(n&1) cout<<x<<'\n';
        else cout<<"0\n";
    }
    return 0;
}