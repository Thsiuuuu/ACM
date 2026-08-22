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

string ti="<censored>";

void sol() {
    int n,k;
    cin>>n;
    vector<string> st;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        st.push_back(s);
    }
    cin>>k;
    cin.ignore();
    int tot=0;
    string line,token;
    getline(cin,line);
    vector<string> tokens;
    stringstream iss(line);
    while(iss>>token){
        tokens.push_back(token);
    }
    for(int i=0;i<tokens.size();i++){
        for(int j=0;j<tokens[i].size();j++){
            for(int k=0;k<st.size();k++){
                if(j+st[k].size()-1>=tokens[i].size()) continue;
                else{
                    if()
                }
            }
        }

    }
    if(tot<k){
        for(int i=0;i<tokens.size();i++){
            if(i) cout<<" ";
            cout<<tokens[i];
        }
    }else{
        cout<<tot<<'\n';
        cout<<"He Xie Ni Quan Jia!";
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