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

char tran(int x){
    if(x==0) return 'A';
    if(x==1) return 'T';
    if(x==2) return 'G';
    if(x==3) return 'C';
}

void prefix_function(const string&s,vector<ll>&pi){
    int n=s.size();
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
}
void build(string s,vector<vector<int>>&aut){
    s+='#';
    int n=s.size();
    vector<ll> pi(n);
    prefix_function(s,pi);
    for(int i=0;i<n;i++){
        for(int c=0;c<4;c++){
            if(i>0&&tran(c)!=s[i]){
                aut[i][c]=aut[pi[i-1]][c];
            }else{
                aut[i][c]=i+(tran(c)==s[i]);
            }
        }
    }
}
const ll N=3010;
ll p[N][4];
ll f[N][N][2];
void sol() {
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
            cin>>p[i][j];
        }
    }
    vector<vector<int>> aut(m+1,vector<int>(4,0));
    build(s,aut);
    f[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            for(int c=0;c<4;c++){
                int nex=aut[j][c];
                if(nex==m){
                    f[i+1][nex][1]=(f[i+1][nex][1]+f[i][j][0]*p[i+1][c])%mod;
                    f[i+1][nex][1]=(f[i+1][nex][1]+f[i][j][1]*p[i+1][c])%mod;
                }else{
                    f[i+1][nex][0]=(f[i+1][nex][0]+f[i][j][0]*p[i+1][c])%mod;
                    f[i+1][nex][1]=(f[i+1][nex][1]+f[i][j][1]*p[i+1][c])%mod;
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=m;i++){
        ans=(ans+f[n][i][1])%mod;
    }
    cout<<ans;
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