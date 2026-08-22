#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

const int N=38;


struct F3Vector{
    ll v1=0,v2=0;
};

F3Vector add(F3Vector a,F3Vector b){
    F3Vector res;
    res.v1=(a.v1&~(b.v1|b.v2))|(b.v1&~(a.v1|a.v2))|(a.v2&b.v2);
    res.v2=(a.v2&~(b.v1|b.v2))|(b.v2&~(a.v1|a.v2))|(a.v1&b.v1);
    return res;
}

struct Linear_Basis{
    F3Vector base[38];

    F3Vector mul2(F3Vector a){
        return {a.v2,a.v1};
    }

    F3Vector build(ll x){
        F3Vector res;
        for(int i=0;i<=37;i++){
            int d=x%3;
            if(d==1) res.v1|=(1ll<<i);
            else if(d==2) res.v2|=(1ll<<i);
            x/=3;
            if(x==0) break;
        }
        return res;
    }
    void insert(ll x){
        F3Vector v=build(x);
        for(int i=37;i>=0;i--){
            int d=0;
            if((v.v1>>i)&1) d=1;
            else if((v.v2>>i)&1) d=2;
            if(d==0) continue;
            if(base[i].v1==0&&base[i].v2==0){
                if(d==2) v=mul2(v);
                base[i]=v;
                return ;
            }

            if(d==1) v=add(v,mul2(base[i]));
            else v=add(v,base[i]);
        }
    }

    bool query(ll x){
        F3Vector v=build(x);
        for(int i=37;i>=0;i--){
            int d=0;
            if((v.v1>>i)&1) d=1;
            else if((v.v2>>i)&1) d=2;

            if(d==0) continue;
            if(base[i].v1==0&&base[i].v2==0) return false;
            if(d==1) v=add(v,mul2(base[i]));
            else v=add(v,base[i]); 
        }
        return true;
    }
};


void sol() {
    int n,q;
    cin>>n>>q;
    Linear_Basis ji;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        ji.insert(x);
    }
    while(q--){
        ll s;
        cin>>s;
        cout<<(ji.query(s)?"Yes":"No")<<'\n';
    }
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