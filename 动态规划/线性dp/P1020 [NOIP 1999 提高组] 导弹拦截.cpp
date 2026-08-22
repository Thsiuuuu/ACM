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
int f[N],a[N],len,n;
void sol() {
    int x;
    while(cin>>x){
        a[++n]=x;
    }
    f[0]=1e9;
    for(int i=1;i<=n;i++){
        int l=0,r=len,mid,res=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(f[mid]<a[i]) res=mid,r=mid-1;
            else l=mid+1;
        }
        if(res==-1) f[++len]=a[i];
        else f[res]=a[i];
    }
    cout<<len<<'\n';
    for(int i=0;i<=len;i++) f[i]=0;
    len=0;
    for(int i=1;i<=n;i++){
        auto it=lower_bound(f,f+len+1,a[i]);
        if(it==f+len+1) f[++len]=a[i];
        else *it=a[i];
    }
    cout<<len;  
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