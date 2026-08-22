#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,m;
    cin>>n>>m;
    vector<vector<int>> diff(n+2,vector<int>(n+2,0));
    while(m--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        diff[a][b]++;
        diff[c+1][d+1]++;
        diff[a][d+1]--;
        diff[c+1][b]--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            diff[i][j]+=diff[i][j-1]+diff[i-1][j]-diff[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<diff[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}