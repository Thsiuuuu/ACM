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
#define 艹 pr[i-1]
template<typename T>
struct ST{
    vector<vector<T>> st;
    int n;
    ST(const vector<T>& a){
        n=a.size()-1;
        int k=__lg(n);
        st.assign(k+1,vector<T>(n+1));
       	for(int i=1;i<=n;i++) st[0][i]=a[i];
        for(int j=1;j<=k;j++){
            for(int i=1;i+(1<<j)-1<=n;i++){
                st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
            }
        }
    }
    T query(int l,int r){
        int k=__lg(r-l+1);
        return max(st[k][l],st[k][r-(1<<k)+1]);
    }
};  
void sol() {
    string s;cin>>s;
    s=' '+s;
    int n=s.size();
    VI pr(n+1,0);
    unordered_map<int,VI > mp;
    mp[0].push_back(0);
    for(int i=1;i<n;i++){
        pr[i]+=((s[i]=='(')?1:-1);
        pr[i]+=pr[i-1];
        mp[pr[i]].push_back(i);
    }
    ST <int>  ais(pr);
    ll ans=0;
    for(int i=1;i<n;i++){
        int res=-1,l=i,r=n-1,mid;
        while(l<=r){
            mid =(l+r) >>1;
            if(ais.query(i,mid)<=2*pr[i-1]){
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        if(res!=-1) ans+=upper_bound(mp[艹].begin(),mp[艹].end(),res)-lower_bound(mp[艹].begin(),mp[艹].end(),i); 
    }
    cout<<ans<<'\n';
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