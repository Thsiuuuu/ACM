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
const int Mn=0,
          Mx=1e6+5;
struct Node_t{
    int l,r;
    mutable ll v;
    Node_t (const int &il,const int &ir,const int &iv):l(il),r(ir),v(iv){}
    bool operator<(const Node_t&o)const{
        return l<o.l;
    }
};
set<Node_t> odt;
auto split(int x){
    auto it=odt.lower_bound(Node_t(x,0,0));
    if(it!=odt.end()&&it->l==x) return it;
    --it;
    int l=it->l,r=it->r,v=it->v;
    odt.erase(it);
    odt.insert(Node_t(l,x-1,v));
    return odt.insert(Node_t(x,r,v)).first;
    //insert返回<插入位置的迭代器,是否插入成功>
}
void assign(int l,int r,ll v){
    auto itr=split(r+1),itl=split(l);
    odt.erase(itl,itr);
    odt.insert(Node_t(l,r,v));
}
void sol() {
    int n;
    cin>>n;
    odt.insert(Node_t(Mn,Mx,0));
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        assign(l,r-1,1);
    }
    bool f=false;
    int ans1=0,ans2=0;//1代表挤牛奶,2/0代表不挤牛奶
    int last=0;
    int lf=0,rf=0;
    for(auto it=odt.begin();it!=odt.end();it++){
        auto[l,r,v]=*it;
        // cout<<l<<" "<<r<<" "<<v<<'\n';
        if(v==1){
            if(last==0){
                if(f){
                    ans2=max(ans2,rf-lf+1);
                }
                f=true;
                last=1;
                lf=l,rf=r;
            }
            rf=max(rf,r);
        }else {
            if(!f) continue;
            if(last==1){
                ans1=max(ans1,rf-lf+1);
                last=0;
                lf=l,rf=r;
            }
            rf=max(rf,r);
        }
    }
    cout<<ans1<<" "<<ans2;
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