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
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
const int N=1e5+2;
bitset<N> g[26],f;
string s;
int n,q,m;
void sol() {
    cin>>s;
    cin>>q;
    for(int i=0;i<s.size();i++){
        g[s[i]-'a'][i]=1;
    }
    while(q--){
        int op;cin>>op;
        if(op==1){
            int x;char c;cin>>x>>c;
            x--;
            g[s[x]-'a'][x]=0;
            s[x]=c;
            g[s[x]-'a'][x]=1;
        }else{
            int l,r;string y;cin>>l>>r>>y;
            l--,r--;
            m=y.size();
            if(m>r-l+1){
                cout<<0<<'\n';
                continue;
            }
            f.set();
            for(int i=0;i<m;i++){
                f&=(g[y[i]-'a']>>i);
            }
            ll ans=0;
            ans+=(f>>l).count()-(f>>(r-m+1+1)).count();
            cout<<ans<<'\n';
        }
    }
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