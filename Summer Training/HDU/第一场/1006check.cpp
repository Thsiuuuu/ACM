#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
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
const int N=1;
bool is[N+1];
ll go[N+1],all[N+1];
int tim=0;
void dfs1(int level){
    if(level==N){
        tim++;
        // cout<<tim<<"\n";
        for(int i=1;i<=N;i++){
            cout<<go[i]<<" ";
            // all[i]+=go[i];
            // cout<<tim<<'\n';
        }
        for(int i=1;i<=N;i++){
            all[i]+=go[i];
            cout<<tim<<'\n';
        }
        cout<<'\n';
        return ;
    }

    //枚举位置i
    for(int i=1;i<=N;i++){
        // tim++;
        // cout<<tim<<'\n';
        if(!is[i]){
            is[i]=true;
            int cnt=0;
            for(int k=1;k<=N;k++){
                if(is[k]){
                    int j=k;
                    while(j<=N&&is[j]) j++;
                    k=j;
                    cnt++;  
                }
            }
            go[i]=cnt;
            dfs1(level+1);
            // cout<<tim<<'\n';
            is[i]=false;
        }
    }
}
void sol() {
    dfs1(0);
    cout<<"! ! ?\n";
    // for(int i=1;i<=N;i++){
    //     cout<<all[i]<<" ";
    // }
    // cout<<'\n';
    // cout<<tim<<'\n';
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