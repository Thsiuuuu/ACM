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
bool is[N];
int a[N],n;
void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int last=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0) ans++,is[i]=1,last=i;
        else{
            int j=i;
            int cnt=1;
            ans++;
            while(j<=n&&a[j]){
                if(a[j]==2&&cnt==1) cnt++;
                j++;
            }
            if(last&&is[last]) ans--,cnt--,is[last]=0;
            i=j;
            if(cnt&&i<=n);
            else i--;
        }
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}