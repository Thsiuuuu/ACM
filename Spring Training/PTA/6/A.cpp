#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long 

string cal(vector<int>&a){
    string s;
    for(int i=0;i<a.size();i++){
        if(a[i]<10) s.push_back('0'); 
        s.insert(s.size(),to_string(a[i]));
        s.push_back('|');
    }
    return s;
}

vector<int> decode(string s){
    vector<int> ans;
    for(int i=2;i<=s.size();i+=3){
        // cout<<stoi(s.substr(i-2,2))<<" ";
        ans.push_back(stoi(s.substr(i-2,2)));
    }
    return ans;
}


void sol(){
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    string s=cal(a);
    
    // cout<<s<<'\n';
    while(m--){
        int op;
        cin>>op;
        // cout<<s<<'\n';
        if(op==1){
            int l1,l2;cin>>l1;
            vector<int> b,c;
            for(int i=0;i<l1;i++){
                int x;cin>>x;
                b.push_back(x);
            }
            cin>>l2;
            for(int i=0;i<l2;i++){
                int x;cin>>x;
                c.push_back(x);
            }
            string cur=cal(b),nxt=cal(c);
            if(s.find(cur)!=string::npos){
                int idx=s.find(cur);
                s.replace(idx,3*l1,nxt);
            }
            // cout<<s<<'\n';
            a=decode(s);
            // cout<<a.size()<<'\n';
            // for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
            // cout<<'\n';
        }else if(op==2){
            string ori;
            // cout<<s<<'\n';
            // for(int i=0;i<a.size();i++){
            //     cout<<a[i]<<" ";
            // }
            // cout<<'\n';
            ori.insert(ori.size(),s.substr(0,3));
            for(int i=1;i<a.size();i++){
                if((a[i]+a[i-1])%2==0){
                    string tmp=to_string((a[i]+a[i-1])/2);
                    // cout<<i<<" "<<tmp<<'\n';
                    if(tmp.size()==1) tmp='0'+tmp;
                    tmp=tmp+'|';
                    // cout<<tmp<<'\n';
                    ori.insert(ori.size(),tmp);
                }
                // cout<<i<<" "<<s.substr(3*i-1,3)<<'\n';
                ori.insert(ori.size(),s.substr(3*i,3));
                // cout<<a[i]<<'\n';
                // cout<<ori<<'\n';
            }
            s=ori;
            // cout<<s<<'\n';
            a=decode(s);
            // for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
        }else{
            int l,r;
            cin>>l>>r;
            reverse(a.begin()+l-1,a.begin()+r);
            s=cal(a);
        }
        // cout<<s<<'\n';
        // for(int i=0;i<a.size();i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<'\n';
    }
    for(int i=0;i<a.size();i++){
        if(i) cout<<" ";
        cout<<a[i];
    }
}

signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}