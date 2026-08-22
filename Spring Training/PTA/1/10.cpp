#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

    4 8
3 4 1 8
4 7 1 8 4
5 6 5 1 2 3
4 3 2 4 8
*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  

struct node{
    vector<string> st;
    string s;
    bool operator<(const node&other)const{
        return s<other.s;
    }
};


void sol() {
    int n;cin>>n;
    cin.ignore();
    vector<node> dic(n);
    for(int i=0;i<n;i++){
        string token,line;
        getline(cin,line);
        stringstream iss(line);

        
        while(iss>>token){
            dic[i].st.push_back(token);
        }

        dic[i].s=line;
        // for(int i=0;i<line.size();i++){
        //     if(line[i]==' '){
        //         int j=i;
        //         while(j<line.size()&&line[j]==' '){
        //             j++;
        //         }
        //         dic[i].len.push_back(j-i+1);
        //         i=j-1;
        //     }
        // }
    }  
    sort(dic.begin(),dic.end(),[&](const node&k1,const node&k2)->bool{
        return k1.st.size()<k2.st.size();
    });
    vector<int> check(52,0);
    for(int i=0;i<n;i++){
        int j=i;
        check[dic[i].st.size()]=i;
        while(j<n&&dic[j].st.size()==dic[i].st.size()){
            j++;
        }    
        i=j-1;
    }
    int m;cin>>m;
    cin.ignore();
    // cout<<"hel\n";
    while(m--){
        vector<string> tokens;
        string token,line;
        getline(cin,line);
        stringstream iss(line);
        while(iss>>token){
            tokens.push_back(token);
        }
        vector<node> res; 
        for(int i=check[tokens.size()];i<n;i++){
            if(dic[i].st.size()!=tokens.size()) continue;
            else{
                bool f=true;
                for(int j=0;j<tokens.size();j++){
                    if(tokens[j][0]!=dic[i].st[j][0]){
                        f=false;
                        break;
                    }
                }
                if(f){
                    res.push_back(dic[i]);
                }
            }
        }
        // cout<<"hel\n";

        if(res.size()==0){
            cout<<line;
            cout<<'\n';
        }
        else{
            sort(res.begin(),res.end());
            for(int i=0;i<res.size();i++){
                if(i) cout<<"|";
                cout<<res[i].s;
            }
            cout<<'\n';
        }

        // sort(res.begin(),res.end());
        // for(int i=0;i<res.size();i++){
        //     for(int a=0,b=0;a<res[i].st.size();a++,b++){
        //         cout<<res[i].st[a];
        //         if(b<res[i].len.size()){
        //             for(int k=0;k<res[i].len[b];k++) cout<<" ";
        //         }
        //     }
        //     cout<<"|";
        // }
        // cout<<'\n';
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