#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define i128 __int128_t


struct node{
    string name,id;
    string tim;
    int idx;
    node(string name,string id,string tim,int idx):name(name),id(id),tim(tim),idx(idx){}
    bool operator<(const node&other)const{
        if(tim==other.tim){
            return idx<other.idx;
        }
        return tim<other.tim;
    }
};

struct pepl{
    string name,id;
    int idx;
    pepl(string name,string id,int idx):name(name),id(id),idx(idx){}
    bool operator<(const pepl&other)const{
        return idx<other.idx;
    }
};

void sol(){
    int d,p;
    cin>>d>>p;
    map<string,int> mp;
    int cnt=0;
    vector<pepl> res;
    for(int day=1;day<=d;day++){
        int t,s;
        cin>>t>>s;
        vector<node> tmp;
        for(int i=0;i<t;i++){
            string name,id,tim;
            int st;
            cnt++;
            cin>>name>>id>>st>>tim;
            if(id.size()!=18||name.size()>10){
                continue;
            }
            bool f=true;
            for(int i=0;i<18;i++){
                if(!isdigit(id[i])){
                    f=false;
                    break;
                }
            }
            if(!f) continue;
            if(st==1){
                res.push_back(pepl(name,id,cnt));
            }
            tmp.push_back(node(name,id,tim,cnt));
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0,tot=0;i<tmp.size()&&tot<s;i++){
            auto [name,id,tim,st]=tmp[i];
            auto it=mp.find(id);
            if(it==mp.end()||it->second+p+1<=day){
                tot++;
                mp[id]=day;
                cout<<name<<" "<<id<<'\n';
            }
        }
    }
    sort(res.begin(),res.end());
    map<pair<string,string>,int> Bmp;
    for(int i=0;i<res.size();i++){
        if(Bmp.find(make_pair(res[i].name,res[i].id))!=Bmp.end()) continue;
        cout<<res[i].name<<" "<<res[i].id<<'\n';
        Bmp[make_pair(res[i].name,res[i].id)]=1;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}