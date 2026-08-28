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
const int Sig=26,MAXN=4e5+10,N=MAXN;//maxn至少是字符串总长度2倍
VI e[N];
int pos[N],in[N],out[N],nw,st[N][21],cnt[N],ord[N];
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
    }
    void find(const string&s){
        int u=0;
        for(int i=1;i<s.size();i++){
            u=t[u].nxt[s[i]-'a'];
            pos[i]=u;
        }
    }
}S;
struct Seg{
    int lc,rc,sum;
}tr[N*21];
int root[N],tot;
int update(int last,int l,int r,int p){
    int cur=++tot;
    tr[cur]=tr[last];
    tr[cur].sum++;
    if(l==r) return cur;
    int mid=(l+r)>>1;
    if(p<=mid){
        tr[cur].lc=update(tr[last].lc,l,mid,p);
    }else{
        tr[cur].rc=update(tr[last].rc,mid+1,r,p);
    }
    return cur;
}
int query(int u,int v,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr) return tr[u].sum-tr[v].sum;
    int mid=(l+r)>>1;
    int ans=0;
    if(ql<=mid) ans+=query(tr[u].lc,tr[v].lc,l,mid,ql,qr);
    if(qr>mid) ans+=query(tr[u].rc,tr[v].rc,mid+1,r,ql,qr);
    return ans;
}
void dfs(int u){
    nw++;
    in[u]=nw;
    for(int v:e[u]){
        dfs(v);
    }
    out[u]=nw;
}
void sol() {
    string s;cin>>s;
    S.init();
    int n=s.size();
    s=' '+s;
    for(int i=1;i<=n;i++) S.insert(s[i]-'a',i);
    for(int i=0;i<S.tot;i++) cnt[S.t[i].len]++;
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=S.tot-1;i>=0;i--){
        ord[--cnt[S.t[i].len]]=i;
    }
    for(int i=S.tot-1;i>0;i--){
        int u=ord[i],fa=S.t[u].link;
    }
    for(int i=1;i<S.tot;i++){
        int u=ord[i];
        st[u][0]=S.t[u].link;
        for(int j=1;j<21;j++){
            st[u][j]=st[st[u][j-1]][j-1];
        }
    }
    S.find(s);
    for(int i=1;i<S.tot;i++) e[S.t[i].link].push_back(i);
    dfs(0);
    for(int i=1;i<=n;i++){
        root[i]=update(root[i-1],1,S.tot,in[pos[i]]);
    }
    int q;cin>>q;
    while(q--){
        int l,r,a,b;cin>>l>>r>>a>>b;
        if(a+(r-l+1)-1>b){
            cout<<"0\n";
            continue;
        }
        int u=pos[r];
        for(int i=20;i>=0;i--){
            if(S.t[st[u][i]].len>=r-l+1) u=st[u][i];
        }
        cout<<query(root[b],root[a+r-l-1],1,S.tot,in[u],out[u])<<'\n';
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