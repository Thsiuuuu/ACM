#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
char dir[5]={'R','D','L','U'};


void sol(){
    int n,k;
    cin>>n>>k;
    if(k==n*n-1){
        cout<<"no\n";
        return ;
    }
    vector<vector<char>> mp(n+1,vector<char>(n+1,'a'));
    int cnt=k;
    int cntx=1;
    int cnty=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n&&cnt>0;j++){
            mp[i][j]='L';
            cnt--;
            cnty++;
        }
        if(cnt<=0){
            break;
        }
        cntx++;
        cnty=1;
    }

    // cout<<cntx<<" "<<cnty<<'\n';
    if(cntx==n){
        for(int i=cnty;i<=n-1;i++){
            mp[cntx][i]='R';
        }
        mp[cntx][n]='L';
    }else if(cntx<n){
        for(int i=cnty;i<=n;i++){
            mp[cntx][i]='D';
        }
        cntx++;
        for(int i=cntx;i<=n;i++){
            for(int j=1;j<n;j++){
                mp[i][j]='R';
            }
            mp[i][n]='L';
        }
    }


    cout<<"yes\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mp[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}