#include <bits/stdc++.h>
using namespace std;

#define int long long 
/*


    要注意cin是碰到\n停止，\n还在缓冲区里面，所以cin换成getline之前要采用cin.ignore忽略换行符
    但是geline是碰到第一个换行符为止，然后丢掉这个换行符


    读入一整行数据流程：
        声明一个字符串string s;
        读入一整行字符串getline(cin,s);
        把字符串当输入流处理 istringstream iss(s);
        开一个字符串vector vector<string> tokens;
        按空格进行分割
        string token;
        while(iss>token){
            tokens.push_back(token);
        }



*/


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    int ans=0;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        istringstream iss(s);
        vector<string> tokens;
        string token;
        while(iss>>token){
            tokens.push_back(token);
        }
        // cout<<tokens[0]<<'\n';
        if(tokens[0].size()==3){
            for(int i=0;i<tokens[1].size();i++){
                if(tokens[1][i]=='=') ans+=4;
            }
        }else if(tokens[0].size()==4){
            for(int i=0;i<tokens[1].size();i++){
                if(tokens[1][i]=='=') ans+=8;
            }
        }else if(tokens[0].size()==5){
            int cur=0;
            bool st=false;
            for(int i=2;i<tokens.size();i++){
                for(int j=0;j<tokens[i].size();j++){
                    if(tokens[i][j]=='['){
                        st=true;
                    }else if(tokens[i][j]==']'){
                        st=false;
                        ans+=(cur*4);
                        cur=0;
                    }else if(st){
                        cur=cur*10+(tokens[i][j]-'0');
                    }
                }
            }
        }else if(tokens[0].size()==6){
            if(tokens[0]=="String"){
                bool st=false;
                int cur=0;
                for(int i=0;i<tokens[1].size();i++){
                    if(tokens[1][i]=='"'){
                        if(!st){
                            st=true;
                        }else if(st){
                            st=false;
                        }
                    }else if(st){
                        cur++;
                    }
                }
                ans+=cur;
                // cout<<tokens[0]<<" "<<cur;
            }else if(tokens[0]=="long[]"){
                int cur=0;
                bool st=false;
                for(int i=2;i<tokens.size();i++){
                    for(int j=0;j<tokens[i].size();j++){
                        if(tokens[i][j]=='['){
                            st=true;
                        }else if(tokens[i][j]==']'){
                            st=false;
                            ans+=(cur*8);
                            cur=0;
                        }else if(st){
                            cur=(cur*10)+(tokens[i][j]-'0');
                        }
                    }
                }
                // cout<<tokens[0]<<" "<<cur;
            }
        }
    }
    int bit=1024*1024*1024;
    int cur;
    for(int i=0;i<4;i++){
        cur=(ans/bit);
        if(cur){
            cout<<cur;
            if(i==0){
                cout<<"GB";
            }else if(i==1){
                cout<<"MB";
            }else if(i==2){
                cout<<"KB";
            }else{
                cout<<"B";
            }
        }
        ans=ans%bit;
        bit/=1024;
    }
    return 0;
}