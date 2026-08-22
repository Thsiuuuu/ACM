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
const int N=2e5+10;
namespace Trie{
    struct Node{
        int son[26];
        int cnt;
        int exist;//以该点结尾的字符串的数量
        void init(){
            memset(son,0,sizeof(son));
            cnt=exist=0;
        }
    }tr[N];

    int tot,root;//tot节点总数,root=0
    void init(){
        tot=root=0;
        tr[0].init();
    }

    int MakeNode(){
        tr[++tot].init();
        return tot;
    }

    void insert(const string&s){
        int u=root;
        for(int i=0;i<s.size();i++){
            int c=s[i]-'a';
            if(!tr[u].son[c]){
                tr[u].son[c]=MakeNode();
            }
            u=tr[u].son[c];
            tr[u].cnt++;
        }
        tr[u].exist++;
    }
    int query(const string&s){
        int u=root;
        for(int i=0;i<s.size();i++){
            int c=s[i]-'a';
            if(!tr[u].son[c]) return 0;
            u=tr[u].son[c];
        }
        return tr[u].exist;
    }//查询已经插入的字符串次数
    void erase(const string &s){
        int u=root;
        for(int i=0;i<s.size();i++){
            int c=s[i]-'a';
            int nex=tr[u].son[c];
            tr[nex].cnt--;
            if(tr[nex].cnt==0){
                tr[u].son[c]=0;
            }
            u=nex;
        }
        tr[u].exist--;
    }
    void dfs(ll &ans,int u){
        if(u){
            ll num=tr[u].cnt;
            ans+=(num>>1)*((num+1)>>1);
        }
        for(int i=0;i<26;i++){
            if(tr[u].son[i]){
                dfs(ans,tr[u].son[i]);
            }
        }
    }
}
void sol() {
    int n;
    cin>>n;
    Trie::init();
    for(int i=0;i<2*n;i++){
        string s;
        cin>>s;
        Trie::insert(s);
    }
    ll ans=0;
    Trie::dfs(ans,0);
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