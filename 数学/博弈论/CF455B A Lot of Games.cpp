#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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
const int N=1e5+10;
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
    int f[N];

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
    void dfs1(int u){
        int cnt=0;
        for(int i=0;i<26;i++){
            int v=tr[u].son[i];
            if(v){
                dfs1(v);
                if(f[v]==false) f[u]=true;
            }
        }
    }
    void dfs2(int u){
        int cnt=0;
        for(int i=0;i<26;i++){
            int v=tr[u].son[i];
            if(v) {
                dfs2(v);
                if(f[v]==true) f[u]=false;
            }else cnt++;
        }
        if(cnt==26) f[u]=false;
    }
}
void sol() {
    int n,k;cin>>n>>k;
    Trie::init();
    for(int i=0;i<n;i++){
        string s;cin>>s;
        Trie::insert(s);
    }
    int mask=0;
    Trie::dfs1(0);
    mask|=(Trie::f[0]<<1);
    for(int i=0;i<=Trie::tot;i++){
        Trie::f[i]=true;
    }
    Trie::dfs2(0);
    mask|=(Trie::f[0]);
    if(mask<2) cout<<"Second";
    else if(mask==3){
        if(k&1) cout<<"First\n";
        else cout<<"Second\n";
    }else cout<<"First\n";
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