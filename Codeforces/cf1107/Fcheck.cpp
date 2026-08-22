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
#define VI  vector<int>
#define VII vector<VI>
#define VL  vector<ll>
#define VLL vector<VL>

int up=12;
map<string,int> sg;

bool ck(const string&s,ll mask){
    ll pre=0;
    ll ans=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if((mask>>i)&1){
            if(s[i]=='1') pre++;
            else ans+=pre;
        }
    }
    return ans&1;
}

ll dfs(const string&s){
    if(sg.count(s)) return sg[s];
    int n=s.size();
    set<int> st;
    for(int x=0;x<(1<<n);x++){
        if(ck(s,x)){
            string t;
            for(int i=0;i<n;i++){
                if(!((x>>i)&1)) t+=s[i];
            }
            st.insert(dfs(t));
        }
    }
    int g=0;
    while(st.count(g)) g++;
    return sg[s]=g;
}
void sol() {
    for(int x=0;x<(1<<up);x++){
        string s;
        for(int i=up-1;i>=0;i--){
            s+='0'+((x>>i)&1);
        }
        if(dfs(s)==0) cout<<s<<'\n';
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