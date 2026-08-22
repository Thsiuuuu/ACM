#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    string s;
    cin>>n>>s;
    int ans=0;
    for(int i=0;i<n;i++){
        int j=i;
        int len=1;
        while(j+1<n&&s[i]==s[j+1]){
            j++;
            len++;
        }
        if(len>1) ans++;
    }
    cout<<ans;
    return 0;
}