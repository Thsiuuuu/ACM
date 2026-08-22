#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

struct node{
    ll s,d;
    bool operator<(const node&other)const{
        return s<other.s;
    }
};

void sol() {
    int n;cin>>n;
    vector<node> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i].s>>vec[i].d;
    }
    sort(vec.begin(),vec.end());
    ll cur=0;
    for(int i=0;i<n;i++){
        int j=i;
        if(cur<vec[i].s) cur=vec[i].s;
        while(j<n&&vec[j].s==vec[i].s){
            cur+=vec[j].d;
            j++;
        }
        i=j-1;
    }    
    cout<<cur<<'\n';
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