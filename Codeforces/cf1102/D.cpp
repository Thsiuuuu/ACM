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
ll a[3];
int tmp[3];
void sol() {
    ll n,k;cin>>n>>k;
    string s,t;
    cin>>s>>t;
    int st=1;
    for(int i=k;i>=1;i--){
        st^=1;
    }
    string m(n,'0');
    for(int i=0;i<n;i++){
        m[i]=((s[i]==t[i])?'0':'1');
    }
    tmp[0]=2,tmp[1]=st,tmp[2]=st^1;
    a[tmp[0]]=(ll)count(s.begin(),s.end(),'1')*count(s.begin(),s.end(),'0');
    a[tmp[1]]=(ll)count(m.begin(),m.end(),'1')*count(m.begin(),m.end(),'0');
    a[tmp[2]]=(ll)count(t.begin(),t.end(),'1')*count(t.begin(),t.end(),'0');
    if(st==1) swap(a[tmp[1]],a[tmp[2]]);
    ll tot=(1ll<<(k))+1;
    ll ans=((ll)a[tmp[0]]+a[tmp[1]]+a[tmp[2]])*(tot/3);
    // for(int i=0;i<3;i++){
    //     cout<<a[tmp[i]]<<" ";
    // }
    for(int i=0;i<tot%3;i++){
        ans+=a[tmp[i]];
    }
    for(int i=0;i<3;i++) a[i]=tmp[i]=0;
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