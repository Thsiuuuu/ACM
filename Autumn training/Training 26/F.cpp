#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string s,x;
    cin>>s>>x;
    int del=s.size()+x.size();
    for(int i=0;i<s.size();i++){
        if(i==(int)(del/2)) cout<<" ";
        cout<<s[i];
    }
    return 0;
}