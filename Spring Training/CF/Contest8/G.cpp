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


#define lb lower_bound
#define dis distance


// const int maxn=4e6+10;
const ll mod=998244353;
// int tree[maxn];
// int Siz;
// int lowbit(int x){
//     return x&-x;
// }

// void add(int i,int v){
//     while(i<=Siz){
//         tree[i]+=v;
//         i+=lowbit(i);
//     }
// }

// int sum(int i){
//     int ans=0;
//     while(i>0){
//         ans+=tree[i];
//         i-=lowbit(i);
//     }
//     return ans;
// }

// int  query(int l,int r){
//     return sum(r)-sum(l-1);
// }

// struct Query{
//     ll x;
//     ll y;
// };

void sol() {
    int n,q;
    cin>>n>>q;
    // map<int,ll> mp;
    ll i0=0,i1=0;
    vector<ll> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
        // mp[c[i]]++;
        i0+=(c[i]==0);
        i1+=(c[i]==1);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(c[i]==1) ans=(ans+i0)%mod;
        else if(c[i]>1) ans=(ans+n-1+mod)%mod;
    }
    // cout<<ans<<'\n';
    while(q--){
        int x,y;
        cin>>x>>y;
        int af=x-1;
        if(c[af]==1) ans=(ans-i0+mod)%mod;
        else if(c[af]>1) ans=(ans-n+1+mod)%mod;
        else ans=(ans-i1+mod)%mod;
        i0-=(c[af]==0);
        i1-=(c[af]==1);
        // mp[c[af]]--;
        // mp[y]++;
        c[af]=y;
        if(y==1) ans=(ans+i0)%mod;
        else if(y) ans=(ans+n-1+mod)%mod;
        else ans=(ans+i1)%mod;
        i0+=(y==0);
        i1+=(y==1);
        cout<<ans<<'\n';
    }


    // int n,m;
    // cin>>n>>m;
    // vector<ll> a(n);
    // vector<ll> all;
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    //     all.push_back(a[i]);
    // }
    // vector<Query> q(m);
    // for(int i=0;i<m;i++){
    //     cin>>q[i].x>>q[i].y;
    //     all.push_back(q[i].y);
    // }
    // int siz=all.size();
    // for(int i=0;i<siz;i++){
    //     if(all[i]==1){
    //         all.push_back(1);
    //         continue;
    //     }
    //     ll cur=all[i]*all[i];
    //     while(cur<=(ll)1e9){
    //         all.push_back(cur);
    //         all.push_back(cur-1);
    //         cur*=all[i];
    //     }
    // }
    // vector<ll> aft=all;
    // aft.push_back(0);
    // aft.push_back(1);
    // sort(aft.begin(),aft.end());
    // aft.erase(unique(aft.begin(),aft.end()),aft.end());
    // for(int i=0;i<n;i++){
    //     add(dis(aft.begin(),lower_bound(aft.begin(),aft.end(),a[i]))+1,1);
    // }
    // Siz=aft.size();
    // ll ans=0;
    // /*
    // \
    //     现在我需要去枚举每一个值，然后搞32pow
    
    // */
    // // cout<<Siz<<'\n';
    // // for(int i=0;i<aft.size();i++){
    // //     cout<<aft[i]<<" ";
    // // }
    // for(int i=0;i<n;i++){
    //     if(a[i]==1){
    //         ans=(ans+
    //                 query(dis(aft.begin(),lb(aft.begin(),aft.end(),0))+1,
    //                       dis(aft.begin(),lb(aft.begin(),aft.end(),0)))+1
    //         )%mod;
    //     }
    //     else{
    //         ll cur=a[i];
    //         for(int pw=1;cur*a[i]<=(ll)1e9;pw++,cur*=a[i]){
    //             ans=(ans+
    //                 query(dis(aft.begin(),lb(aft.begin(),aft.end(),cur))+1,
    //                       dis(aft.begin(),lb(aft.begin(),aft.end(),cur*a[i]-1)))+1
    //             )%mod;
    //         }
    //     }
    // }
    // for(int i=0;i<m;i++){
    //     add(dis(aft.begin(),lb(aft.begin(),aft.end(),q[i].x))+1,-1);
    //     add(dis(aft.begin(),lb(aft.begin(),aft.end(),q[i].y))+1,+1);
    //     ll cur=q[i].x;
    //     while(cur*q[i].x<=(ll)1e9){
    //         ans=(ans-
    //             query(dis(aft.begin(),lb(aft.begin(),aft.end(),cur))+1,
    //                   dis(aft.begin(),lb(aft.begin(),aft.end(),cur*q[i].x-1))+1)+mod
    //         )%mod;
    //         cur*=q[i].x;
    //     }
    //     if(q[i].y==1){
            
    //     }
    //     cur=q[i].y;
    //     while(cur*q[i].y<=(ll)(1e9)){
    //         ans=(ans+
    //             query(dis(aft.begin(),lb(aft.begin(),aft.end(),cur))+1,
    //                   dis(aft.begin(),lb(aft.begin(),aft.end(),cur*q[i].y-1))+1)
    //         )%mod;
    //         cur*=q[i].y;
    //     }   
    //     cout<<ans<<'\n';
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