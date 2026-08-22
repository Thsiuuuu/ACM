#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n,k;
    cin>>n>>k;
    int n1=0,n2=0,n3=0,tot=n;
    string s;
    cin>>s;
    if(k==n){
        for(int i=0;i<n;i++)cout<<"-";
        cout<<'\n';
        return ;
    }else{
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') n1++;
            else if(s[i]=='1') n2++;
            else n3++;
        }
        for(int i=0;i<n1;i++) cout<<"-";
        tot=max(n-n1-n2-2*n3,0);
        for(int i=0;i<(n-n1-n2);i++){
            if(tot&&(i<n3+tot)&&(i>=n3)) cout<<"+";
            else cout<<"?";
        }
        for(int i=0;i<n2;i++) cout<<"-";
        cout<<'\n';
    }
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