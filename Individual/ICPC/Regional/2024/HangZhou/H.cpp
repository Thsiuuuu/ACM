#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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
    int l,r;
    int len;
    bool operator<(const node&o)const{
        return len>o.len;
    }  
};
void sol() {
    int n,k;cin>>n>>k;
    VI fa(n+1,0);
    vector<node> a(k);
    for(int i=0;i<k;i++){
        cin>>a[i].l>>a[i].r;
        a[i].len=a[i].r-a[i].l+1;
    }
    sort(a.begin(),a.end());
    if(a.size()==1){
        for(int i=a[0].l;i<=a[0].r;i++){
            cout<<i-1<<" ";
        }
        // cout<<"is\n";
        cout<<'\n';
        return ;
    }
    bool is=true;
    for(int i=1;i<k;i++){
        if(a[i].len!=a[i-1].len){
            is=false;
            break;
        }
    }
    if(is){
        cout<<"IMPOSSIBLE\n";
        return ;
    }
    if(a[k-1].len+1==a[0].len&&a[0].len==a[1].len){
        cout<<"IMPOSSIBLE\n";
        return ;
    }
    if(a[0].len!=a[1].len){
        for(int i=1;i<a.size();i++){
            fa[a[i].l]=a[0].l;
        }
    }else{
        for(int i=1;i<a.size();i++){
            if(a[i].len+2>a[0].len) fa[a[i].l]=a[0].l;
            else fa[a[i].l]=a[0].l+1;
        }
    }
    for(int i=0;i<a.size();i++){
        for(int x=a[i].l+1;x<=a[i].r;x++){
            fa[x]=x-1;
        }
    }
    for(int i=1;i<=n;i++) cout<<fa[i]<<' ';
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