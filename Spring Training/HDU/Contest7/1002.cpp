#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long
void sol() {
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    vector<vector<bool>> row(n,vector<bool>(n*n,false)),cal;
    cal=row;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            row[i][a[i][j]-1]=true;
            cal[j][a[i][j]-1]=true;
        }
    }
    // cout<<cal[1][0]<<'\n';
    vector<int> ans;
    for(int i=1;i<=n*n;i++){
        bool f=true;
        for(int x=0;x<n;x++){
            if(row[x][i-1]==false){
                f=false;
                break;
            }
        }
        if(f){
            for(int x=0;x<n;x++){
                if(cal[x][i-1]==false){
                    f=false;
                    break;
                }
            }
        }
        if(f) ans.push_back(i);
    }
    
    cout<<ans.size()<<'\n';
    for(int x:ans) cout<<x<<" ";
    cout<<'\n';
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