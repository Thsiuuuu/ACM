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

const int N=2e5+10;
int pL[N],pR[N],ls[N],rs[N];
int mxL[N][20],mxR[N][20],uL[N][20],uR[N][20],HL[N],HR[N];
int a[N],dep[N],st[N][20],h[N];
void dfs1(int u,int fa){
    dep[u]=dep[fa]+1;
    st[u][0]=fa;
    for(int i=1;i<20;i++){
        st[u][i]=st[st[u][i-1]][i-1];
    }
    if(ls[u]){
        dfs1(ls[u],u);
    }
    if(rs[u]){
        dfs1(rs[u],u);
    }
    h[u]=1+max(h[ls[u]],h[rs[u]]);
    // cout<<h[u]<<"|\n";
    HL[u]=h[ls[u]];
    HR[u]=h[rs[u]];
    // cout<<HL[u]<<'\n';
}
int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=19;i>=0;i--){
        if(dep[st[u][i]]>=dep[v]) u=st[u][i];
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(st[u][i]!=st[v][i]) u=st[u][i],v=st[v][i];
    }
    return st[u][0];
}
void sol() {
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        h[i]=pL[i]=pR[i]=ls[i]=dep[i]=rs[i]=HL[i]=HR[i]=0;
        for(int j=0;j<20;j+=1){
            mxL[i][j]=mxR[i][j]=uL[i][j]=uR[i][j]=st[i][j]=0;
        }
        cin>>a[i];
    }
    stack<int> stk;
    int rt;
    for(int i=1;i<=n;i++){
        int last=0;
        while(stk.size()&&a[stk.top()]>a[i]){
            last=stk.top();
            stk.pop();
        }
        if(stk.size()){
            rs[stk.top()]=i;
        }
        if(last){
            ls[i]=last;
        }
        stk.push(i);
    }
    while(stk.size()){
        rt=stk.top();
        stk.pop();
    }
    dfs1(rt,0);
    for(int i=n;i>=1;i--){
        while(stk.size()&&a[stk.top()]>a[i]){
            stk.pop();
        }
        if(stk.size()) pL[i]=stk.top();
        stk.push(i);
    }
    while(stk.size()) stk.pop();
    for(int i=1;i<=n;i++){
        while(stk.size()&&a[stk.top()]>a[i]){
            stk.pop();
        }
        if(stk.size()) pR[i]=stk.top();
        stk.push(i);
    }
    for(int u=1;u<=n;u++){
        uR[u][0]=pR[u];
        mxR[u][0]=HL[pR[u]];
        for(int i=1;i<20;i++){
            uR[u][i]=uR[uR[u][i-1]][i-1];
            mxR[u][i]=max(mxR[u][i-1],mxR[uR[u][i-1]][i-1]-(1<<(i-1)));
        }
    }
    for(int u=n;u>=1;u--){
        uL[u][0]=pL[u];
        mxL[u][0]=HR[pL[u]];
        for(int i=1;i<20;i++){
            uL[u][i]=uL[uL[u][i-1]][i-1];
            mxL[u][i]=max(mxL[u][i-1],mxL[uL[u][i-1]][i-1]-(1<<(i-1)));
        }
    }
    while(q--){
        int l,r;cin>>l>>r;
        int u=lca(l,r);
        if(l==r){
            cout<<"1\n";
            continue;
        }
        int lk=0,rk=0;
        int ans=0;
        if(l^u){
            int cr=l;
            int ori=0;
            for(int i=19;i>=0;i--){
                if(cr==u) break;
                if(uL[cr][i]&&uL[cr][i]<u){
                    ori=max(ori,1+mxL[cr][i]-lk),
                    lk|=(1<<i),
                    cr=uL[cr][i];
                }
            }
            lk+=0;
            ans=max({ans,ori+lk,lk+2+HR[l]});
        }
        if(r^u){
            int cr=r;
            int ori=0;
            for(int i=19;i>=0;i--){
                if(cr==u) break;
                if(uR[cr][i]&&uR[cr][i]>u){
                    ori=max(ori,1+mxR[cr][i]-rk),
                    rk|=(1<<i),
                    cr=uR[cr][i];
                }
            }
            rk+=0;
            ans=max({ans,rk+ori,rk+2+HL[r]});
        }
        cout<<ans<<'\n';
    }
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