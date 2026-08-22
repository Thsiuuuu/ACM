#include <bits/stdc++.h>
using namespace std;
/*

    悬线法

*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n+1,vector<int>(m+1)),l,r,up;
    l=r=up=a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            up[i][j]=1;
            if(i-1>=1&&(a[i-1][j]^a[i][j])){
                up[i][j]=up[i-1][j]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            l[i][j]=j;
            if(j>=2&&(a[i][j-1]^a[i][j])){
                l[i][j]=l[i][j-1];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            r[i][j]=j;
            if(j<=m-1&&(a[i][j+1]^a[i][j])){
                r[i][j]=r[i][j+1];
            }
        }
    }
  
    int ans1=-1,ans2=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>=2&&(a[i-1][j]^a[i][j])){
                l[i][j]=max(l[i][j],l[i-1][j]),r[i][j]=min(r[i][j],r[i-1][j]);
            }
            int len=r[i][j]-l[i][j]+1;
            ans1=max(ans1,min(len,up[i][j])*min(len,up[i][j]));
            ans2=max(ans2,len*up[i][j]);
        }
    }
    cout<<ans1<<'\n'<<ans2;
    return 0;
}