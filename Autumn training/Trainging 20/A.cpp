#include <bits/stdc++.h>
using namespace std;

void sol(){

    int n;
    string s;
    cin>>n>>s;

    pair<int,int> res;
    if(s[0]!=s[n-1]){
        cout<<"empty\n";
        return ;
    }
    char flag='0'+(s[0]-'0')^1;

    int mx=1145141;
    for(int i=0;i<n;){
        int ans=1;
        int j=i;
        while(j+1<n&&s[j]==s[j+1]){
            // cout<<ans<<" ";
            ans++;
            j++;
        }

        j++;

        if(ans>1&&s[i]==flag){
            cout<<"empty\n";
            return ;
        }else if(ans<mx&&s[i]==s[0]){
            res={i,j-1};
            mx=ans;
        }
        i=j;
    }

    // cout<<res.first<<" "<<res.second;
    for(int i=res.first;i<=res.second;i++){
        cout<<s[i];
    }
    cout<<"\n";
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