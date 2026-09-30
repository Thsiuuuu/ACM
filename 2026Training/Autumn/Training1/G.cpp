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
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int n;
// a[2501][2501];
// bool vis[2540*2500+4];
// // int cnt;
// void dfs(int x,int y){
//     // if(cnt==100) return ;
//     if(x==n){
//         cerr<<x<<" "<<y<<'\n';
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cout<<a[i][j]<<' ';
//             }
//             cout<<'\n';
//         }
//         cout<<"******\n";
//         return; 
//     }   
//     for(int i=1;
//         i<=
//         n*n
//         // n*n+40*n
//         ;i++){

//         // if(cnt==100) return ;
//         // cnt++;
//         if(vis[i]) continue;
//         if(x>=1&&gcd(a[x-1][y],i)!=1) continue;
//         if(y>=1&&gcd(a[x][y-1],i)!=1) continue;
//         a[x][y]=i;
//         vis[i]=1;
//         if(y+1==n) dfs(x+1,0);
//         else       dfs(x,y+1);
//         vis[i]=0;
//     }
// }
const int N=2540*2500+410;
bool viss[N];
int prime[N/2+1];
int cnt=0;
void init(){
    for(ll i=2;i<N;i++){
        if(!viss[i]){
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>=N){
                break;
            }
            viss[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
// VI all[2540*2500+4];
void sol() {
    cin>>n;
    int x=-1;
    for(int i=0;i<cnt;i++){
        if(prime[i]>n){
            x=prime[i];
            break;
        }
    }
    int base=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<base+j<<" ";
        }
        cout<<'\n';
        base+=x;
    }
    // for(int i=1;i<=n;i++){
    //     int x=i;
    //     for(int j=2;j<=x;j++){
    //         if(x%j==0){
    //             all[i].push_back(j);
    //             while(x%j==0) x/=j;
    //         }
    //     }
    //     if(x>1) all[i].push_back(x);
    // }
    // int cnt=1;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         bool is=false;
    //         is=((i&&gcd(cnt,a[i-1][j])>1)||(j&&gcd(cnt,a[i][j-1])>1)||vis[cnt]);
    //         if(!is) a[i][j]=cnt++;
    //         else{
    //             for(int number=0;number<cnt;number++){
    //                 if()
    //             }
    //         }
    //     }
    // }
    // dfs(0,0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    init();
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}