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
void sol() {
    int n;cin>>n;
    vector<ll> a;
    queue<int> ln;
    multiset<ll> fu;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        if(x<0) fu.insert(x);
        else if(x) a.push_back(x);
        else ln.push(x);
    }
    sort(a.begin(),a.end());
    if(a.size()==0){
        cout<<"-1\n";
        return ;
    }
    ll pr=0;
    int idx=0;
    vector<ll> ans(n);
    // cout<<a.size()<<'\n';
    // cout<<a[2]<<'\n';
    for(int i=0;i<n;i++){
        if(i==0){
            ans[0]=pr=a[0];
            idx++;
            continue;
        }
        // cout<<i<<" "<<idx<<'\n';
        bool f=true;
        if(fu.size()){
            auto it=fu.upper_bound(-pr);
            // cout<<i<<" "<<(it==fu.end())<<'\n';
            if(it==fu.end()) f=false;
            else{
                pr+=*it;
                ans[i]=pr;
                fu.erase(it);
                // cout<<i<<'\n';
            }
            // cout<<"h1\n";
        }else f=false;
        if(!f){
            // cout<<i<<'\n';
            if(ln.size()){
                // cout<<"h3"<<" "<<i<<'\n';
                ln.pop();
                ans[i]=pr;
            }else{
                if(idx==a.size()){
                    cout<<"-1\n";
                    return ;
                }else{
                    // cout<<idx<<" "<<i<<'\n';
                    // cout<<"h2"<<" "<<i<<'\n';
                    // cout<<i<<" "<<idx<<" "<<a[idx]<<'\n';
                    pr+=a[idx++];
                    // cout<<i<<" "<<pr<<'\n';
                    ans[i]=pr;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
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