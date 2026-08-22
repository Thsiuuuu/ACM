#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> s;
    int n;
    cin>>n;
    while(n--){
        string st;
        cin>>st;
        s.push_back(st);
    }
    sort(s.begin(),s.end());
    for(auto ck:s){
        cout<<ck<<'\n';
    }
    return 0;
}