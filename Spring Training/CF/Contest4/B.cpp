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

struct node{
    int l,r;
    node(){}
    node(int l,int r):l(l),r(r){}
    bool operator<(const node&other)const{
        if(l==other.l) return r>other.r;
        return l<other.l;
    };
};


void sol() {
    int n,t;
    cin>>n>>t;
    vector<node> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
    }  
    sort(a.begin(),a.end());
    int cl=a[0].l,cr=a[0].r;
    vector<node> res;
    for(int i=0;i<n;i++){
        if(a[i].l<=cr) cr=max(cr,a[i].r);
        else{
            res.push_back(node(cl,cr));
            cl=a[i].l,cr=a[i].r;
        }
    }
    res.push_back(node(cl,cr));
    int ans=0;
    if(res[0].l!=0) ans=max(ans,res[0].l);
    for(int i=1;i<res.size();i++){
        ans=max(ans,res[i].l-res[i-1].r);
    }
    if(res[res.size()-1].r!=t) ans=max(ans,t-res[res.size()-1].r);
    cout<<ans;
    // if(res.size()==1) cout<<"0";
    // else{
    //     // for(int i=0;i<res.size();i++){
    //     //     cout<<res[i].l<<" "<<res[i].r<<'\n';
    //     // }
    // }
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