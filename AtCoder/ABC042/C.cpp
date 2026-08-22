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

bool f[10];

void sol() {
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int x;cin>>x;
        f[x]=true;
    }
    for(int i=n;;i++){
        int tmp=i;
        bool is=true;
        while(tmp){
            if(f[tmp%10]){
                is=false;
                break;
            }else tmp/=10;
        }
        if(is){
            cout<<i;
            return ;
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