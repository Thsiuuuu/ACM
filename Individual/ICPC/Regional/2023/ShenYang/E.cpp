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
int x,y,p,q;
int f[101][101][2];
void sol() {
    cin>>x>>y>>p>>q;
    if(x<=p){
        cout<<"1";
        return ;
    }
    else if(y-p>x+q){
        cout<<"-1";
        return ;
    }
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            f[i][j][0]=f[i][j][1]=-1;
        }
    }
    f[x][y][0]=0;
    queue<tuple<int,int,int>> Q;
    Q.push({x,y,0});
    while(Q.size()){
        auto [i,j,op]=Q.front();
        Q.pop();
        if(op==0){
            for(int a=0;a<=min(i,p);a++){
                for(int b=0;b<=min(p-a,j);b++){
                    if(i-a&&j-b>i-a+q) continue;
                    if(f[i-a][j-b][1]==-1){
                        f[i-a][j-b][1]=f[i][j][0]+1;
                        if(i-a==0){
                            cout<<f[i][j][0]+1<<'\n';
                            return ;
                        }
                        Q.push({i-a,j-b,1});
                    }
                }
            }
        }else{
            for(int a=0;a<=min(x-i,p);a++){
                for(int b=0;b<=min(p-a,y-j);b++){
                    if(x-i-a&&y-j-b>x-i-a+q) continue;
                    if(f[i+a][j+b][0]==-1){
                        f[i+a][j+b][0]=f[i][j][1]+1;
                        Q.push({i+a,j+b,0});
                    } 
                }
            }
        }
    }
    cout<<-1;
    // for(int i=0;i<=x;i++){
    //     for(int j=0;j<=y;j++){
    //         f[i][j]=1e9;
    //     }
    // }
    // f[0][0]=0;
    // for(int i=0;i<=x;i++){
    //     for(int j=max(y-x+i-q,0);j<=y;j++){
    //         if(i==0&&j==0) continue;
    //         if(j>i+q) continue;
    //         for(int a=0;a<=min(i,p);a++){
    //             for(int b=0;b<=min(j,p-a);b++){
    //                 if((a==0&&b==0)||f[i-a][j-b]==1e9) continue;
    //                 else f[i][j]=min(f[i][j],f[i-a][j-b]+2);
    //             }
    //         }
    //     }
    // }
    // if(f[x][y]==1e9) cout<<-1;
    // else cout<<f[x][y]-1;
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