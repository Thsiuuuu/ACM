#include <bits/stdc++.h>
using namespace std;
int pre[1010][28];

int cnt[28];
int vis[28];

void sol(){
    int n;
    string s;
    cin>>n>>s;
    
    s=" "+s;
    vector<string> st;

    for(int i=1;i<=s.size()-1;i++){
        
        bool check=true;
        cnt[s[i]-'a'+1]=0;

        if(vis[s[i]-'a'+1]){
            for(int j=i-1;j>=vis[s[i]-'a'+1]+1;j--){
                if(vis[s[j]-'a'+1]==j){
                    cnt[s[j]-'a'+1]++;
                }
            }
        }else{
            for(int j=1;j<=26;j++){
                if(vis[j]&&(s[i]-'a'+1)!=j){
                    cnt[j]++;
                }
            }
        }

        vis[s[i]-'a'+1]=i;
        
        string res=" ";
        for(int j=1;j<=i;j++){
            res=res+(char)('a'+cnt[s[j]-'a'+1]);
        }
        st.push_back(res);
    }
    sort(st.begin(),st.end());


    // for(string tri:st){
    //     cout<<tri<<'\n';
    // }
    cout<<st[st.size()-1].substr(1,st[st.size()-1].size()-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    sol();
    return 0;
} 