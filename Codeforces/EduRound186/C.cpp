#include <bits/stdc++.h>
using namespace std;
#define int long long 
/*



*/
void sol() {
    int n;
    cin>>n;
    vector<int> a(2*n+1),b(2*n+1),c(2*n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    // for(int i=n+1;i<=2*n;i++){
    //     a[i]=a[i-n];
    //     b[i]=b[i-n];
    //     c[i]=c[i-n];
    // }
    int ans1=0;
    int ans2=0;
    for(int del=0;del<n;del++){
        bool f1=false;
        for(int i=0;i<n;i++){
            if(a[i]>=b[(i+del)%n]){
                f1=true;
                break;
            }
        }
        if(!f1) ans1++;
    }
    for(int del=0;del<n;del++){
        bool f1=false;
        for(int i=0;i<n;i++){
            if(b[i]>=c[(i+del)%n]){
                f1=true;
                break;
            }
        }
        if(!f1) ans2++;
    }
    cout<<ans1*ans2*n<<'\n';
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