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

// const eps=1e-5;

struct node{
    ld c,k;
    bool operator<(const node&other)const{
        return c*other.k>k*other.c;
    }
};

void sol() {
    int n,m;
    cin>>n>>m;
    ld sum=0;
    vector<node> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].c;
    }
    for(int i=0;i<n;i++) cin>>a[i].k;
    sort(a.begin(),a.end());
    for(int i=0;i<n&&m>0;i++){
        int siz=a[i].k;
        while(m>0&&siz>0){
            sum+=100*a[i].c/a[i].k;
            siz--;
            m--;
        }
    }
    cout<<fixed<<setprecision(4)<<sum;
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