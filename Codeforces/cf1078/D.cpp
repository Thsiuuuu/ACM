#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
void sol() {
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> mp(n+1,vector<ll>(m+1,0));
    ll tot=0;
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            tot+=mp[i][j];
        }

    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            mp[i][j]+=mp[i-1][j];
        }
    }

    ll low=tot/2,sum=0;
    int cur=n;
    cout<<low*(tot-low)<<'\n';
    for(int j=1;j<=m;j++){
        while(cur>=1&&sum+mp[cur][j]>low){
            cur--;cout<<"D";
        }
        sum+=mp[cur][j];
        cout<<"R";
    }
    while(cur>=1){cur--;cout<<"D";}
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