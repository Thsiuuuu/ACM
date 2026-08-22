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
    int m,n;
    while(cin>>m>>n){
        vector<vector<char>> mp(m,vector<char>(m,'.'));
        for(int i=0;i<n;i++){
            int s;
            ll x,y;
            cin>>s>>x>>y;
            // cout<<"hek\n";
            if(s==0){
                for(int cur=x+1;cur>=0&&cur>=x-1;cur--){
                    // cout<<"h0\n";
                    if(cur>=0&&cur<m&&y>=0&&y<m){
                        if(cur==x) mp[cur][y]='o';
                        else mp[cur][y]='_';
                    }
                }
            }
            else{
                // if(x+s<0||y+s+1<0||) continue;
                for(int cx=x-1;cx<=x+1;cx++){
                    if(cx>=0&&cx<m&&y>=0&&y<m){
                        // cout<<"h1\n";
                        // cout<<cx<<" ";
                        if(cx==x) mp[cx][y]='|';
                        else      mp[cx][y]='_';
                        // cout<<cx<<" "<<y<<" "<<mp[cx][y]<<'\n';
                    }
                }//树根
                for(int cy=y+1;cy<=y+s;cy++){
                    if(x>=0&&x<m&&cy>=0&&cy<m)  mp[x][cy]='|';
                    for(int cx=x+1;cx<=x+1;cx++){
                        // cout<<cx<<"\n";
                        if(cx>=0&&cx<m&&cy>=0&&cy<m){
                            // cout<<"h3\n";
                            mp[cx][cy]='\\';
                        }
                    }//佑树叉
                    for(int cx=x-1;cx>=x-1;cx--){
                        // cout<<cx<<'\n';
                        if(cx>=0&&cx<m&&cy>=0&&cy<m){
                            // cout<<"h4\n";
                            mp[cx][cy]='//';
                        }
                    }//左树杈
                }//树干
                if(y+s+1>=0&&y+s+1<m&&x>=0&&x<m) mp[x][y+s+1]='^';//书剑
            }
        }
        for(int i=0;i<m+2;i++) cout<<'*';
        cout<<'\n';
        for(int j=m-1;j>=0;j--){
            cout<<'*';
            for(int i=0;i<m;i++){
                cout<<mp[i][j];
            }
            cout<<'*';
            cout<<'\n';
        }
        for(int i=0;i<m+2;i++) cout<<"*";
        cout<<'\n';
        cout<<'\n';
    }
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}