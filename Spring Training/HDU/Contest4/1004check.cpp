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
    int cnt=50;
    while(cnt--){
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            a[i]=rand()%100001;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum^a[i];
        }
        bool f=true;
        for(int i=0;i<n;i++){
            if(a[i]>sum^a[i]){
                cout<<"yes\n";
                // for(int j=0;j<n;j++){
                //     cout<<a[j]<<" ";
                // }
                // cout<<'\n';
                f=false;
                break;
            }
        }
        if(f){
            cout<<"no\n";
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<'\n';
        }
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