#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n,q;
    cin>>n>>q;
    vector<int> pre(n+1,0),a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=n;i>=1;i--){
        if(i+1<=n){
            a[i]=max(a[i],a[i+1]);
        }
        a[i]=max(a[i],b[i]);
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<" ";
    }
    cout<<'\n';
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