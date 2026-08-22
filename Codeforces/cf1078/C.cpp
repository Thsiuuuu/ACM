#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

const int N=1e5+10;
bitset<27> st[N];

void sol() {
    ll n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) st[i].reset();
    vector<vector<char>> mp(k+1,vector<char>(n+1));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }  
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            st[i][mp[j][i]-'a']=1;
        }
    }
    for(int su=1;su<=n;su++){
        if(n%su) continue;
        string res;
        for(int i=1;i<=su;i++){
            bitset<27> tmp;tmp.set();
            for(int j=i;j<=n;j+=su){
                tmp&=st[j];
                if(tmp.none()) break;
            }
            if(!tmp.none()){
                res.push_back((char)((int)tmp._Find_first()+'a'));
            }else break;
        }
        if(res.size()==su){for(int i=1;i<=n/su;i++)cout<<res;cout<<'\n';return;}
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