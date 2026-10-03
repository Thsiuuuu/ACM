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

void san(ll x, string &s){
    while(x){
        s.push_back(('0'+x%3));
        x/=3;
    }
}
ll pw[39];
void init(){
    pw[0]=1;
    for(int i=1;i<39;i++) pw[i]=pw[i-1]*3;
}
void sol() {
    ll l,r;cin>>l>>r;
    string l3,r3;
    san(l,l3),san(r,r3);
    while(l3.size()<r3.size()) l3.push_back('0');
    reverse(l3.begin(),l3.end());
    reverse(r3.begin(),r3.end());
    // cout<<l3<<" \n"<<r3<<'\n';
    // string s;
    // san(118097,s);
    // reverse(s.begin(),s.end());
    // cout<<s<<'\n';
    // int sum=0;
    int len=r3.size();
    ll ans=0;
    for(int i=0;i<r3.size();i++){
        ans+=(r3[i]-'0');
    }
    ans+=r3.size();
    if(l3[0]=='0'){
        if(r3.size()!=1) ans=max(ans,len-1+2*(len-1ll));
        ll cursum=0;
        for(int i=0;i<r3.size();i++){
            int x=r3[i]-'0';
            if(i==0&&r3[i]=='1'){
                cursum+=x;
                continue;
            }
            if(x==0) continue;
            ans=max(ans,len+cursum+x-1+2*((int)r3.size()-i-1ll));
            cursum+=x;
        }
    }else {
        ll pwl=0,pwr=0;
        ll cursum=0;
        for(int i=0;i<r3.size();i++){
            int x=r3[i]-'0';
            if(i==0&&r3[i]=='1'){
                pwr+=(r3[i]-'0')*pw[r3.size()-i-1];
                pwl+=(l3[i]-'0')*pw[r3.size()-i-1];
                cursum+=x;
                continue;
            }
            if(x==0) continue;
            if(pwl==pwr&&r3[i]==l3[i]){
                pwr+=(r3[i]-'0')*pw[r3.size()-i-1];
                pwl+=(l3[i]-'0')*pw[r3.size()-i-1];
                cursum+=x;
                continue;
            }
            ans=max(ans,len+cursum+x-1+2*((int)r3.size()-1ll-i));
            cursum+=x;
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    init();
    while (t--) {
        sol();
    }
    return 0;
}