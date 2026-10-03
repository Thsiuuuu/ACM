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
const int N=1e5+10;
ll a,b,pre[N],n;
void sol(int ts) {
    cin>>a>>b>>n;
    for(int i=1;i<=a;i++){
        cin>>pre[i];
        pre[i]+=pre[i-1];
    }
    ll A=a,B=b;
    for(int tt=0;tt<n;tt++){
        auto it=lower_bound(pre+1,pre+a+1,A);
        // cout<<*it<<" "<<it-pre<<'\n';
        ll nxA=it-pre,nxB=A-pre[it-pre-1];
        if(nxA==A){
            B=nxB;
            break;
        }
        // cout<<nxA<<" "<<nxB<<'\n';
        A=nxA,B=nxB;
    }
    cout<<"Case #"<<ts<<": "<<A<<"-"<<B<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}