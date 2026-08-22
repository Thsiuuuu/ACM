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
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>
char p[5]={'a','e','i','o','u'};
void o1(){
    cout<<"Well-Being\n";
}
void sol() {
    string s;cin>>s;
    if(s.size()!=8){
        o1();
        return ;
    }
    for(int i=0;i<s.size();i++){
        if((i&1)&&find(p,p+5,s[i])==p+5){
            o1();
            return ;
        }else if((i%2==0)&&find(p,p+5,s[i])!=p+5){
            o1();
            return ;
        }
    }
    cout<<"Suspected Virus\n";
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