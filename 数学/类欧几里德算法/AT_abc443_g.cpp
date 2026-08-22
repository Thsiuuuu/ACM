#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t

ll solve(ll a,ll b,ll c,ll n){
    ll n2=(n+1)*n/2;
    i128 res=0;
    if(a>=c||b>=c){
        ll tmp=solve(a%c,b%c,c,n);
        ll aa=a/c,bb=b/c;
        res=(i128)tmp+(i128)aa*n2+(i128)bb*(n+1);
        return res; 
    }

    i128 m=(a*n+b)/c;
    if(!m) return res;
    i128 tmp=solve(c,c-b-1,a,m-1);
    res=((i128)m*n-tmp);
    return res;
}

void sol() {
    ll n,m,a,b;
    cin>>n>>m>>a>>b;

    if(a==0){
        cout<<min(n,b)<<'\n';
        return ;
    }

    ll ans=0;
    ans+=solve(a-1,b+m-1,m,n-1);
    ans-=solve(a,b,m,n-1);
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}