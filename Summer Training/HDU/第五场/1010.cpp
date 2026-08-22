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
const int N=101;

void sol() {
    int n;
    VII LB(102,VI(102,0));
    cin>>n;
    for(int i=1;i<=n;i++){
        int c,s;cin>>c>>s;
        LB[i][101]=s;
        for(int j=0;j<c;j++){
            int l;cin>>l;
            LB[i][l]^=1;
        }
    }
    // for(int i=1;i<=3;i++){
    //     for(int j=1;j<=7;j++){
    //         cout<<LB[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    for(int i=1;i<=100;i++){
        bool f=false;
        for(int j=1;j<=100;j++){
            if(j<i&&LB[j][j]==1) continue;
            else if(LB[j][i]==1){
                if(i^j)  swap(LB[i],LB[j]);
                f=true;
                break;
            }
        }
        if(f){
            for(int j=1;j<=100;j++){
                if(j!=i&&LB[j][i]==1){
                    for(int k=i;k<=101;k++){
                        LB[j][k]^=LB[i][k];
                    }
                }
            }
        }
    }
    // for(int i=1;i<=3;i++){
    //     for(int j=1;j<=101;j++){
    //         cout<<LB[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    int q;
    cin>>q;
    while(q--){
        vector<int> cr(102,0),ob(102,0);
        int d;cin>>d;
        for(int i=0;i<d;i++){
            int l;cin>>l;
            ob[l]^=1;
        }
        bool f=true;
        for(int i=1;i<=100;i++){
            if(cr[i]==ob[i]) continue;
            if(LB[i][i]==0){
                cout<<"-1\n";
                f=false;
                break;
            }else{
                for(int k=i;k<=101;k++){
                    cr[k]^=LB[i][k];
                }
            }
            if(cr[i]!=ob[i]){
                cout<<"-1\n";
                f=false;
                break;
            }
        }
        if(f){
            cout<<cr[101]<<'\n';
        }
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