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
    double a,b;
    cin>>a>>b;
    if(b<45){
        cout<<"0.0\n";
        return ;
    }
    double s=ceil(0.6*a+0.4*b);
    if(s>=95) cout<<"5.0\n";
    else if(s<60) cout<<"0.0\n";
    else{
        cout<<fixed<<setprecision(1)<<5-0.1*(95-s)<<'\n';
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