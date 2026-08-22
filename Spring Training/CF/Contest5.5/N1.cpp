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
#define pss pair<string,string>
const int del=1440;

void sol() {
    int n;cin>>n;
    vector<pss> a1,a2;
    for(int i=0;i<n;i++){
        string s,s1,s2,tim;cin>>s>>tim;
        for(int i=0;i<tim.size();i++){
            if(tim[i]=='-'){
                if(i<5) s1='0'+tim.substr(0,4);
                else s1=tim.substr(0,5);
                if(tim.size()-i-2<5) s2='0'+tim.substr(i+2,4);
                else s2=tim.substr(i+2,5);
                break;
            }
        }        
        if(s=="Zagreb-Graz") a1.push_back(make_pair(s1,s2));
        else a2.push_back(make_pair(s1,s2));
    }
    if(a1.size()==0||a2.size()==0){
        cout<<"NEMOGUCE\n";
        return ;
    }
    auto cal=[&](const string&s)->int{
        return stol(s.substr(0,2))*60+stol(s.substr(3,2));
    }
    ll ans=1145141919810;
    for(int i=0;i<a1.size();i++){
        auto [s1,s2]=a1[i];
        ll tmp1,tmp2,tmp3;
        tmp1=(s1<s2)?(cal(s2)-cal(s1)):(del+cal(s2)-cal(s1));
        for(int j=0;j<a2.size();j++){
            auto [t1,t2]=a2[j];
            bool f=false;
            
        }
    }
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