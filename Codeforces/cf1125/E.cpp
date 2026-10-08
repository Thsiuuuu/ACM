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
const int N=2e5+10;
ll a[N],b[N],n;
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    if(n==1){
        cout<<(1+(a[1]==b[1]))<<'\n';
        return ;
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=1+(a[i]==b[i]);
        if(i+1<=n){
            sum+=(b[i]==a[i+1])+1;
            sum+=(a[i]==b[i+1])+1;
        }
    }
    ll number=0;
    for(int i=1;i<=n-1;i++) number+=1+(a[i]==b[i]);
    ll mn=1e18;
    for(int i=1;i<=n;i++){
        mn=min(number,mn);
        if(i<n){
            number-=1+(a[i]==b[i]);
            number+=1+(a[i]==b[i+1]);
        }
    }
    cout<<sum-mn<<'\n';
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