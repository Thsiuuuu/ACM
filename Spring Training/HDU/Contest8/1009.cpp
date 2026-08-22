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
    string s;
    cin>>s;
    int sW=0,sR=0,sB=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='W'){
            sW=sR+sB+sW;
            sR=sB=0;
            if(sW==0) sW++;
        }else if(s[i]=='R'){
            if(sB) sB--;
            else if(sW) sW--;
            sR++;
        }else{
            if(sR) sR--;
            else if(sW) sW--;
            sB++;
        }
        // cout<<i<<" "<<sR<<" "<<sB<<" "<<sW<<'\n';
    }
    cout<<sB+sR+sW<<'\n';
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