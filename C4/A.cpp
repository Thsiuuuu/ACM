#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using  namespace std;
/*

    从上往下，从左往右涂
    这样每个点至多会受到两种制约

    0状态表示没有占用
    1状态表示已经占用

*/

#define int long long 

bool st[103][103][4]={false};

signed main(){
    
    int n,col;
    cin>>n;
    // vector<vector<node>> grid(n+3,vector<node>(n+3));
    // //int t=n*n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            cin>>col;
            // auto cur=grid[i][j];
            for(int k=1;k<=3;k++){
                if(k==col){
                    continue;
                }else{
                    if(!st[i][j][k]){
                        st[i][j][k]=true;
                        st[i][j+1][k]=true;
                        st[i+1][j][k]=true;
                        cout<<k<<" "<<i<<" "<<j<<"\n";
                        cout<<"\n";
                        cout.flush();
                        break;
                    }
                }
            }
        }
    }

}