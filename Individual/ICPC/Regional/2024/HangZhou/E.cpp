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
struct node{
    ll l,r;
    int idx;
    node(){}
    node(ll l,ll r,int idx):l(l),r(r),idx(idx){}
    bool operator<(const node&other)const{
        if(l==other.l) return r>other.r;
        else return l>other.l;
    }
};
void sol() {
    ll n,f;cin>>n>>f;
    vector<node> a;
    priority_queue<node,vector<node>> q;
    ll mx=-1;
    for(int i=0;i<n;i++){
        ll l,r;cin>>l>>r;
        mx=max(mx,r);
        q.push(node(l,r,i+1));
    }
    VI ans;
    ll sum=0,cur=f;
    while(q.size()){
        auto[l,r,idx]=q.top();
        q.pop();
        // cout<<l<<" "<<r<<'\n';
        // cout<<mx<<'\n';
        if(l<=cur&&cur<r){
            cur=r;ans.push_back(idx);
            sum+=(r-l);
        }else if(cur<l){
            // cout<<mx<<'\n';
            sum+=(r-cur);
            cur=r;ans.push_back(idx);
        }else{
            a.push_back(node(l,r,idx));
        }
        if(r==mx){
            // cout<<mx<<'\n';
            while(q.size()){
                // cout<<q.top().l<<'\n';
                a.push_back(q.top());
                q.pop();
            }
            break;
        }
    }
    sort(a.begin(),a.end(),[&](const node&x,const node&y)->bool{
        return x.r>y.r;
    });
    for(int i=0;i<a.size();i++){
        auto&[l,r,idx]=a[i];
        ans.push_back(idx);
        sum+=(r-l);
    }
    cout<<sum<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
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