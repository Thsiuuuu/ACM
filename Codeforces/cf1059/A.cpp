#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    cout<<a[0]<<'\n';
    
}
int main(){
    ios::sync_with_stdio(0);

    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}