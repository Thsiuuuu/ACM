#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N=102;

int mar[N][N];

int n;

int main(){
    

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    cin>>n;
    for(int i=1;i<=n;i++){
        int u,k;
        cin>>u>>k;
        while(k--){
            int v;
            cin>>v;
            mar[u][v]=1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mar[i][j]<<" ";
        }
        cout<<"\n";

    }

    return 0;
}