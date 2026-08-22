#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n;
    string s;
    cin>>n>>s;
    if(n==1){
        cout<<"0\n";
        return ;
    }
    vector<int> ans;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='1') ans.push_back(i+1);
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--) sol();
    return 0;
}