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
struct node{
    ll len,d;
    ll cal(int j)const{
        return (len-j)/(j+1);
    }
    ll c1(int j)const{
        ll u=cal(j),r=(len-j)%(j+1);
        return u*(u+1)/2*(j+1-r)+(u+1)*(u+2)/2*r;
    }
    ll del()const{
        return c1(d)-c1(d+1);
    }
    bool operator<(const node&o)const{
        // ll u=cal();
        return del()<o.del();
    }
};
void sol() {
    int n,k;cin>>n>>k;
    string s;cin>>s;
    priority_queue<node,vector<node>> Q;
    ll ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            int j=i;
            while(j<s.size()&&s[j]=='0'){
                j++;
            }
            ans+=(ll)(j-i)*(j-i+1)/2;
            Q.push({j-i,0});
            i=j;
        }
    }
    for(int i=0;i<k&&Q.size();i++){
        auto P=Q.top();
        Q.pop();
        ans-=(P.del());
        if(++P.d<P.len)  Q.push(P);
    }
    ans*=5;
    while(Q.size()){
        auto [len,d]=Q.top();
        Q.pop();
        ans+=20*(len-d);
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