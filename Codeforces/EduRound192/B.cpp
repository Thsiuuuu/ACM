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
    int n;cin>>n;
    VL a(4,0);
    int st=1;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a[x]++;
        // cout<<i<<'\n';
        // for(int k=1;k<=3;k++) cout<<a[k]<<" ";
        // cout<<'\n';
        if(st==1){
            if(a[1]>=a[2]+a[3]){
                st=-1;
                // if(x==3) {}
                // else{
                //     a[1]=a[2]=a[3]=0;
                //     st++;
                //     a[x]=1;
                // }
            }else{

            }
        }else if(st==-1){
            if(x!=3){
                a[1]=a[2]=a[3]=0;
                st=2;
                a[x]=1;
                // cout<<i<<'\n';
            }else if(a[1]<a[2]+a[3]){
                a[1]=a[2]=0;
                st=2;
                a[3]=1;
            }
        }
        if(st==2&&a[1]+a[2]>=a[3]&&i+1<n){
            st++;
        }
    }
    cout<<((st==3)?"yes\n":"no\n");
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