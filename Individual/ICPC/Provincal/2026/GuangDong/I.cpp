#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
int a[4][26];
void sol() {
    string s,t;cin>>s>>t;
    for(int i=0;i<4;i++){
        if(i&1) fill(a[i],a[i]+26,-1);
        else fill(a[i],a[i]+26,1e9);
    }
    for(int i=0;i<s.size();i++){
        int x=s[i]-'a';
        a[1][x]=max(a[1][x],i);
        a[0][x]=min(a[0][x],i);
    }
    for(int i=0;i<t.size();i++){
        int x=t[i]-'a';
        a[2][x]=min(a[2][x],i);
        a[3][x]=max(a[3][x],i);
    }
    for(char xx='a';xx<='z';xx++){
        for(char yy='a';yy<='z';yy++){
            int x=xx-'a',y=yy-'a';
            if(a[0][x]<a[1][y]&&a[2][x]<a[3][y]){
                cout<<xx<<yy<<'\n';
                return ;
            }
        }
    }
    cout<<"HENG!\n";
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