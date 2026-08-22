#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long  

struct node{
    string st,ed;
    node();
    node(string st,string ed):st(st),ed(ed){}
};

void sol() {
    int n;cin>>n;
    vector<node> f1,f2;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        string tim;cin>>tim;
        string s1,s2;
        for(int i=0;i<tim.size();i++){
            if(tim[i]=='-'){
                if(i<5) s1='0'+tim.substr(0,4);
                else s1=tim.substr(0,5);
                if(tim.size()-i-2<5) s2='0'+tim.substr(i+2,4);
                else s2=tim.substr(i+2,5);
                break;
            }
        }
        if(s=="Zagreb-Graz"){
            f1.push_back(node(s1,s2));
        }else{
            f2.push_back(node(s1,s2));    
        }
    }
    string ans="99:99";
    if(f1.size()==0||f2.size()==0){
        cout<<"NEMOGUCE";
        return ;
    }
    for(int i=0;i<f1.size();i++){
        auto [s1,t1]=f1[i];
        for(int j=0;j<f2.size();j++){
            // cout<<i<<" "<<j<<'\n';
            auto [s2,t2]=f2[j];
            if(t2<t1){
                s2.replace(0,2,to_string(stoi(s2.substr(0,2))+24));
                t2.replace(0,2,to_string(stoi(t2.substr(0,2))+24));
            }
            // cout<<s2<<" "<<t2<<'\n';
            if(t1<s2){
                int ex=0;
                if(s1.substr(3,2)>t2.substr(3,2)){
                    ex=1;
                }
                // cout<<s1.substr(3,2)<<" "<<t2.substr(3,2)<<'\n';
                // cout<<s1.substr(0,2)<<" "<<t2.substr(0,2)<<'\n';
                string tmp1=to_string((abs(stoi(s1.substr(3,2))-stoi(t2.substr(3,2))))),
                       tmp2=to_string((abs(stoi(s1.substr(0,2))-stoi(t2.substr(0,2)))-ex));
                if(tmp1.size()==1) tmp1='0'+tmp1;
                if(tmp2.size()==1) tmp2='0'+tmp2;
                string tmp=tmp2+":"+tmp1;
                // cout<<tmp<<'\n';
                tmp.replace(3,2,to_string(stoi(tmp.substr(3,2))+1));
                if(tmp.substr(3,2)>="60"){
                    tmp.replace(3,2,to_string(stoi(tmp.substr(3,2))-60));
                    tmp.replace(0,2,to_string(stoi(tmp.substr(0,2))+1));
                }
                ans=min(ans,tmp);
            }
        }
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}