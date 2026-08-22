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
int cnt=0;
vector<ll> a;

bool check(int x){
    int number=0;
    int cur=cnt;
    for(int i=0;i<a.size();i++){
        if(a[i]>=x) number++;
        else{
            int tot=0;
            ll val=a[i];
            while(tot<cur&&val<x){
                val*=2,tot++;
            }
            if(val>=x) cur-=tot,number++;
        }
    }
    return number>=x;
}

void sol() {
    int n;
    cin>>n;
    a.assign(n,0);
    cnt=0;
    // priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i=0;i<n;i++){
        cin>>a[i];
        while(a[i]%2==0){
            cnt++;
            a[i]/=2;
        }
        // q.push(a[i]);
    }
    sort(a.begin(),a.end(),greater<ll>());
    int l=0,r=n,mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid,l=mid+1;            
        }else r=mid-1;
    }
    cout<<ans<<'\n';
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