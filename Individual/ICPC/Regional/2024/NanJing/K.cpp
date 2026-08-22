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
// struct Seg{
//     ll xl,xr;
//     ll Ll,Lr;
//     Seg(){}
//     Seg(ll xl,ll xr,ll Ll,ll Lr):xl(xl),xr(xr),Ll(Ll),Lr(Lr){}
// };
void sol() {
    ll n,m,k,w;cin>>n>>m>>k>>w;
    VL a(n),b(m);
    vector<pll> c;
    c.push_back({0,1});
    c.push_back({(w+1),1});
    for(int i=0;i<n;i++){
        cin>>a[i];
        c.push_back({a[i],0});
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        c.push_back({b[i],1});
    }
    // vector<Seg> all;
    sort(c.begin(),c.end(),[&](const pll&x,const pll&y)->bool{
        return x.first<y.first;
    });
    ll lt=0,cr=0;
    // ft=-1,sc=-1;
    VL ans;
    bool is=1;
    vector<pll> tmp;
    ll L,R;
    for(int i=0;i<c.size();i++){
        if(is&&c[i].second==0){
            R=c[i].first+k-1;
            tmp.push_back({c[i].first,R});
            is=0;
        }
        else if(!is&&c[i].second==1){
            cr=c[i].first;
            is=1;
            // if(tmp.size()==1){
            // }else{
            // }
            if(tmp[tmp.size()-1].second>=cr){
                tmp[tmp.size()-1]={cr-1-(k-1),cr-1};
            }
            for(int i=tmp.size()-2;i>=0;i--){
                if(tmp[i].second>=tmp[i+1].first){
                    tmp[i].second=tmp[i+1].first-1;
                    tmp[i].first=tmp[i].second-(k-1);
                }
            }
            if(tmp[0].first<=lt){
                cout<<"-1\n";
                return ;
            }
            for(int i=0;i<tmp.size();i++) ans.push_back(tmp[i].first);
            tmp.clear();
            // all.push_back(Seg(ft,sc,lt+1,cr-1));
            lt=cr;
        }else if(is&&c[i].second==1) lt=cr=c[i].first;
        else if(!is&&c[i].second==0){
            // sc=c[i].first;
            if(c[i].first>R){
                R=c[i].first+k-1;
                tmp.push_back({c[i].first,R});
            }
        } 
    }
    // for(const auto&[xl,xr,Ll,Lr]:all){
    //     // cout<<Ll<<" "<<Lr<<'\n';
    //     ll len=xr-xl+1;
    //     ll rem=(len+k-1)/k*k-len;
    //     ll tmp=min(rem,xl-Ll);
    //     ll anl=xl-tmp;
    //     rem-=tmp;
    //     tmp=min(rem,Lr-xr);
    //     ll anr=xr+tmp;
    //     rem-=tmp;
    //     if(rem){
    //         cout<<"-1\n";
    //         return ;
    //     }
    //     for(ll i=anl;i<=anr;i+=k){
    //         ans.push_back(i);
    //     }
    // }
    cout<<ans.size()<<'\n';
    for(ll x:ans) cout<<x<<" ";
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