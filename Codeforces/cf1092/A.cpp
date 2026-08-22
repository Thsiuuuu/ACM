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
    int idx;
    int level;
    bool operator<(const node&other)const{
        if(level==other.level) return idx<other.idx;
        return level>other.level;
    }
};


void sol() {
    int n,k;
    cin>>n>>k;
    vector<int> a(k+1,0);
    vector<node> b(n);
    for(int i=1;i<=k;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>b[i].level;
        b[i].idx=i+1;
    }
    sort(b.begin(),b.end());
    vector<int> res;
    for(int i=0;i<n;i++){
        while(b[i].level<=k){
            res.push_back(b[i].idx);
            b[i].level++;
        }
    }
    cout<<res.size()<<'\n';
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
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