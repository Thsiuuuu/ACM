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
double a[1010][3];
void sol() {
    int n;
    cin>>n; 
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    double ans=0;
    double base=0,sum=0;
    for(int j=0;j<3;j++){
        for(int i=1;i<=n;i++){
            if(j<2){
                base+=a[i][j];
                sum+=min(a[i][j],a[i][2]);
            }else{
                if(a[i][0]+a[i][1]==2){
                    base+=1;
                    sum+=a[i][2];
                }
            }
        }
        if(base!=0) ans=max(ans,sum/base);
        base=sum=0;
    }
    cout<<fixed<<setprecision(2)<<ans*100<<"%\n";
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