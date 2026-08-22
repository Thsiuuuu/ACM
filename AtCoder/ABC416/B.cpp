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

string s;


void sol(){

    cin>>s;
    int len=s.size();
    string t=" ";
    int cnt=0;
    for(int i=0;i<len;i++){
        if(s[i]=='#'){
            t+="#";
            cnt=0;
        }else{
            if(!cnt) t+="o";
            else t+=".";
            cnt++;
        }

    }
    for(int i=1;i<=len;i++){
        cout<<t[i];
    }
    
   
}


signed main(){


    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    sol();

}