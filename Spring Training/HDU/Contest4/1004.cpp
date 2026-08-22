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
void sol() {
    int n;
    cin>>n;
    vector<int> a(n,0),f(1<<n,0);
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=1;i<(1<<n);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) sum^=a[j];
        }
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                if(f[i^(1<<j)]==0&&(a[j]>(sum^a[j]))){
                    f[i]=1;
                    break;
                }
            }
        }
    }
    cout<<(f[(1<<n)-1]?"Left":"Right")<<'\n';
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