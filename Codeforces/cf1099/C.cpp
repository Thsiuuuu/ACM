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


void sol() {
    int n;
    cin>>n;
    VI a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,pii> mp;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(i==0||mp.count(a[i])){
            auto&[key,val]=mp[a[i]];
            if(key==i)    key++;
            if(key==n) ans.push_back(val);
        }
        if(a[i]==1){
            if(i==0||mp.count(2)){
                auto&[key,val]=mp[2];
                if(key==i) key++,val++;
                if(key==n) ans.push_back(val);
            }
        }
        int st=0;
        while(a[i]!=1){
            st++;
            if(a[i]&1) a[i]+=1;
            else a[i]>>=1;
            if(i==0||mp.count(a[i])){
                auto&[key,val]=mp[a[i]];
                if(key==i){
                    key++,val+=st;
                    if(key==n) ans.push_back(val);
                }
            }
        }
    } 
    // sort(ans.begin(),ans.end()
    // // ,[&](const pll& a1,const pll&a2)->bool{
    // //     return a1.second<a2.second;
    // // }
    // );
    cout<<*min_element(ans.begin(),ans.end())<<'\n';
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