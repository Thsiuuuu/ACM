#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

int a[12][12];

void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int cur=0;
    for(int i=1;i<=n;i++){
        sort(a[i]+1,a[i]+m+1);
        bool f=false;
        for(int j=1;j<=m;j++){
            if(a[i][j]>cur){
                f=true;
                cur=a[i][j];
                break;
            }
        }
        if(!f){
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}