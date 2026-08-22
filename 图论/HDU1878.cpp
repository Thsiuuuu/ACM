#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
/*
    没有判断图的连通性
*/

struct DSU{
    vector<int> fa,siz;
    DSU(int i):fa(i),siz(i,1){
        iota(fa.begin(),fa.end(),0);
    }
    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    void unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return ;
        if(siz[x]<siz[y]) swap(x,y);
        fa[y]=x;
        siz[x]+=siz[y];
    }
};

int main(){
    int n,m;
    while(cin>>n){
        if(!n){
            return 0;
        }
        DSU dsu(n+1);
        cin>>m;
        vector<int> deg(n+1);
        while(m--){
            int a,b;
            cin>>a>>b;
            dsu.unite(a,b);
            deg[a]++;
            deg[b]++;
        }
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(deg[i]&1){
                flag=false;
                break;
            }
        }
        if(dsu.siz[1]<n){
            flag=false;
        }
        if(flag){
            cout<<"1\n";
        }
        else cout<<"0\n";
    }
    return 0;
}