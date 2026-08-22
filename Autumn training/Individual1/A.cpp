#include <bits/stdc++.h>
using namespace std;
#define int long long 

void change(int&mn,int& ans,int cur){
    ans=max(ans,cur-mn);
    mn=min(cur,mn);
}

void sol(){
    int n;
    cin>>n;
    vector<int> p(n+1,0),v(n+1,0),pre(n+1,0),b(n+1,0);
    int  mn1=11445141919810,mn2=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        v[i]=(p[i]+i)%2;
        pre[i]=pre[i-1]+v[i];
        b[i]=i-2*pre[i];
    }
    for(int i=1;i<=n;i++){
        change((i&1)?mn1:mn2,ans,b[i]);
    }
    cout<<ans+pre[n]<<'\n';
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