#include <bits/stdc++.h>
using namespace std;
// #define int  long long 

void sol(){
    map<char,int> mp;
    string  s,p;
    cin>>s>>p;
    for(int i=0;i<p.size();i++){
        mp[p[i]]++;
    }
    for(const auto&[key,val]:mp){
        if(val&1){
            if(key=='v'){
                for(int i=0;i<s.size();i++){
                    if(s[i]=='b') s[i]='p';
                    else if(s[i]=='p') s[i]='b';
                    else if(s[i]=='q') s[i]='d';
                    else if(s[i]=='d') s[i]='q';
                }
            }else if(key=='h'){
                string t;
                for(int i=s.size()-1;i>=0;i--){
                    char x;
                    if(s[i]=='b') x='d';
                    else if(s[i]=='d') x='b';
                    else if(s[i]=='p') x='q';
                    else x='p';
                    t+=x;
                }
                s=t;
            }else{
                string t;
                for(int i=s.size()-1;i>=0;i--){
                    char x;
                    if(s[i]=='b') x='q';
                    else if(s[i]=='q')x='b';
                    else if(s[i]=='p') x='d';
                    else x='p';
                    t+=x;
                }
                s=t;
            }
        }
    }
    cout<<s;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    sol();
    return 0;
}