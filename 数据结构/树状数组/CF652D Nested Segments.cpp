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
const int maxn=2e5+10;
int tree[maxn],ans[maxn];
VI r;
struct node{
    int l,r;
    int id;
    bool operator<(const node&other)const{
        return l>other.l;
    }
}p[maxn];
int lowbit(int x){
    return x&-x;
}

void add(int i,int v){
    while(i<maxn){
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
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].l>>p[i].r;  
        r.push_back(p[i].r);
        p[i].id=i;
    }
    sort(r.begin(),r.end());
    r.erase(unique(r.begin(),r.end()),r.end());
    for(int i=0;i<n;i++){
        p[i].r=lower_bound(r.begin(),r.end(),p[i].r)-r.begin()+1;
    }
    sort(p,p+n);
    for(int i=0;i<n;i++){
        ans[p[i].id]=query(1,p[i].r);
        add(p[i].r,1);
        // cout<<ans[p[i].id]<<'\n';
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<'\n';
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