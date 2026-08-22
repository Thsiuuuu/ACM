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
void sol() {
    int n;
    cin>>n;
    ll sum=0;
    ll ans1=0;
    vector<ll> a(n);
    // priority_queue<ll,vector<ll>,less<ll>> q;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        // if(a[i])    q.push(a[i]);
    }

    // while(q.size()>=2){
    //     ll i1=q.top();q.pop();
    //     ll i2=q.top();q.pop();
    //     ans1+=i2,i1-=i2;
    //     if(i1) q.push(i1);
    // }
    // sort(a.begin(),a.end());
    // for(int i=1;i<n;i++){
    //     ans1+=a[i-1];
    //     a[i]-=a[i-1];
    // }
    // if(q.size()==1) ans1+=q.top();
    cout<<max(*max_element(a.begin(),a.end()),(sum+1)/2)<<" "<<sum<<'\n';
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