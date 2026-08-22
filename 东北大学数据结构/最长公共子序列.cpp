#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define endl "\n"


const int N=1010;

int t;

void sol(){


    vector<vector<int>> f(N,vector<int>(N,0));
    string a,b;
    cin>>a>>b;
    a=" "+a;
    b=" "+b;
    int n=a.size()-1,m=b.size()-1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j]=max(f[i-1][j-1]+1,f[i][j]);
        }
    }

    cout<<f[n][m]<<endl;

}


int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--) sol();
    return 0;
}