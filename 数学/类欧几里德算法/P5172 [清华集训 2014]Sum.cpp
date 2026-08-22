#include <iostream>
#include <cmath>

#define ll long long 
#define ull unsigned long long 

ll r;
long double sqrt_r;

ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}

ull f(ll a,ll b,ll c,ll n){
    if(!n) return 0;
    auto d=gcd(a,gcd(b,c));
    a/=d;
    b/=d;
    c/=d;
    ull k=(a*sqrt_r+b)/c;
    if(k){
        return n*(n+1)/2*k+f(a,b-c*k,c,n);
    }else{
        ull m=n*(a*sqrt_r+b)/c;
        return n*m-f(c*a,-c*b,a*a*r-b*b,m);
    }
}

ull solve(ll n,ll r){
    ll sqr=sqrt_r=sqrtl(r);
    if(r==sqr*sqr){
        return r%2?(n%2?-1:0):n;
    }
    return n-2*f(1,0,1,n)+4*f(1,0,2,n);
}

using std::cin;
using std::cout;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>r;
        ll res=solve(n,r);
        cout<<res<<'\n';
    }
    return 0;
}