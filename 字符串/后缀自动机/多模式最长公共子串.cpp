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
const int Sig=26,MAXN=2e6+30;//maxn至少是字符串总长度2倍
int cnt[MAXN],ord[MAXN],f[MAXN],ans[MAXN];
vector<string> all;
struct SuffixAutomaton{
    struct Node{
        int len;
        int link;
        int nxt[Sig];
        Node():len(0),link(-1){
            memset(nxt,-1,sizeof(nxt));
        }
    }t[MAXN];
    int tot,last;
    void init(){
        tot=1,last=0;
        t[0]=Node();
    }
    void insert(int c){
        int cur=tot++;
        t[cur]=Node();
        t[cur].len=t[last].len+1;
        int p=last;
        while(p!=-1&&t[p].nxt[c]==-1){
            t[p].nxt[c]=cur;
            p=t[p].link;
        }
        if(p==-1){
            t[cur].link=0;
        }else{
            int q=t[p].nxt[c];
            if(t[p].len+1==t[q].len){t[cur].link=q;}
            else{
                int clone=tot++;
                t[clone]=t[q];
                t[clone].len=t[p].len+1;//接着原来那个点，然后把>x+1的点腾出来
                while(p!=-1&&t[p].nxt[c]==q){
                    t[p].nxt[c]=clone;
                    p=t[p].link;
                }//链上沿着s_i重连边
                t[q].link=t[cur].link=clone;//两个状态都连到自己的link超集状态上面
            }
        }
        last=cur;
    }
}S;
void sol() {
    int n;cin>>n;
    S.init();
    for(int i=0;i<n;i++){
        string s;cin>>s;
        all.push_back(s);
        if(i&&all[0].size()>all.back().size()) swap(all[0],all.back());
    }
    int len=all[0].size();
    for(char ch:all[0]){
        S.insert(ch-'a');
    }
    for(int i=0;i<MAXN; i++) f[i]=0; 
    for(int i=0;i<S.tot;i++) cnt[S.t[i].len]++;
    for(int i=1;i<=len;i++) cnt[i]+=cnt[i-1];
    for(int i=S.tot-1;i>=0;i--){
        ord[--cnt[S.t[i].len]]=i;
    }   
    for(int i=S.tot-1;i>=0;i--){
        int u=ord[i];ans[u]=S.t[u].len;
    }
    for(int i=1;i<all.size();i++){
        int u=0,len=0;
        for(int i=0;i<S.tot;i++) f[i]=0;
        for(char ch:all[i]){
            int c=ch-'a';
            while(u&&S.t[u].nxt[c]==-1) u=S.t[u].link,len=S.t[u].len;
            if(S.t[u].nxt[c]!=-1){
                len=len+1,u=S.t[u].nxt[c];
                f[u]=max(f[u],len);
            }
        }
        for(int i=S.tot-1;i>0;i--){
            int u=ord[i];
            ans[u]=min(ans[u],f[u]);
            f[S.t[u].link]=max(f[S.t[u].link],min(f[u],S.t[S.t[u].link].len));
        }
    }
    cout<<*max_element(ans,ans+S.tot);
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