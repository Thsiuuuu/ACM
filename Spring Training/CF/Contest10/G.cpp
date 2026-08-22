#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
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
    if(n<=3){
        for(int i=1;i<=n-1;i++){
            cout<<i<<" "<<i+1<<'\n';
        }
    }
    else if(n==4
        // ||(n+1)%3==1
    ){
        cout<<"-1\n";
    }else if((n+1)%3==1){
        int m=n;
        m-=1;
        int x=(m+1)/3*2;
        for(int i=1;i<x-1;i++){
            cout<<i<<" "<<i+1<<'\n';
        }
        for(int i=x;i<=m;i++){
            cout<<1<<" "<<i<<'\n';
        }
        cout<<x-1<<" "<<n<<'\n';
        // cout<<2<<" "<<n<<'\n';  
    }
    else{
        int m=n;
        if((n+1)%3==2){
            m-=2;
        }
        int x=(m+1)/3*2;
        for(int i=1;i<x-1;i++){
            cout<<i<<" "<<i+1<<'\n';
        }
        for(int i=x;i<=m;i++){
            cout<<1<<" "<<i<<'\n';
        }
        if((n+1)%3==2){
            cout<<x-1<<" "<<n-1<<'\n';
            cout<<2<<" "<<n<<'\n';
        }
    }
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