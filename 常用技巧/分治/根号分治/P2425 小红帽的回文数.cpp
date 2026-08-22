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
    ll x;
    cin>>x;
    for(ll i=2;i*i<=x;i++){
        vector<ll> s;
        ll tmp=x;
        while(tmp){
            s.push_back(tmp%i);
            tmp/=i; 
        }
        int l=0,r=s.size()-1;
        bool f=true;
        while(l<=r){
            if(s[l]!=s[r]){
                f=false;
                break;
            }
            l++,r--;
        }
        if(f){
            cout<<i<<'\n';
            return ;
        }
    }
    // cout<<"hel";
    ll sq=sqrt(x);
    for(ll s=sq-1;s>=1;s--){
        ll b=x/s-1;
        if(b>sq&&b>=2&&x/b==x%b&&x%s==0){
            cout<<b<<'\n';
            return ;
        }
    }
    cout<<max(x+1,2ll)<<'\n';
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