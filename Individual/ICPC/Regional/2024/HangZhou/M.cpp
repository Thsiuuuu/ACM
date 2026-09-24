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
template<typename T>
T gcd(T a,T b){
    return b?gcd(b,a%b):a;
}
template<typename T>
struct ST{
    vector<vector<T>> st;
    int n;
    ST(const vector<T>& a){
        n=a.size();
        int k=__lg(n);
        st.assign(k+1,vector<T>(n+1));
        for(int i=0;i<n;i++) st[0][i]=a[i];
        for(int j=1;j<=k;j++){
            for(int i=0;i+(1<<j)<=n;i++){
                st[j][i]=gcd(st[j-1][i],st[j-1][i+(1<<(j-1))]);
            }
        }
    }
    T query(int l,int r){
        int k=__lg(r-l+1);
        return gcd(st[k][l],st[k][r-(1<<k)+1]);
    }
};
void sol() {
    int n,k;cin>>n>>k;
    VI b(n);
    VL gg;
    ll g=0,mn;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(i)   g=gcd(g,abs(b[i]-b[i-1]));
    }
    if(g==0){
        cout<<k<<' '<<k*(k+1ll)/2<<'\n';
        return ;
    }
    for(int i=1;i<n;i++){
        gg.push_back(abs(b[i]-b[i-1]));
    }
    mn=*min_element(b.begin(),b.end());
    ST<ll> st(gg);
    VL all;
    for(ll m=1;m*m<=g;m++){
        if(g%m==0){
            if(m>mn&&m<=mn+k) all.push_back(m);
            if(m!=g/m&&(g/m)>mn&&(g/m)<=mn+k) all.push_back(g/m);
        }
    }
    stack<int>stk;
    VI l(n),r(n);
    l[0]=0;
    r[n-1]=n-1;
    stk.push(0);
    for(int i=1;i<n;i++){
        while(stk.size()&&b[stk.top()]>=b[i]) stk.pop();
        if(stk.empty()) l[i]=0;
        else l[i]=stk.top()+1;
        stk.push(i);
    }
    while(stk.size()) stk.pop();
    stk.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(stk.size()&&b[stk.top()]>=b[i]) stk.pop();
        if(stk.empty()) r[i]=n-1;
        else r[i]=stk.top()-1;
        stk.push(i);
    }
    ll cnt,sum;cnt=sum=0;
    for(ll x:all){
        bool is=true;
        for(int i=0;i<n;i++){
            if(l[i]==r[i]) continue;
            if(st.query(l[i],r[i]-1)%(b[i]+x-mn)!=0){
                is=false;
                break;
            } 
        }
        if(is) cnt++,sum+=(x-mn);
    }
    cout<<cnt<<" "<<sum<<'\n';
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