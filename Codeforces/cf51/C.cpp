#include <bits/stdc++.h>
using namespace std;
void sol(){
    vector<vector<int>> vec(105);
    vector<int> a;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        vec[x].push_back(i);
    }
    string s(n+1,'A');
    int num1=0,num2=0;
    for(int i=1;i<=100;i++){
        if(vec[i].size()==1) num1++;
        else if(vec[i].size()>=3) num2++;
    }
    if((num1&1)&&num2==0){
        cout<<"NO\n";
        return ;
    }else{
        if(num1&1){
            bool f1=false;
            char cur='A';
            for(int i=1;i<=100;i++){
                if(vec[i].size()==0) continue;
                else if(vec[i].size()==1){
                    s[vec[i][0]]=cur;
                    cur=((cur=='A')?'B':'A');
                }else if(vec[i].size()==2){
                    for(int x:vec[i]){
                        s[x]='A';
                    }
                }else{
                    if(f1){
                        for(int x:vec[i]){
                            s[x]='A';
                        }
                    }else{
                        for(int j=0;j<vec[i].size();j++){
                            if(j==0){
                                s[vec[i][j]]='B';
                            }else{
                                s[vec[i][j]]='A';
                            }
                        }
                        f1=true;
                    }
                }
            }
        }else{
            char cur='A';
            for(int i=1;i<=100;i++){
                if(vec[i].size()==1){
                    s[vec[i][0]]=cur;
                    cur=((cur=='A')?'B':'A');
                }else{
                    for(int x:vec[i]){
                        s[x]='A';
                    }
                }
            }
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++) cout<<s[i];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}