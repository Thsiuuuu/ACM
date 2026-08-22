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


ll mp[10][10];

void sol() {

    bool f=true;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cin>>mp[i][j];if(mp[i][j]<=0||mp[i][j]>9) f=false;
        }
    }
    if(!f){ cout<<"0\n";return ;}

    for(int i=1;i<=9;i++){
        set<ll> st;
        for(int j=1;j<=9;j++){
            st.insert(mp[i][j]);
        }
        if(st.size()!=9) f=false; 
    }
    if(f){
        for(int j=1;j<=9;j++){
            set<ll> st;
            for(int i=1;i<=9;i++){
                st.insert(mp[i][j]);
            }
            if(st.size()!=9) f=false;
        }
    }
    if(f){
        for(int i=3;i<=9;i+=3){
            for(int j=3;j<=9;j+=3){
                set<ll> st;
                st.insert({mp[i][j],mp[i][j-1],mp[i][j-2],mp[i-1][j],mp[i-1][j-1],mp[i-1][j-2],mp[i-2][j],mp[i-2][j-1],mp[i-2][j-2]});
                if(st.size()!=9) f=false;
            }
        }
    }
    cout<<f<<'\n';
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