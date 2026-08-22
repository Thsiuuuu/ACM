#include <bits/stdc++.h>
using namespace std;
#define int long long  

void sol(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            sum=k;
        }else{
            if(sum){
                s[i]='1';
                sum--;
            }
        }
    }
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') ans++;
    }
    cout<<ans<<'\n';
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