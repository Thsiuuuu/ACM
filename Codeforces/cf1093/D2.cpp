#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

bool check1(int l,int r){
    cout<<"? ";
    cout<<r-l+1<<" ";
    for(int i=l;i<=r;i++) cout<<i<<" ";
    cout.flush();
    int ans;
    cin>>ans;
    return (ans+r-l+1)%2;
}

bool check2(int l,int r1,int r2){
    cout<<"? ";
    cout<<r1-l+2<<" ";
    for(int i=l;i<=r1;i++) cout<<i<<" ";
    cout<<r2<<" ";
    cout.flush();
    int ans;
    cin>>ans;
    return (ans+r1-l+2)%2;  
}

void sol() {
    int n;
    cin>>n;
    int l=1,r=2*n+1,ans1,ans2,ans3,mid;
    while(l<=r){
        // cout<<"h1";
        mid=(l+r)>>1;
        if(check1(1,mid)){
            ans3=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    l=1,r=ans3-1;
    while(l<=r){
        // cout<<"h2";  
        mid=(l+r)>>1;
        if(check1(mid,ans3)){
            ans1=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    l=ans1+1,r=ans3-1;
    while(l<=r){
        // cout<<"h3";
        mid=(l+r)>>1;
        if(check2(ans1,mid,ans3)){
            ans2=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<"! "<<ans1<<" "<<ans2<<" "<<ans3<<'\n';
    cout.flush();
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