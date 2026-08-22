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
// const int N=1e5+10;
void sol() {
    int n;cin>>n;
    VII e(n+1);
    vector<ll> siz(n+1,0),w(n+1,0);
    vector<bool> is(n+1,true);
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        if(l) e[i].push_back(l),e[l].push_back(i);
        if(r) e[i].push_back(r),e[r].push_back(i);
    }
    // cout<<"hel\n";
    auto dfs1=[&](auto &&self,int u,int fa)->int{
        siz[u]=1;
        for(int v:e[u]){
            if(v!=fa&&is[v]){
                self(self,v,u);
                siz[u]+=siz[v];
            }
        }
        return siz[u];
    };
    auto dfs2=[&](auto&&self,int u,int tot,int &fin,int fa)->void{
        w[u]=0;
        for(int v:e[u]){
            if(is[v]&&v!=fa){
                self(self,v,tot,fin,u);
                w[u]=max(w[u],siz[v]);
            }
        }
        w[u]=max(w[u],tot-siz[u]);
        if(w[u]<=tot/2){
            fin=u;
        }
        // cout<<"hel\n";
    };
    auto query=[&](int x,int y)->int{
        cout<<"? "<<x<<" "<<y<<'\n';
        cout.flush();
        int t;cin>>t;
        return t;
    };
    auto out=[&](int res)->void{
        cout<<"! "<<res<<'\n';
        cout.flush();   
    };
    auto check=[&](int x,int obj,int tot)->int{
        if(siz[x]>siz[obj]) return tot-siz[obj]+1;
        return siz[x];
    };
    int cu=1,msc=-1;
    int tot;
    while(1){
        tot=dfs1(dfs1,cu,0);
        // cout<<tot<<'\n';
        dfs2(dfs2,cu,tot,msc,0);
        // cout<<"hel\n";
        int num=0;
        // cout<<msc<<'\n';
        for(int v:e[msc]){
            if(is[v]){
                num++;
            }
        }

        // cout<<num<<'\n';
        if(num==0){
            cout<<"! "<<msc<<'\n';
            cout.flush();
            return ;
        }else if(num==1){
            int ans;
            for(int v:e[msc]){
                if(is[v]){
                    ans=query(msc,v);
                    if(ans==0){
                        out(msc);
                    }else if(ans==2){
                        out(v);
                    }
                    return ;
                }
            }
        }else if(num==2){
            int rem=0;
            array<int,2> ch;
            for(int v:e[msc]){
                if(is[v]){
                    ch[rem++]=v;
                }
            }
            int ans=query(ch[0],ch[1]);
            if(ans==0){
                cu=ch[0];
            }else if(ans==1){
                out(msc);
                return ;
            }else if(ans==2){
                cu=ch[1];
            }
            is[msc]=false;
        }else{
            int rem=0;
            array<int,3> ch;
            for(int v:e[msc]){
                if(is[v]){
                    ch[rem++]=v;
                }
                // cout<<v<<" ";
            }
            // cout<<'\n';
            // cout<<w[ch[0]]<<" "<<w[ch[1]]<<'\n';
            sort(ch.begin(),ch.end(),[&](int x,int y)->bool{
                return check(x,msc,tot)>check(y,msc,tot);
            });
            int ans=query(ch[0],ch[1]);
            is[msc]=false;
            if(ans==0){
                cu=ch[0];
            }else if(ans==1){
                cu=ch[2];
                is[msc]=true;
                is[ch[0]]=is[ch[1]]=false;
            }else if(ans==2){
                cu=ch[1];
            }
        }
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