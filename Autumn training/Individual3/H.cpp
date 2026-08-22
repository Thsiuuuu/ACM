#include  <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> a(m+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    while(q--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==2){
            cout<<a[x][y]<<'\n';
        }else{
            vector<int> tmp;
            for(int i=1;i<=n;i++){
                tmp.push_back(a[x][i]);
            }
            for(int i=1;i<=n;i++){
                tmp.push_back(a[y][i]);
            }
            sort(tmp.begin(),tmp.end());
            for(int i=0;i<n;i++){
                a[x][i+1]=tmp[i];
            }
            for(int i=0;i<n;i++){
                a[y][i+1]=tmp[i+n];
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();
    return 0;
}