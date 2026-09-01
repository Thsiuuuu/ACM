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
const int Sig=26,MAXN=2e5+10;//maxn至少是字符串总长度2倍
int cnt[MAXN],ord[MAXN];
ll f[MAXN];
struct SuffixAutomaton{
    struct Node{
        int len;
        int link;
        int nxt[26];
        Node():len(0),link(-1){
            memset(nxt,-1,sizeof(nxt)); 
        }
    }t[MAXN];
    int tot,last;
    void init(){
        tot=1,last=0;
        t[0]=Node();
    }
    void  insert(int c){
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
    void find(int k){
        string ans;
        int u=0;
        while(1){
            if(u&&k<=1ll){
                cout<<ans<<'\n';
                return ;
            }
            if(u)  k-=1ll;
            bool is=true;
            for(int i=0;i<26;i++){
                int v=t[u].nxt[i];
                if(v==-1) continue;
                if(k>f[v]) k-=f[v];
                else{
                    is=false;
                    ans+=('a'+i);
                    u=v;
                    break;
                }
            }
            if(is){
                cout<<"-1\n";
                return ;
            }
        }
    }
}S;
void sol() {
    S.init();
    string s;cin>>s;
    S.init();
    int q;cin>>q;
    for(char c:s){
        S.insert(c-'a');
    }
    int n=s.size();
    for(int i=0;i<=n;i++) cnt[i]=0;
    for(int i=0;i<S.tot;i++) cnt[S.t[i].len]++;
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=S.tot-1;i>=0;i--){
        int L=S.t[i].len;
        ord[--cnt[L]]=i;//从左到右len不断增加，len相同编号逐渐增加，同理从右向左长度递减，编号递减
    }
    for(int i=S.tot-1;i>0;i--){
        int u=ord[i];
        f[u]+=1ll;
        for(int x=0;x<26;x++){
            int v=S.t[u].nxt[x];
            if(S.t[u].nxt[x]==-1) continue;
            f[u]+=f[v];
        }
    }
    while(q--){
        int k;cin>>k;
        S.find(k);
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