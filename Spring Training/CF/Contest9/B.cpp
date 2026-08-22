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

const double eps=1e-7;
vector<double> a;
int n;
ll f;
bool check1(double mid){
    double rem=0;
    for(int i=0;i<n-1;i++){
        if(rem+mid*f>=a[i]) rem=rem+mid*f-a[i];
        else rem=0;
    }
    return rem+mid*f-a[n-1]>=0;
}

bool check2(double mid){
    double rem=0;
    for(int i=0;i<=n-1;i++){
        if(rem+mid*f>=a[i]) rem=rem+mid*f-a[i];
        else return false;
    }
    return true;
}


void sol() {
    while(cin>>n>>f){
        a.assign(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        ld r=1+(double)a[n-1]/f,l=0,mid,ans1=0,ans2=0;
        // cout<<r<<'\n';
        while(r-l>eps){
            mid=(l+r)/2;
            // cout<<mid<<'\n';
            // cout<<mid<<" ";
            // cout<<check1(mid)<<'\n';
            if(check1(mid)){
                r=mid;
                // cout<<mid<<'\n';
                ans1=mid;
            }else l=mid;
        }
        r=1+*max_element(a.begin(),a.end())/f,l=0;
        while(r-l>eps){
            mid=(l+r)/2;
            if(check2(mid)){
                r=mid;
                ans2=mid;
            }else l=mid;
        }
        cout<<fixed<<setprecision(6)<<ans1<<" "<<ans2<<'\n';
    }
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