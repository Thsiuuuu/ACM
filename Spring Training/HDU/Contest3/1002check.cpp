#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

struct node{
    vector<stack<int>> st;
    node():st(3){}
    int l,r;
    l=r=0;

    void init(int n,int idx){
        for(int i=n;i>=1;i--){
            st[idx].push(i);
        }
    }

    bool operator<(const node&other)const{
        for(int i=0;i<3;i++){
            if(st[i]==other.st[i]) continue;
            return st[i]<other.st[i];
        }
        if(l==other.l){
            return r<other.r;
        }
        return l<other.l;
    }
};

void sol() {
    int n;
    cin>>n;
    map<node,bool> mp;
    node s;
    s.init(n,0);
    mp[s]=1;
    queue<pair<node,ll>> Q;
    Q.push({s,0});
    node obj;
    obj.init(n,2);
    while(Q.size()){
        auto [u,dis]=Q.front();Q.pop();
        if(u==obj){
            cout<<dis;
            return ;
        }
        for(int i=0;i<3;i++){
            if(!u.l&&!u.r){
                node tmp=u;
                if(tmp.st[i].size()){
                    tmp.l=tmp.st[i].top();
                    tmp.st[i].pop();
                    if(mp.count(tmp)==0){
                        mp[tmp]=1;
                        Q.push({tmp,dis+1});
                    }
                }   
            }else if(u.l&&u.r){
                if(u.st[i].size()){
                    node tmp=u;
                    
                }
            }
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