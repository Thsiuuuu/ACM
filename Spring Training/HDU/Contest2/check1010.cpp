#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define double long double
#define i128 __int128_t
#define ull unsigned long long  

vector<int> res;

void dfs(int x,ll k){
    if(k==0) return ;
    // cout<<x<<" "<<k<<'\n';
    for(int i=1;i<=x;i++){
        if(k<=(1ll<<(x-i))){res.push_back(i);x-=i;k--;break;}
        else k-=(1ll<<(x-i));
    }
    dfs(x,k);
}



void sol() {
    i128 tmp=1;
    int l=0;
    cout<<(1ll<<63)<<" ";
    cout<<((tmp<<62)>=INT64_MAX);
    // while(l<126&&tmp<=INT64_MAX){
    //     tmp<<=1;
    //     l++;
    // }
    // cout<<l;
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