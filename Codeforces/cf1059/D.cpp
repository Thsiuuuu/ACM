#include <bits/stdc++.h>
using namespace std;

bool check(int mid){

    int og,nw;
    cout<<"1 1 "<<mid<<'\n';
    cout.flush();
    cin>>og;
    cout<<"2 1 "<<mid<<'\n';
    cout.flush();
    cin>>nw;
    return og==nw;
}
void sol(){
    int n;
    cin>>n;

    int len;
    cout<<"2 1 "<<n<<'\n';
    cout.flush();
    cin>>len;
    len-=n*(n+1)/2;

    int ans;
    int l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(!check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<"! "<<ans<<" "<<ans+len-1<<'\n';
    cout.flush();
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}