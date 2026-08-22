#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

/*

    一个点只要最少堵住四个角一定是不联通的
    然后还有可能靠墙，取两个点的最小值即可

*/

int t;
int dir[5]={-1,0,1,0,-1};
struct Point{
    int x,y;
};
void sol(){
    vector<Point> num(2);
    vector<int> ans(2,4);
    int n,m;
    cin>>n>>m;
    cin>>num[0].x>>num[0].y>>num[1].x>>num[1].y;
    
    for(int i=0;i<=1;i++){
        for(int j=0;j<=3;j++){
            if(num[i].x+dir[j]==0||num[i].y+dir[j+1]==m+1||num[i].x+dir[j]==n+1||num[i].y+dir[j+1]==0){
                ans[i]--;
            }
        }
    }
    cout<<min(ans[0],ans[1])<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}