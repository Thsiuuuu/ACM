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
const int N=110;
VI e[N];
int p[N],dep[N],num[4],cnt[N];
set<int> a[2];
int st[N];
void dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    a[dep[u]&1].insert(e[u].size());
    for(int v:e[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
}
void dfs2(int u,int root){
    if(e[u].size()==1){
        if(st[root]==0) st[root]=(dep[u]&1)+1;
        else if(st[root]!=(dep[u]&1)+1) st[root]=-1;
    }
    if(st[root]==-1) return ;
    for(int v:e[u]) dfs2(v,root);
}
void sol() {
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        int u;cin>>u;
        e[u].push_back(i);
        p[i]=u;
    }
    dep[0]=-1;
    dfs(1,0);
    int mx=*max_element(dep+1,dep+1+n);
    if(mx==1){
        cout<<1<<endl;
        for(int i=1;i<n;i++) cout<<1<<" ";
        cout<<endl;
        int op;
        while(1){
            cin>>op;
            if(op==1) return ;
            else if(op==0){
                int x;cin>>x;
                cout<<x<<endl;
            }
        }
    }else{
        bool is=true;
        for(int v:e[1]){
            dfs2(v,v);
            if(st[v]==-1) is=false;
        } 
        if(is){
            cout<<2<<endl;
            for(int v:e[1]){
                if(st[v]==2) cnt[v]=2;
                else if(st[v]==1) cnt[v]=1;
                else cnt[v]=1;
            }
            for(int i=2;i<=n;i++){
                if(cnt[i]) continue;
                if(cnt[p[i]]==2) cnt[i]=1;
                else cnt[i]=2;
            }
            for(int i=2;i<=n;i++) cout<<cnt[i]<<" " ;
            cout<<endl;
            int op;
            while(1){
                cin>>op;
                if(op==1) return ;
                else if(op==0){
                    int sum=0;
                    for(int i=1;i<=2;i++){
                        cin>>num[i];
                        sum+=num[i];
                    }
                    if(num[1]==num[2]&&sum==2){
                        cout<<2<<endl;
                    }else if(num[1]==1){
                        cout<<1<<endl;
                    }else{
                        cout<<2<<endl;
                    }
                }
            }
        }else{
            cout<<3<<endl;
            cnt[1]=3;
            for(int i=2;i<=n;i++){
                if(cnt[p[i]]==1) cnt[i]=2;
                else if(cnt[p[i]]==2) cnt[i]=3;
                else cnt[i]=1;
                cout<<cnt[i]<<" ";
            }
            cout<<endl;
            int op;
            while(1){
                cin>>op;
                if(op==1) return ;
                else if(op==0){
                    int sum=0;
                    for(int i=1;i<=3;i++){
                        cin>>num[i];
                        sum+=num[i];
                    }
                    for(int i=1;i<=3;i++){
                        if(sum==1&&num[i]==1){
                            cout<<i<<endl;
                            break;
                        }
                        if(sum>1&&num[i]==0){
                            if(i<=2) cout<<i+1<<endl;
                            else cout<<1<<endl;
                            break;
                        }
                    }
                }
            }
        }
    }
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}