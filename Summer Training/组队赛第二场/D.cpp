#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define i128 __int128_t
#define VL vector<ll>
#define VI vector<int>

int dir[5]={-1,-1,0,0,-1};
char mp[510][510];
int n,m;
bool check(int x,int y){
    return x&&y&&x<=n&&y<=m;
}
void sol(){
    cin>>n>>m;
    int all=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            if(mp[i][j]=='1') all++;
        }
    }
    // cout<<all<<'\n';
    bool f1,f2,f3;
    f1=f2=f3=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cout<<i<<" "<<j<<'\n';
            int sum=0;
            bool f=true;
            for(int k=0;k<=3;k++){
                int x=i+dir[k],y=j+dir[k+1];
                // cout<<"? "<<x<<" "<<y<<'\n';
                if(check(x,y)){
                    if(mp[x][y]=='0') sum++;
                }else{
                    f=false;
                    break;
                }
            }
            if(f){
                // cout<<i<<" "<<j<<" "<<sum<<'\n';
                if(sum>=2) f1=true;
                else if(sum==1) f2=true;
                else f3=true;
            }
        }
    }
    if(f1) cout<<all;
    else if(f2) cout<<all-1;
    else cout<<all-2;
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}