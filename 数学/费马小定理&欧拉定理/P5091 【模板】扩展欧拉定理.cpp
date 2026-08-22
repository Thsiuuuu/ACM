#include <bits/stdc++.h>
using namespace std;

#define ll long long 



ll ksm(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

ll phi(ll n){
    ll res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res=res/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) res=res/n*(n-1);
    return res;
}

ll gcd(ll a,ll b){
    return b?gcd(b,b%a):a;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);

    ll a,m,b=0;
    scanf("%lld%lld",&a,&m);
    a%=m;
    ll fai=phi(m);
    char ch=getchar();
    bool flag=false;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        b=10*b+ch-'0';
        if(b>=fai){
            flag=true;
            b%=fai;
        }
        ch=getchar();
    }
    if(flag) b+=fai;
    cout<<ksm(a,b,m);
    return 0;
}