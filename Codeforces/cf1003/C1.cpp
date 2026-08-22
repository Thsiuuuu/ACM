#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    a[1]=min(a[1],b[1]-a[1]);
    for(int i=2;i<=n;i++){
        if(min(a[i],b[1]-a[i])<a[i-1]){
            if(max(a[i],b[1]-a[i])<a[i-1]){
                cout<<"NO\n";
                return ;
            }else a[i]=max(a[i],b[1]-a[i]);
        }else{
            a[i]=min(a[i],b[1]-a[i]);
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