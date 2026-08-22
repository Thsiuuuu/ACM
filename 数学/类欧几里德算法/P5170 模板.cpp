#include <iostream>

#define ll long long 


struct Data{
    int f,g,h;
};


Data solve(ll a,ll b,ll c,ll n){
    constexpr ll M=998244353;
    constexpr ll i2=(M+1)/2;
    constexpr ll i6=(M+1)/6;
    ll n2=(n+1)*n%M*i2%M;
    ll n3=(2*n+1)*(n+1)%M*n%M*i6%M;
    Data res={0,0,0};
    if(a>=c||b>=c){
        auto tmp=solve(a%c,b%c,c,n);
        ll aa=a/c,bb=b/c;
        res.f=(tmp.f+aa*n2+bb*(n+1))%M;
        res.g=(tmp.g+aa*n3+bb*n2)%M;
        res.h=(tmp.h+2*bb*tmp.f%M+2*aa*tmp.g%M+
                aa*aa%M*n3%M+bb*bb%M*(n+1)%M+
                2*aa*bb%M*n2%M)%
                M;
        return res;
    }

    ll m=(a*n+b)/c;
    if(!m) return res;
    auto tmp=solve(c,c-b-1,a,m-1);
    res.f=(m*n-tmp.f+M)%M;
    res.g=(m*n2+(M-tmp.f)*i2+(M-tmp.h)*i2)%M;
    res.h=(n*m%M*m-tmp.f-tmp.g*2+3*M)%M;
    return res;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);

    int t;
    std::cin>>t;
    while(t--){
        int n,a,b,c;
        std::cin>>n>>a>>b>>c;
        auto res=solve(a,b,c,n);
        std::cout<<res.f<<" "<<res.h<<" "<<res.g<<'\n';
    }
    return 0;
}