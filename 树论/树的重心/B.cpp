#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

/*

    首先要注意到这个题有一个小巧思，

    如果把两颗树连起来，那么新树的重心一定在原来两棵树重心的路径上
    然后自底向上考虑，叶节点一定是它自己为一棵树的重心
    那么这样在不断合并子树的时候，重心至少是不会下降的，和c题类似


    然后注意一个结论：对于一颗树的重心它在初始根节点或者最重的子树上
*/

int q,n;
const int N=600010;
int nxt[N],head[N],to[N],cnt=1,siz[N],f[N],ans[N],fa[N];


void add(int u,int v){
    nxt[cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt++;
}

void dfs(int x){
    ans[x]=x;
    siz[x]=1;
    int  maxn=0,t=0;
    for(int e=head[x],v;e;e=nxt[e]){
        v=to[e];
        dfs(v);
        siz[x]+=siz[v];
        if(siz[v]>maxn){
            maxn=siz[v];
            t=v;
        }
    }
    f[x]=maxn;
    if(f[x]*2<siz[x]) ans[x]=x;
    else{
        int now=ans[t];
        while(fa[now]&&max(f[now],siz[x]-siz[now])>max(f[fa[now]],siz[x]-siz[fa[now]])){
            now=fa[now];
            
        }
        ans[x]=now;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int k;
        cin>>k;
        fa[i]=k;
        add(k,i);
    }
    dfs(1);
    for(int i=1;i<=q;i++){
        int k;
        cin>>k;
        cout<<ans[k]<<"\n";
    }
    return 0;
}