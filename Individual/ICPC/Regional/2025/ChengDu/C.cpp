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
    ll t,tp,id;
    node(){};
    node(ll t,ll tp,ll id):t(t),tp(tp),id(id){}
    bool operator<(const node&other)const{
        return t<other.t;
    }
};
pair<int,bool> check(ll T,vector<vector<node>>& a,int k){
    ll sum=0;
    vector<int> fs(2,0);
    fs[0]=a[0].size()-1,fs[1]=a[1].size()-1;
    bool f=true;
    ll Cy=T;
    int st=0;
    // int i=a[0].size()-1,j=a[1].size()-1;
    while((fs[0]>=0||fs[1]>=0)&&f){
        if(fs[(st^1)]>=0){
            if(T-k>=a[st^1][fs[(st^1)]].t){
                fs[(st^1)]--,st^=1;
                T-=k;
            }else{
                f=false;
                break;
            }
        }
        else{
            if((fs[st]>=0&&T-2*k>=a[st][fs[st]].t)){
                fs[st]--;
                T-=2*k;
            }else f=false;
        }
    }
    if(f) return make_pair(0,true);
    T=Cy;
    st=1;
    f=true;
    fs[0]=a[0].size()-1,fs[1]=a[1].size()-1;
    while((fs[0]>=0||fs[1]>=0)&&f){
        if(fs[(st^1)]>=0){
            if(T-k>=a[st^1][fs[(st^1)]].t){
                fs[(st^1)]--,st^=1;
                T-=k;
            }else{
                f=false;
                break;
            }
        }
        else{
            if((fs[st]>=0&&T-2*k>=a[st][fs[st]].t)){
                fs[st]--;
                T-=2*k;
            }else f=false;
        }
    }
    if(f) return make_pair(1,true);
    return make_pair(-1,false);
}

void sol() {
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vector<vector<node>> a(2);
    // vector<node> ans;
    for(int i=1;i<=n;i++){
        ll t;
        cin>>t;
        a[0].push_back(node(t,0,i));
    }
    for(int i=1;i<=m;i++){
        ll t;
        cin>>t;
        a[1].push_back(node(t,1,i));
    }
    for(int i=0;i<=1;i++) sort(a[i].begin(),a[i].end());
    ll l=0,r=3e15,mid;
    ll ans=0;
    int is;
    vector<node> res;
    while(l<=r){
        mid=(l+r)>>1;
        auto ck=check(mid,a,k);
        if(ck.second){
            ans=mid;
            is=ck.first;
            r=mid-1;
        } else{
            l=mid+1;
        }
    }
    vector<int> fs(2,0);
    fs[0]=a[0].size()-1,fs[1]=a[1].size()-1;
    int st=is;
    ll T=ans;
    // int i=a[0].size()-1,j=a[1].size()-1;
    while((fs[0]>=0||fs[1]>=0)){
        if(fs[(st^1)]>=0){
            T-=k;
            res.push_back(node(T,a[st^1][fs[st^1]].tp,a[st^1][fs[st^1]].id));
            fs[(st^1)]--,st^=1;
        }
        else{
            T-=2*k;
            res.push_back(node(T,a[st][fs[st]].tp,a[st][fs[st]].id));
            fs[st]--;
        }
    }
    reverse(res.begin(),res.end());
    cout<<ans<<'\n';
    for(const auto&[_,__,___]:res){
        cout<<_<<" "<<__<<" "<<___<<'\n';
    }
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