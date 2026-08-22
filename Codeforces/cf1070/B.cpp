#include <bits/stdc++.h>
using namespace std;
#define int long long 

void sol(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> num;
    int l=0;
    while(l<n&&s[l]=='0'){
        s=s+"0";
        l++;
    }
    s=s+"1";
    for(int i=l;i<=s.size()-1;i++){
        if(s[i]=='1'){
            if(i-l>=2){
                num.push_back(i-l-1);
            }
            l=i;
        }
    }
    if(num.size()==0){
        cout<<"0\n";
    }else{
        sort(num.begin(),num.end(),greater<int>());
        cout<<num[0]<<'\n';
    }
}
signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}