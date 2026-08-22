#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define double long double
#define i128 __int128_t
#define ull unsigned long long  

string s,t;
const int N=5e5+10;
ll f[N][2][2],pw2[N],pw3[N];
const ll mod=998244353;

void init(){
    pw2[0]=pw3[0]=1;
    for(int i=1;i<=5e5;i++){
        pw2[i]=pw2[i-1]*2%mod;
        pw3[i]=pw3[i-1]*3%mod;
    }
}


ll dfs(int i,int fs,int ft){
    if(i==s.size()) return 1;
    if(f[i][fs][ft]!=-1) return f[i][fs][ft];
    if(!(fs|ft)) return f[i][fs][ft]=pw3[s.size()-i];
    f[i][fs][ft]=0;
    for(int a=0;a<=1;a++){
        for(int b=a;b<=1;b++){
            if(fs&&a<(s[i]-'0')) continue;
            if(ft&&b>(t[i]-'0')) continue;
            f[i][fs][ft]=(f[i][fs][ft]+dfs(i+1,fs&&(a==(s[i]-'0')),ft&&(b==(t[i]-'0'))))%mod;
        }
    }
    return f[i][fs][ft];
}



void sol() {
    cin>>s>>t;
    s.insert(0,t.size()-s.size(),'0');
    for(int i=0;i<s.size();i++){
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                f[i][j][k]=-1;
            }
        }
    }
    ll tmp1=0,tmp2=0;
    for(int i=0;i<s.size();i++){
        if(t[i]>'0') tmp1=(tmp1+pw2[s.size()-i-1])%mod;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>'0') tmp2=(tmp2+pw2[s.size()-i-1])%mod;
    }
    ll dis=((tmp1-tmp2+mod)%mod+1)%mod;
    ll ans=dfs(0,1,1);
    cout<<((2*ans)%mod-dis+mod)%mod<<'\n';
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