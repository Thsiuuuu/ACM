#include <bits/stdc++.h>
using namespace std;



int team[420];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> arr(430,vector<int>(15,-1));
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c<240){
            if(arr[a][b]==-1){
                arr[a][b]=c;
                team[a]++;
                cout<<b<<'\n';
            }else{
                cout<<"0\n";
            }
        }else{
            if(arr[a][b]==-1&&team[a]<3){
                arr[a][b]=c;
                team[a]++;
                cout<<b<<'\n';
            }else{
                cout<<"0\n";
            }
        }
    }
    return 0;
}