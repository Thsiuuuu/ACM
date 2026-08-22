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
void sol() {
    int n;
    cin>>n;
    VL a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int j=i;
        int len=0;
        while(j+1<=n&&a[j+1]<=a[j]){
            if(a[j+1]<a[j]) len++;
            j++;
        }
        if(len>=2){
            cout<<"NO\n";
            return ;
        }
        i=j;
    }
    bool f=false;
    ll k;
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]){
            if(!f){
                auto it=upper_bound(a.begin()+1,a.end(),a[i]);
                f=true;
                if(it==a.end()){
                    cout<<"YES\n";
                    return ;
                }else{
                    k=*it-a[i];
                }
            }
            if(a[i]+k<a[i-1]){
                cout<<"NO\n";
                return ;
            }
            a[i]+=k;
        }
    }
    cout<<"YES\n";
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