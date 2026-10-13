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
map<array<int,6>,bool> sg;
bool dfs(const array<int,6>& tmp){
    auto it=sg.find(tmp);
    if(it!=sg.end()) return it->second;
    if(tmp.back()==0) return false;
    for(int i=0;i<6;i++){
        if(tmp[i]==0) continue;
        array<int,6> nxt;
        for(int j=0;j<6;j++) nxt[j]=min(tmp[j],tmp[i]);
        nxt[i]-=1;
        sort(nxt.begin(),nxt.end());
        if(!dfs(nxt)) return sg[tmp]=true;
    }
    return sg[tmp]=false;
}
void sol() {
    sg[{0,0,0,0,0}]=false;
    for(int i=0;i<=10;i++){
        for(int j=i;j<=10;j++){
            for(int k=j;k<=10;k++){
                for(int a=k;a<=10;a++){
                    for(int b=a;b<=10;b++){
                        for(int c=b;c<=10;c++){
                            array<int,6> tmp={i,j,k,a,b,c};
                            bool is=dfs(tmp);
                            if(!is){
                                cout<<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<" "<<'\n'; //<<is<<'\n';
                            }
                        }
                    }
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    freopen("Lout.txt","w",stdout);
    while (t--) {
        sol();
    }
    return 0;
}