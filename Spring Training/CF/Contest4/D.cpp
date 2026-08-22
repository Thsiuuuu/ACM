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


vector<pll> a;
int n;
ll b;

ll check(ll k){
    sort(a.begin(),a.end(),[&](const pll&l1,const pll&l2)->bool{
        return l1.first+k*l1.second<l2.first+k*l2.second;
    });
    ll sum=0;
    for(int i=0;i<k;i++){
        sum+=(a[i].first+k*a[i].second);
    }
    return sum;
}

void sol() {
    cin>>n>>b;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++) cin>>a[i].second;
    int l=0,r=n;
    int mid;
    ll res1=0,res2=0;
    while(l<=r){
        mid=(l+r)>>1;
        ll tmp=check(mid);
        // cout<<tmp<<'\n';
        if(tmp<=b){
            res1=mid,res2=tmp;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<res1<<" "<<res2;
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}