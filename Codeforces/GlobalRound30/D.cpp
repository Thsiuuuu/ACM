#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    int mx=-1;
    s=" "+s;
    t=" "+t;
    vector<int> pos(27,INT32_MAX);//记录s的当前最近字符
    for(int i=1;i<=n;i++){
        pos[s[i]-'a']=i;
        if(pos[t[i]-'a']==INT32_MAX){
            cout<<"-1\n";
            return ;
        }
        mx=max(i-pos[t[i]-'a'],mx);
    }
    cout<<(mx<=k?mx:-1)<<'\n';
    int cnt=0;
    queue<string> que;
    while(cnt<mx){
        string cpy=s;
        for(int i=1;i<=n;i++){
            if(i+1<=n){
                cpy[i+1]=s[i];
            }
            if(s[i]==t[i]){
                cpy[i]=s[i];
            }
        }
        s=cpy;
        que.push(s);
        cnt++;
    }
    if(s==t){
        while(que.size()){
            cout<<que.front().substr(1,n)<<'\n';
            que.pop();
        }
    }else{
        cout<<"-1\n";
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