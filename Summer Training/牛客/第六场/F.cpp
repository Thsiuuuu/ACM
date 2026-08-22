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
#define u32 unsigned int
const ll mod=1e9+7,B=233;
const ll MOD=1ll<<32;
const int N=2e7+5;
ll f[N],p[N];
u32 F[(1<<26)+3];
int du[27],in[27];
VI e[27];
int n;
ll get(int l,int r){
    return f[r]-f[l-1]*p[r-l+1];
}
bool ck(int i,int mid){
    // cout<<get(1,mid-i+1)<<" "<<get(i,mid)<<'\n';
    return get(1,mid-i+1)==get(i,mid);
}

void sol() {
    string s;cin>>s;
    s=' '+s;
    int n=s.size();
    p[0]=1;
    for(int i=1;i<n;i++) p[i]=p[i-1]*B;
    for(int i=1;i<n;i++){
        f[i]=(f[i-1]*B+(s[i]-'a'+1));
        // cout<<f[i]<<'\n';
    }    
    for(int i=2;i<n;i++){
        // cout<<i<<' ';
        ll l=i,r=n-1,mid,ob=i-1;
        while(l<=r){
            mid=(l+r)>>1;
            // cout<<mid<<" ";
            if(ck(i,mid)){
                ob=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ob++;
        if(ob==n){
            cout<<"0\n";
            return ;
        }
        // cout<<'\n';
        // cout<<ob<<'\n';
        e[s[ob]-'a'].push_back(s[ob-i+1]-'a');
    }
    queue<int>Q;
    for(int i=0;i<26;i++){
        for(int v:e[i]){
            // cout<<v<<" "<<i<<'\n';
            du[v]++;
            in[v]|=(1<<i);
        }
        // cout<<du[i]<<" ";
    }
    for(int i=0;i<26;i++){
        if(du[i]==0){
            Q.push(i);
            // cout<<i<<'\n';
        }
    }
    
    while(Q.size()){
        auto u=Q.front();
        Q.pop();
        for(int v:e[u]){
            if(--du[v]==0){
                Q.push(v);
            }
        }
    }
    for(int i=0;i<26;i++){
        if(du[i]){
            cout<<"0\n";
            return ;
        }
    }
    F[0]=1;
    for(int mask=0;mask<(1<<26);mask++){
        for(int u=0;u<26;u++){
            if(
                ((mask>>u)&1)
                &&
                ((mask&(in[u]))==0)
            ){
                F[mask]+=F[((mask)^(1<<u))];
            }
        }
    }
    cout<<F[(1<<26)-1];
    cout<<'\n';
    cout<<(ll)(1<<26)*26<<'\n';
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