#include <iostream>
#include <algorithm>


using namespace std;

#define int long long 


int n,m,c;
const int maxn=1002;

int num[maxn][maxn],sum[1002][1002];


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n>>m>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>num[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+num[i][j];
        }
    }

    int mx=-1145141919,ox=1,oy=1;
    for(int i=c;i<=n;i++){
        for(int j=c;j<=m;j++){
            int com=sum[i][j]-sum[i][j-c]-sum[i-c][j]+sum[i-c][j-c];
            if(com>mx){
                ox=i-c+1,oy=j-c+1;
                mx=max(com,mx);
            }
        }
    }

    cout<<ox<<" "<<oy;
    return 0;

    
}
