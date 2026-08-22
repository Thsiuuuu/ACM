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
    mutable ll x,y;
    mutable int cnt=0;
    mutable int idx;
    node(ll x,ll y,int cnt,int idx):x(x),y(y),cnt(cnt),idx(idx){}
    bool operator<(const node&other)const{
        if(x==other.x){
            if(y==other.y){
                if(cnt==other.cnt){
                    return idx<other.idx;
                }
                return cnt<other.cnt;
            }
            return y<other.y; 
        }
        return x<other.x;
    }
};
void sol() {
    int n,m;
    cin>>n>>m;
    set<node> st;
    vector<ll> fx(n+1),fy(n+1);
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        fx[i+1]=x,fy[i+1]=y;
        st.insert(node(x,y,0,i+1));
    }
    vector<int> is(n+1,0);
    while(m--){
        ll l,r,dx,dy;
        cin>>l>>r>>dx>>dy;
        auto i1=st.lower_bound(node(l,INT64_MIN,0,0)),
             i2=st.upper_bound(node(r,INT64_MAX,0,0));
        vector<node> tmp;
        for(auto i=i1;i!=i2;i++){
            tmp.push_back(*i);
        }
        st.erase(i1,i2);
        for(int i=0;i<tmp.size();i++){
            auto& [x,y,cnt,idx]=tmp[i];
            is[idx]=++cnt;
            if(is[idx]==6){
                
            }else{
                x+=dx;
                y+=dy;
                fx[idx]=x,fy[idx]=y;
                st.insert(tmp[i]);
            }
        }
        // for(int i=0;i<tmp.size();i++){
        //     // cout<<tmp[i].idx<<" "<<tmp[i].cnt<<'\n';
        // }
        // cout<<m<<" ";
    
    }
    for(int i=1;i<=n;i++){
        if(is[i]==6){
            cout<<"Disappeared\n";
        }else{
            if(is[i]){
                cout<<"Cirrus ";
            }else{
                cout<<"Cumulus ";
            }
            cout<<fx[i]<<" "<<fy[i]<<'\n';
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