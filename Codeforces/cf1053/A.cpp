#include <bits/stdc++.h>
using namespace std;
/*

    检验逆序对，如果存在逆序对，那么只有一个，否则就是最大值出现几次就是几次

*/

void sol(){
    int n,m;
    cin>>n>>m;
    int fr,nw;
    bool flag=true;
    for(int i=0;i<m;i++){
        
        if(i){
            fr=nw;
        }
        cin>>nw;
        if(i&&fr!=nw-1){
            flag=false;
        }
    }
    if(flag){
        cout<<n-nw+1<<'\n';
    }else{
        cout<<"1\n";
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}