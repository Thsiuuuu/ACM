#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    string s;
    int n;
    cin>>n;
    vector<int> a(n);
    int id1,idm;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            id1=i;
        }
        if(a[i]==n){
            idm=i;
        }
    }
    cin>>s;
    int ids=-1,ide=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            ids=i;
            break;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            ide=i;
            break;
        }
    }
    if(ids==ide&&ids==-1){
        cout<<"0\n";
    }else if(s[0]=='1'||s[n-1]=='1'){
        cout<<"-1\n";
    }else{
        
    }
    
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