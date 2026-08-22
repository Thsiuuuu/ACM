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
int n,m,s;
namespace GenHelper
{
    unsigned z1,z2,z3,z4,b;
    unsigned rand_()
    {
    b=((z1<<6)^z1)>>13;
    z1=((z1&4294967294U)<<18)^b;
    b=((z2<<2)^z2)>>27;
    z2=((z2&4294967288U)<<2)^b;
    b=((z3<<13)^z3)>>21;
    z3=((z3&4294967280U)<<7)^b;
    b=((z4<<3)^z4)>>12;
    z4=((z4&4294967168U)<<13)^b;
    return (z1^z2^z3^z4);
    }
}
void srand(unsigned x)
{using namespace GenHelper;
z1=x; z2=(~x)^0x233333333U; z3=x^0x1234598766U; z4=(~x)+51;}
int read()
{
    using namespace GenHelper;
    int a=rand_()&32767;
    int b=rand_()&32767;
    return a*32768+b;
}
void sol() {
    cin>>n>>m>>s;
    srand(s);
    int rt;
    VI a(n+1);
    VI ls(n+1),rs(n+1);
    stack<int> stk;
    for(int i=1;i<=n;i++){
        a[i]=read();        
    }
    for(int i=1;i<=n;i++){
        int last=0;
        while(stk.size()&&a[stk.top()]<a[i]){
            last=stk.top();
            stk.pop();
        }
        if(stk.size()) rs[stk.top()]=i;
        if(last) ls[i]=last;
        stk.push(i);
    }
    while(stk.size()){
        rt=stk.top();
        stk.pop();
    }
    ull res=0;
    for(int i=1;i<=m;i++){
        int l=read()%n+1,r=read()%n+1;
        if(l>r) swap(l,r);
        for(int u=rt;;){
            if(r<u){
                u=ls[u];
            }else if(l>u){
                u=rs[u];
            }
            else{
                res+=a[u];
                break;
            }
        }
    }
    cout<<res<<'\n';
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