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
    int n;cin>>n;
    string s;cin>>s;
    vector<bool> is(n+1,false);
    stack<int> stk;
    s=' '+s;
    for(int i=1;i<s.size();i++){
        if(s[i]=='1'){
            stk.push(i);
        }else if(s[i]=='2'){
            if(stk.size()){
                is[stk.top()]=true;
                stk.pop();
            }else is[i]=true;
        }else{
            is[i]=true;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=!is[i];
    cout<<cnt<<"\n";
    for(int i=1;i<=n;i++){
        if(!is[i]) cout<<i<<" ";
    }
    if(cnt==0) cout<<'\n';
    cout<<'\n'; 
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