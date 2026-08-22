#include <bits/stdc++.h>
using namespace std;

#define int long long 
void sol(){
    string s;
    vector<int> num(27,0);
    cin>>s;
    int cnt=0;
    bool fl1=true,fl2=true;
    for(int i=0;i<s.size();i++){
        num[s[i]-'a']++;
        if(num[s[i]-'a']==1) cnt++;
    }
    if(cnt==26){
        if(num[s[0]-'a']==1&&num[s[s.size()-1]-'a']==1){
            cout<<"No\n";
            cout<<"2\n";
        }
        else cout<<"Yes\n";
    }else{
        cout<<"No\n";
        cout<<"1 2\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}