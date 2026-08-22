#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    string s,t;
    cin>>s>>t;
    vector<int> nums(27,0),numt(27,0);
    for(int i=0;i<s.size();i++){
        nums[s[i]-'a']++;
    }
    for(int i=0;i<t.size();i++){
        numt[t[i]-'a']++;
    }
    int cur=0;
    for(int i=0;i<26;i++){
        if(numt[i]<nums[i]){
            cout<<"Impossible\n";
            return ;
        }
    }
    for(int i=0;i<26;i++){
        while(cur<s.size()&&(s[cur]-'a')<=i){
            numt[s[cur]-'a']--;
            nums[s[cur]-'a']--;
            cout<<s[cur++];
        }
        while(numt[i]-1>=nums[i]){
            cout<<(char)('a'+i);
            numt[i]--;
        }
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}