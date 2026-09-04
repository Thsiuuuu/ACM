#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>


      T1
2 3
1 2
1 2 0
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
const int N=20;
int A[N],B[N],a[N][N],row[N],col[N];
int n,m;
void dfs(int x,int y){
    if(x>n){
        for(int i=1;i<=n;i++){
            if(A[i]^row[i]) return ;
        }
        for(int i=1;i<=m;i++){
            if(B[i]^col[i]) return ;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<'\n';
        }
        cout<<"############\n";
        return ;
    }
    if(row[x]+1<=A[x]&&col[y]+1<=B[y]){
        row[x]++,col[y]++;
        a[x][y]=1;
        if(y==m){
            dfs(x+1,1);
        }else{
            dfs(x,y+1);
        }
        row[x]--,col[y]--;
        a[x][y]=0;
    }
    if(y==m){
        dfs(x+1,1);
    }else{
        dfs(x,y+1);
    }
}

void sol() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=m;i++) cin>>B[i];
    dfs(1,1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("Ein.txt","r",stdin);
    freopen("Eout.txt","w",stdout);
    int t = 1;
    cin >> t;

    while (t--) {
        sol();
    }
    return 0;
}