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
void sol() {
    string s;cin>>s;
    int a1,a2,b1,b2,num;
    a1=a2=b1=b2=num=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            if(i&1) a2++;
            else a1++;
        }else if(s[i]=='0'){
            if(i&1) b2++;
            else b1++;
        }
        else num++;
    }
    int tot=abs(a1-a2)+abs(b1-b2);
    int mn=min(tot,num);
    tot-=mn,num-=mn;
    if(tot>0){
        cout<<tot<<'\n';
    }else{
        cout<<(num%2)<<'\n';
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