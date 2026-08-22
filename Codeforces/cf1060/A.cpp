#include <bits/stdc++.h>
using namespace std;
void sol(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int lst=-114514;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            if(lst<=i-k) ans++;
            lst=i;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}