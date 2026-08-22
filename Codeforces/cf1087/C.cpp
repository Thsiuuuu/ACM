#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  



void sol() {
    int n;cin>>n;

    // if(n==2){
    //     // bool f=false;
    //     for(int j=2;j<=4;j++){
    //         cout<<"? "<<1<<" "<<j<<'\n';
    //         cout.flush();
    //         int x;cin>>x;
    //         if(x==1){
    //             cout<<"! 1\n";
    //             cout.flush();
    //             return ;
    //         }

    //     }
    // }

    for(int i=2;(i+1)<=2*n;i+=2){
        cout<<"? "<<i<<" "<<i+1<<'\n';
        cout.flush();
        int x;cin>>x;
        if(x){
            cout<<"! "<<i<<'\n';cout.flush();
            return ;
        }
    }
    // if(f){
    //     cout<<"! "<<a1<<'\n';
    //     cout.flush();
    // }else{
    // }
    cout<<"? 1 2\n";
    cout.flush();
    int x;cin>>x;
    if(x==1){
        cout<<"! 1\n";
        cout.flush();
    }else{
        cout<<"? 1 3"<<'\n';cout.flush();
        cin>>x;
        if(x==1){
            cout<<"! 1\n";
        }else{
            cout<<"! "<<2*n<<'\n';
        }
        cout.flush();
    }
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}