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
const int N=1e6+10;
namespace Trie{
    struct Node{
        int son[12];
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

    void insert(const VI&s){
        int u=root;
        for(int i=1;i<s.size();i++){
            int c=s[i];
            if(!tr[u].son[c]){
                tr[u].son[c]=MakeNode();
            }
            u=tr[u].son[c];
            tr[u].cnt++;
        }
        tr[u].exist++;
    }
    int bfs(const VI&s){
        int u=root;
        int ans=0;
        for(int i=0;i<s.size();i++){
            int c=s[i];
            if(!tr[u].son[c]) return ans;
            ans++;
            u=tr[u].son[c];
        }
        return ans;
    }
}
void sol() {
    Trie::init();
    int n,m;cin>>n>>m;
    VII a(n,VI(m,0));
    VI idx(m+1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
        for(int j=0;j<m;j++){
            idx[a[i][j]]=j+1;
        }
        Trie::insert(idx);
    }
    for(int i=0;i<n;i++){
        cout<<Trie::bfs(a[i])<<" ";
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}