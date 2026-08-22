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
    VL b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    VL c=b;
    sort(c.begin(),c.end());
    if(c[0]){
        cout<<"-1\n";
        return;
    }
    ll last=0,vl=0,pr=0;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        int j=i;
        last=0;
        pr=c[i];
        while(j<n&&c[j]==c[i]) last++,j++;
        if(j<n){
            if((c[j]-pr)%last){
                cout<<"-1\n";
                return ;
            }else if((c[j]-pr)/last<=vl){
                cout<<"-1\n";
                return ;
            }
            vl=(c[j]-pr)/last;
            mp[pr]=vl;
        }else{
            mp[pr]=vl+1;
        }
        i=j-1;
    }
    for(int i=0;i<n;i++){
        cout<<mp[b[i]]<<" ";
    }
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