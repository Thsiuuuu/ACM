#include <bits/stdc++.h>
using namespace std;
/*
    /\_/\
    ( =o.o= ) *
    / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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
const int N=102;
int f[N],a[N];
void sol() {
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int k;cin>>k;
    for(int i=0;i<k;i++) cin>>a[i];
    for(int x=1;x<=100;x++){
        set<int> s;
        for(int i=0;i<k;i++){
            if(x>=a[i]) s.insert(f[x-a[i]]);
        }
        for(int i=0;i<=100;i++){
            if(s.find(i)==s.end()){
                f[x]=i;
                break;
            }
        }
    }
    int res=f[n1]^f[n2]^f[n3];
    cout<<(res?"Peter":"Vasya");
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