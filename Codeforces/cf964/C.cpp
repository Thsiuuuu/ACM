#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    ll n,s,m;
    cin>>n>>s>>m;
    int l=0,r=0;
    bool f=false;
    for(int i=1;i<=n;i++){
        cin>>l;
        if(l-r>=s) f=true;
        cin>>r; 
    }
    if(m-r>=s) f=true;
    cout<<((f)?("yes"):("no"))<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}