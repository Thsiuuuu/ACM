#include <bits/stdc++.h>
using namespace std;

// void sol(){

// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i+5<=s.size();i++){
        if(s[i]=='e'&&s[i+1]=='d'&&s[i+2]=='g'&&s[i+3]=='n'&&s[i+4]=='b'){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}