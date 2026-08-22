#include <bits/stdc++.h>
using namespace std;

#define int long long 
void sol(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==b&&b==c&&c==d) cout<<"yes\n";
    else cout<<"no\n";
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