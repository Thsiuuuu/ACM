#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n,l,r;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==n) l=r=i;
    }
    for(int i=n-1;i>=1;i--){
        if((l-1)>=1&&a[l-1]==i) l--;
        else if((r+1)<=n&&a[r+1]==i) r++;
    }
    if(r-l+1==n) cout<<"yes\n";
    else cout<<"no\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}