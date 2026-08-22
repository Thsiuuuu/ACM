#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>


using namespace std;

#define int long long 

void sol(){

    int n;
    string s;

    int l,r;
    cin>>n>>l>>r>>s;
    bool st=true;
    for(int i=l-1;i<=r-1;i++){
        if(s[i]!='o'){
            //cout<<i<<" ";
            st=false;
            break;
        }
    }
    if(st) cout<<"Yes";
    else cout<<"No";

}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}