#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string> sol(int n){
    vector<string>res={"0","1"};
    for(int i=2;i<=n;i++){
        vector<string> nwres;
        for(const string&s:res) nwres.push_back("0"+s);
        for(int j=res.size()-1;j>=0;j--) nwres.push_back("1"+res[j]);
        res=nwres;
    }
    return res;
}


int main(){
    int n;
    cin>>n;
    vector<string> ans=sol(n);
    for(const string&s:ans) cout<<s<<"\n";
    return 0;
}