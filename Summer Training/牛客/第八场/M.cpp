// KV Cache 
// 4000ms, 2048MB

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int _=1000005, _m=998244353, INF=0x3f3f3f3f3f3f3f3fLL; mt19937_64 rnd(98275314); int qpow(int a, int b) {int ret=1;while(b) {if(b&1) ret=ret*a%_m;b>>=1; a=a*a%_m;}return ret;}int inv(int a) {return qpow(a, _m-2);}int gcd(int a, int b) {return b==0?a:gcd(b, a%b);}int lcm(int a, int b) {return a/gcd(a, b)*b;}int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int n, m, __;
string s[_];
const int N=1e6+10;
namespace Trie{
    struct Node{
        int son[26];
        int cnt;
        int exist;//以该点结尾的字符串的数量
        int live;
        int fa;
        int step;
        void init(){
            memset(son,0,sizeof(son));
            cnt=exist=live=step=0;
            fa=-1;
        }
    }tr[N];

    priority_queue<pair<int, int>> q;
    int siz=0;

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
                tr[tot].fa=u;
            }
            if(tr[u].live) {
                tr[u].live=0;
                siz--;
            }
            u=tr[u].son[c];
            tr[u].cnt++;
        }
        tr[u].live=1;
        q.push({tr[u].cnt, u});
        siz++;
        tr[u].exist++;
    }
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
    void erase1(const string &s){
        int u=root;
        for(int i=0;i<s.size();i++){
            int c=s[i]-'a';
            int nex=tr[u].son[c];
            tr[nex].cnt--;
            if(!tr[nex].step) {
                cout<<char(c+'a')<<'\n';
                __++;
            }
            tr[nex].step++;
            if(tr[nex].cnt==0){
                tr[u].son[c]=0;
            }
            u=nex;
        }
        tr[u].exist--;
    }
    void fuck(const string &s) {
        erase1(s);
        while(siz>m) {
            auto [cnt, u]=q.top(); q.pop();
            if(!tr[u].live) continue;
            cout<<"*\n";
            tr[u].live=0;
            tr[u].step=0;
            if(tr[u].fa!=-1) {
                tr[tr[u].fa].live=1;
                q.push({tr[tr[u].fa].cnt, tr[u].fa});
            }
            siz--;
        }
    }
}
void solve() {
    cin>>n>>m;
    Trie::init();
    for(int i=1; i<=n; i++) {
        cin>>s[i];
        Trie::insert(s[i]);
    }
    for(int i=1; i<=n; i++) {
        Trie::fuck(s[i]);
    }
    cout<<__<<'\n';
} //yunayu_2026_target_M

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // int T; cin>>T; while(T--) solve();
    return 0;
} //"只要不失去你的崇高，整个世界都会向你敞开"