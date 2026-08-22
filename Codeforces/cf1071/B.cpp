#include <bits/stdc++.h>
using namespace std;

#define int long long 

void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1){
            sum+=llabs(a[i]-a[i-1]);
        }
    }
    int mn=INT_MAX;
    for(int i=3;i<=n;i++){
        int cur=sum-llabs(a[i]-a[i-1])-llabs(a[i-1]-a[i-2]);
        cur+=llabs(a[i]-a[i-2]);
        mn=min(mn,cur);
    }
    mn=min(mn,sum-llabs(a[2]-a[1]));
    mn=min(mn,sum-llabs(a[n]-a[n-1]));
    cout<<mn<<'\n';
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