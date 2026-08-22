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
vector<int> e[N];
int ca[N],cb[N],siz[N],son[N];
int cnt1[N],cnt2[N],tot[N];
bool ans[N];
ll sum=0;
void add(int u,int fa,int val,int ban){
    int col1=ca[u],col2=cb[u];
    if(val==1){
        cnt1[col1]++,cnt2[col2]++;
        if(col1==col2&&col1){
            sum++;
            tot[col1]++;
        }else{
            if(col1&&cnt1[col1]>tot[col1]) sum++,tot[col1]++;
            if(col2&&cnt2[col2]>tot[col2]) sum++,tot[col2]++;
        }
        // tot[col1]=max(cnt1[col1],cnt2[col1]);
        // tot[col2]=max(cnt1[col2],cnt2[col2]);
    }else{
        cnt1[col1]--;
        cnt2[col2]--;
        if(col1==col2&&col1){
            sum--;
            tot[col1]--;
        }else{
            if(col1&&max(cnt1[col1],cnt2[col1])<tot[col1]) sum--,tot[col1]--;
            if(col2&&max(cnt1[col2],cnt2[col2])<tot[col2]) sum--,tot[col2]--;
        }

        // tot[col1]=max(cnt1[col1],cnt2[col1]);
        // tot[col2]=max(cnt1[col2],cnt2[col2]);
    }
    for(int v:e[u]){
        if(v==fa||v==ban) continue;
        add(v,u,val,ban);
    }
}
void dfs1(int u,int fa){
    siz[u]=1,son[u]=0;
    for(int v:e[u]){
        if(fa^v){
            dfs1(v,u);
            siz[u]+=siz[v];
            if(siz[v]>siz[son[u]]) son[u]=v;
        }
    }
}
void dfs2(int u,int fa,bool keep){
    for(int v:e[u]){
        if(v==fa||v==son[u]) continue;
        dfs2(v,u,false);
    }
    if(son[u]){
        dfs2(son[u],u,true);
    }
    add(u,fa,1,son[u]);
    ans[u]=(sum<=siz[u]);
    if(!keep){
        add(u,fa,-1,0);
    }
}
void sol() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ca[i];
    for(int i=1;i<=n;i++) cin>>cb[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0,1);
    sum=0;
    for(int i=1;i<=n;i++){
        cout<<ans[i];
    }
    for(int i=0;i<=n;i++){
        ans[i]=false;
        e[i].clear();
        siz[i]=son[i]=cnt1[i]=cnt2[i]=tot[i]=0;
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