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
const int Sig=26,MAXN=4e5+10;//maxn至少是字符串总长度2倍
ll cnt[MAXN],ord[MAXN],mn[MAXN],st[MAXN][21],f[MAXN],pos[MAXN>>1];
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
    void insert(int c,int i){
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
        mn[cur]=i;
    }
    void find(const string&s){
        int u=0;
        for(int i=0;i<s.size();i++){
            u=t[u].nxt[s[i]-'a'];
            pos[i]=u;
        }
    }
}S;
void sol() {
    string s;cin>>s;
    S.init();
    int n=s.size();
    for(int i=0;i<(n<<1)+3;i++) mn[i]=f[i]=1e18; 
    for(int i=0;i<s.size();i++){
        S.insert(s[i]-'a',i);
    }
    S.find(s);
    ll p,q;cin>>p>>q;
    for(int i=0;i<S.tot;i++) cnt[S.t[i].len]++;
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=S.tot-1;i>=0;i--){
        ord[--cnt[S.t[i].len]]=i;
    }
    for(int i=S.tot-1;i>0;i--){
        int u=ord[i],fa=S.t[u].link;
        mn[fa]=min(mn[fa],mn[u]);
    }
    for(int i=1;i<S.tot;i++){
        int u=ord[i];
        st[u][0]=S.t[u].link;
        for(int j=1;j<21;j++){
            st[u][j]=st[st[u][j-1]][j-1];
        }
    }
    for(int i=0;i<n;i++){
        f[i]=(i?(f[i-1]):0)+p;
        int u=pos[i];
        for(int j=20;u&&j>=0;j--){
            if(st[u][j]&&mn[st[u][j]]>i-S.t[S.t[st[u][j]].link].len-1){
                u=st[u][j];
            }
        }
        if(u&&S.t[u].link){
            u=S.t[u].link;
            int L=min(i-mn[u],1ll*S.t[u].len);
            f[i]=min(f[i],f[i-L]+q);
        }
    }
    cout<<f[n-1];
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