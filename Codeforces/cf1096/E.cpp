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

// #define ls (u<<1)
// #define rs ((u<<1)|1)
// #define mid ((l+r)>>1)
const int maxn=2e5+10;
int a[maxn],tree[maxn],n;
int lowbit(int x){
    return x&-x;
}

void add(int i,int v){
    while(i<=n){
        tree[i]+=v;
        i+=lowbit(i);
    }
}

int sum(int i){
    int ans=0;
    while(i>0){
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

int  query(int l,int r){
    return sum(r)-sum(l-1);
}


void sol() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll res=0,ans=0;
    vector<bool> is(n+1,true);
    for(int i=n,mn=a[n];i>=1;i--){
        if(a[i]>mn) ans+=(a[i]-mn);
        else if(a[i]<mn) mn=a[i],is[i]=false;
    }
    res=ans;
    // cout<<res<<'\n';
    // for(int i=1;i<=n;i++) cout<<is[i]<<" ";
    // cout<<'\n'; 
    for(int i=1,l=1;i<=n;i++){
        // cout<<ans-is[i]+query(a[i],n)<<" ";
        res=max(res,ans+query(a[i],n));
        add(a[i],1);
        if(!is[i]){
            while(l<=i){
                add(a[l],-1);
                l++;
            }
        }
    }
    // cout<<'\n';
    cout<<res<<'\n';
    for(int i=1;i<=n;i++) tree[i]=0;
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