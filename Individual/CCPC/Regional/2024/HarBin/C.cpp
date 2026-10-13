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

void sol() {
    int n;cin>>n;
    vector<pair<char,int>> all(n);
    for(int i=0;i<n;i++){
        cin>>all[i].first>>all[i].second;
    }
    vector<pair<char,int>> ans;
    char bg=all[0].first,last=bg;
    ans.push_back({'Z',all[0].second});
    for(int i=1;i<all.size();i++){
        auto [direct,wei]=all[i];
        if(last==direct){
            ans.push_back({'Z',wei});
        }else{
            if(
                (last=='W'&&direct=='N')||
                (last=='N'&&direct=='E')||
                (last=='E'&&direct=='S')||
                (last=='S'&&direct=='W')
            ) {
                ans.push_back({'R',-1});
                last=direct;
            }else {
                ans.push_back({'L',-1});
                last=direct;
            }
            ans.push_back({'Z',wei});
        }
    }
    cout<<ans.size()<<" "<<bg<<'\n';
    for(auto[key,val]:ans){
        cout<<key<<" ";
        if(val!=-1) cout<<val;
        cout<<'\n';
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