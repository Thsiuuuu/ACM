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
    int n,m;
    cin>>n>>m;
    odt.insert(Node_t(1,n+1,1));
    for(int i=0;i<m;i++){
        int op;
        int l,r;
        cin>>op>>l>>r;
        if(op==0){
            assign(l,r,0);
        }else if(op==1){
            int x,y;
            cin>>x>>y;
            auto ridx=split(r+1),
                lidx=split(l);
            int num=0;
            for(;lidx!=ridx;lidx++){
                if(lidx->v){
                    num+=(lidx->r-lidx->l+1);
                }
            }
            // cout<<num<<'\n';
            assign(l,r,0);
            if(num==0) continue;
            ridx=split(y+1);
            lidx=split(x);
            if(num>=y-x+1){
                assign(x,y,1);
                continue;
            }
            int rf=lidx->l;
            auto it=lidx;
            for(;lidx!=ridx&&num;lidx++){
                if(lidx->v==0){
                    int len=lidx->r-lidx->l+1;
                    if(num>=len){
                        num-=len;
                        rf=lidx->r;
                    }else{
                        rf=lidx->l+num-1;
                        num=0;
                        break;
                    }
                }
            }
            assign(it->l,rf,1);
        }else{
            auto ridx=split(r+1),lidx=split(l);
            ll ans=0,t=0;
            for(;lidx!=ridx;lidx++){
                if(lidx->v==0) t+=(lidx->r-lidx->l+1);
                else ans=max(ans,t),t=0;
            }
            cout<<max(ans,t)<<'\n';
        }
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