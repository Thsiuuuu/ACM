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
const ll mod=998244353;
const int N=5e3+2;
ll inv[N];

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
void init(){
    for(int i=1;i<N;i++){
        inv[i]=ksm(i,mod-2);
    }
}
void sol() {
    int n;
    cin>>n;
    vector<ll> a(n);
    int num=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==-1) num++;
    }
    // if(t==0) cout<<num<<endl;
    vector<vector<vector<ll>>> f(num+1,vector<vector<ll>>(n+1));
    vector<ll> cnt(n+1,0);
    int tot=0,cur=0;
    for(int i=0;i<n;i++){
        if(a[i]!=-1){
            cnt[a[i]]++;
            tot++;
        }else{
            cur++;
            if(cur==1){
                for(int j=0;j<=n;j++){
                    if(cnt[j]==0) continue;
                    f[cur][j].assign(2,0);
                    f[cur][j][1]=cnt[j]*inv[tot]%mod;
                }
                // cout<<"hel"<<endl;
            }else{
                for(int j=0;j<=n;j++){
                    if(cnt[j]==0) continue;
                    f[cur][j].assign(cnt[j]+1,0);
                }
                vector<ll> g(n+1,0),h(n+1,0);
                for(int u=0;u<=n;u++){
                    for(int v=1;v<=cnt[u]&&v<f[cur-1][u].size();v++){
                        g[u]=(g[u]+f[cur-1][u][v])%mod;
                    }
                    if(u!=0){
                        h[u]=h[u-1];
                    }
                    h[u]=(h[u]+g[u])%mod;
                }
                for(int j=0;j<=n;j++){
                    if(1<=cnt[j]) f[cur][j][1]=cnt[j]*inv[tot-cur+1]%mod*((j>=1)?h[j-1]:0)%mod;
                    for(int k=2;k<=cnt[j]&&k-1<f[cur-1][j].size();k++){
                        f[cur][j][k]=f[cur-1][j][k-1]*(cnt[j]-k+1+mod)%mod*inv[tot-cur+1]%mod;
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=n;i++){
        // if(t==0){
        //     cout<<i<<endl;
        // }
        for(int k=1;k<=cnt[i]&&k<f[num][i].size();k++){
            ans=(ans+f[num][i][k])%mod;
            // if(t==0){
            //     cout<<i<<endl;
            //     cout<<f[num][i][k]<<endl;
            //     cout<<ans<<endl;
            // }
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}