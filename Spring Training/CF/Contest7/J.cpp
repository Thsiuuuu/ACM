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

vector<int> e[28],deg(28,0);

int cnt[28];
void sol() {
    int n;cin>>n;
    for(int i=0;i<n;i++){
        string a,b,d;cin>>a>>b>>d;
        char u=a[0],c=b[0],v=d[0];
        if(c=='>') swap(u,v);
        // cout<<u<<" "<<c<<" "<<v<<'\n';
        e[u-'a'].push_back(v-'a');
        deg[v-'a']++;
    }
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        // cout<<s[i]<<" ";
        cnt[s[i]-'a']++;
    }
    // cout<<('n'-'a')<<'\n';
    // cout<<cnt['n'-'0']<<'\n';
    queue<int> q;
    for(int i=0;i<26;i++){
        // cout<<i<<" "<<deg[i]<<" "<<cnt[i]<<'\n';
        if(!deg[i]){
            q.push(i);
            // cout<<i<<" ";
        }
    }
    string ans;
    while(q.size()){
        int u=q.front();
        q.pop();
        // cout<<u<<'\n';
        for(int i=0;i<cnt[u];i++) ans+=(char)('a'+u);
        for(int v:e[u]){
            if(--deg[v]==0) q.push(v);
        }
    }
    for(int i=0;i<26;i++){
        if(deg[i]){
            cout<<"IMPOSSIBLE\n";
            return ;
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}