#include <bits/stdc++.h>
using namespace std;
/*

    首先直接遍历一遍一定会超
    0.正着不好求，可以反过来想
    1.首先如果自己都构不成二分图，一定不行
    2.其次考虑一个集团和另一个集团能否构成二分图，这里最多k条边，可以用扩展域并查集判断一下
    3.因为涉及撤销合并操作，所以说可以使用可撤销并查集，每次最多O(logn)
    所以总的时间复杂度是O(n+k*logn)

*/
using ll=long long ;
const int MAXN=5e5+10;
struct DSU{
    int siz[MAXN<<1],father[MAXN<<1],rollback[MAXN<<1][2],opsize;
    DSU (int n=0){
        for(int i=1;i<=2*n;i++){
            father[i]=i;
            siz[i]=1;
        }
        opsize=0;
    }
    int find(int i){
        while(i^father[i]) i=father[i];
        return i;
    }
    void unite(int x,int y){
        int fx=find(x),fy=find(y);
        if(siz[fx]<siz[fy]){
            swap(fx,fy);
        }
        father[fy]=fx;
        siz[fx]+=siz[fy];
        rollback[++opsize][0]=fx;
        rollback[opsize][1]=fy;
    }
    void undo(){
        int fx=rollback[opsize][0],fy=rollback[opsize--][1];
        father[fy]=fy;
        siz[fx]-=siz[fy];
    }
};

struct CrossEdge{
    int u,uteam,v,vteam;
    bool operator<(const CrossEdge x)const{
        if(x.uteam==uteam) return vteam<x.vteam;
        return uteam<x.uteam;
    }
};

int n,m,k;
int team[MAXN];
int edge[MAXN][2];

CrossEdge crossEdge[MAXN];
int cnt=0;

bool conflict[MAXN];

void filter(DSU& dsu){

    for(int i=1,u,v;i<=m;i++){
        u=edge[i][0],v=edge[i][1];
        if(team[u]<team[v]){
            crossEdge[++cnt].u=u;
            crossEdge[cnt].uteam=team[u];
            crossEdge[cnt].v=v;
            crossEdge[cnt].vteam=team[v];
        }else if(team[u]>team[v]){
            crossEdge[++cnt].u=v;
            crossEdge[cnt].uteam=team[v];
            crossEdge[cnt].v=u;
            crossEdge[cnt].vteam=team[u];
        }else{
            if(conflict[team[u]]){
                continue;
            }
            if(dsu.find(u)==dsu.find(v)){
                k--;
                conflict[team[u]]=true;
            }else{
                dsu.unite(u,v+n);
                dsu.unite(v,u+n);
            }
        }
    }
}

ll compute(DSU& dsu){
    sort(crossEdge+1,crossEdge+cnt+1);
    ll ans=(ll)k*(k-1)/2;
    int u,uteam,v,vteam,unionCnt;
    for(int l=1,r=1;l<=cnt;l=++r){
        uteam=crossEdge[l].uteam,vteam=crossEdge[l].vteam;
        while(r+1<=cnt&&crossEdge[r+1].uteam==uteam&&crossEdge[r+1].vteam==vteam){
            r++;
        }
        if(conflict[uteam]||conflict[vteam]){
            continue;
        }
        unionCnt=0;
        for(int i=l;i<=r;i++){
            u=crossEdge[i].u;
            v=crossEdge[i].v;
            if(dsu.find(u)==dsu.find(v)){
                ans--;
                break;
            }else{
                dsu.unite(u,v+n);
                dsu.unite(v,u+n);
                unionCnt+=2;
            }
        }
        for(int i=1;i<=unionCnt;i++){
            dsu.undo();
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>team[i];
    for(int i=1;i<=m;i++) cin>>edge[i][0]>>edge[i][1];
    DSU dsu(n);
    filter(dsu);
    cout<<compute(dsu)<<'\n';
    return 0;
}