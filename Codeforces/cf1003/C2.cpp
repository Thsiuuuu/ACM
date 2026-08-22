#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n,m;
    cin>>n>>m;
    vector<ll> a(n+1),b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(b.begin()+1,b.end());
    a[1]=min(a[1],b[1]-a[1]);
    for(int i=2,j=1;i<=n;i++){
        cout<<i<<" "<<j<<" "<<a[i-1]<<'\n';
        while(j<=m&&max(a[i],b[j]-a[i])<a[i-1]){
            j++;
        }
        if(j>m){
            cout<<"NO\n";
            return ;
        }else{
            if(min(a[i],b[j]-a[i])<a[i-1]) a[i]=max(a[i],b[j]-a[i]);
            else a[i]=min(a[i],b[j]-a[i]);
        }
    }
    cout<<"YES\n";
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