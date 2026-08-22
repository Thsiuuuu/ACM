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

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

const int N=1100;
int a[N],b[N],n,m;
int res[N][N];

void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]%b[j]!=0){
                cout<<"no";
                return ;
            }
        }
    }
    if(m==1){
        ll g=0;
        for(int i=1;i<=n;i++) g=gcd(g,a[i]);
        if(g!=b[1]){
            cout<<"no";
            return ;
        }
    }
    if(n==1){
        ll l=1;
        for(int i=1;i<=m;i++) l=lcm(l,b[i]);
        if(l!=a[1]){
            cout<<"no";
            return ;
        }
        else{
            cout<<"yes\n";
            for(int i=1;i<=m;i++){
                cout<<b[i]<<" ";
            }
            return ;
        }
    }
    cout<<"yes\n";
    int cur=1,k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==cur) res[i][j]=a[i];
            else res[i][j]=b[j];
        }
        if(cur==m) cur=0;
        cur++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}