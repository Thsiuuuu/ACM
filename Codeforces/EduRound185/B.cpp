#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    sort(b.begin(),b.end(),greater<int>());
    int l=0,r=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(b[i]){r=i;sum+=b[i];}
        else break;
    }
    if(sum==n) cout<<"1\n";
    else cout<<min(r-l+1,sum-n+1)<<'\n';
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