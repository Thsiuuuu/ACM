#include <bits/stdc++.h>
using namespace std;

void sol1(){
    int n;
    cin>>n;
    string cpy=to_string(n);
    while(cpy.size()<5){//没有特判1e4的情况
        cpy='0'+cpy;
    }
    string s=cpy;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        string cpn=to_string(x);
        while(cpn.size()<2){
            cpn='0'+cpn;
        }
        s=s+cpn;
    }
    for(int i=0;i<s.size();i++){
        cout<<(char)(s[i]-'0'+'a');
    }
}

void sol2(){
    string s;
    cin>>s;
    bool f1=false;
    for(int i=0;i<5;i++){
        if(s[i]!='a'){
            f1=true;
            cout<<(s[i]-'a');
        }else if(f1) cout<<(s[i]-'a');
    }
    cout<<'\n';
    for(int i=5;i<s.size();i+=2){
        if(s[i]!='a') cout<<(s[i]-'a');
        cout<<(s[i+1]-'a')<<" ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string s;
    cin>>s;
    if(s=="first") sol1();
    else sol2();
    return 0;
}