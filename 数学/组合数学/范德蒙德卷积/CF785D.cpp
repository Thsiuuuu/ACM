#include <bits/stdc++.h>
using namespace std;

/*

    范德蒙德卷积妙妙题
    两段枚举分界点，
    枚举最后一个(是谁，式子与范德蒙德卷积形式类似，但是对于[min(a,b),a]的值需要进行判断
    但是这个区间内部
    1.min(a,b)=a,那么a的组合数此时为0
    2.min(a,b)=b,那么b的组合数此时为0

    所以说这一部分对答案没有贡献，直接计算卷积就可以

*/

#define ll long long 

const ll mod=1e9+7;
const int N=200010;

int l[N],r[N];
ll fac[N],inv[N];
ll ans;

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

void init(){
    fac[0]=1;
    for(int i=1;i<=200000;i++) fac[i]=fac[i-1]*i%mod;
    inv[200000]=ksm(fac[200000],mod-2);
    for(int i=200000;i>=1;i--) inv[i-1]=inv[i]*i%mod;
}

ll C(ll n,ll m){
    if(n<m) return 0;
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    init();
    string s;
    cin>>s;

    s=' '+s;
    for(int i=1;i<s.size();i++){
        l[i]=l[i-1];
        if(s[i]=='(') l[i]++;
    }
    for(int i=s.size()-1;i>=1;i--){
        r[i]=r[i+1];
        if(s[i]==')') r[i]++;
    }

    for(int i=1;i<s.size();i++){
        if(s[i]=='('){
            ans=(ans+C(l[i]+r[i]-1,l[i]))%mod;
        }
    }
    cout<<ans;
    return 0;
}