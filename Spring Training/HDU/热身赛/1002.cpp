#include <bits/stdc++.h>
using namespace std;
/*

    对每一个点维护一个并查集
    然后map存并查集的头部

    搞两个map存一下映射吧...

*/
#define ll long long
#define double long double 
#define pii pair<ll,ll>

struct DSU{
    int n;
    //第一个是值到并查集头，第二个是并查集头到值
    map<int,int> ValToHead,HeadToVal;
    vector<int> siz,fa,a;
    // DSU(int n_):n(n_),siz(n+1,1),fa(n+1),a(n+1){
    //     for(int i=1;i<=n;i++) fa[i]=i;
    // }

    DSU(int n_):n(n_),siz(1,1),fa(1,1),a(1,1){

    }

    void add(int i){
        siz.push_back(1),fa.push_back(i);
        auto it=ValToHead.find(a[i]);
        if(it==ValToHead.end()){
            ValToHead[a[i]]=fa[i];
            HeadToVal[fa[i]]=a[i];
        }else{
            siz[it->second]++;
            fa[i]=it->second;
        }
    }
    
    int find(int x){
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }
    void change(int x,int y){
        // if(x==y) return ;
        auto check=ValToHead.find(x);
        int fx;
        if(check==ValToHead.end()) return ;
        else fx=check->second;
        auto it=ValToHead.find(y);
        if(it==ValToHead.end()){
            ValToHead[y]=fx;
            HeadToVal[fx]=y;
            ValToHead.erase(x);
        }else{
            int fy=it->second;
            siz[fy]+=siz[fx];
            fa[fx]=fy;
            ValToHead.erase(x);
            HeadToVal.erase(fx);
        }
    }

    void clear(int x){
        auto it=ValToHead.find(x);
        if(it==ValToHead.end()) return ;
        else{
            int fx=it->second;
            HeadToVal.erase(fx);    
            ValToHead.erase(x);
        }
    }

};


void sol() {
    int n,m;
    cin>>n;
    DSU dsu(n);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        dsu.a.push_back(x);
        dsu.add(i);
    }

    // for(int i=1;i<=n;i++){
    //     int fx=dsu.find(i);
    //     cout<<dsu.HeadToVal[fx]<<" ";
    // }


    cin>>m;
    int sum=n;
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            dsu.change(x,y);
        }else if(op==2){
            int x;cin>>x;
            sum++;
            dsu.a.push_back(x);
            dsu.add(sum);
        }else{
            int x;cin>>x;
            dsu.clear(x);
        }
        // for(int i=1;i<=sum;i++){
        //     int fi=dsu.find(i);
        //     auto it=dsu.HeadToVal.find(fi);
        //     if(it!=dsu.HeadToVal.end()) cout<<it->second<<" ";
        // }
        // cout<<'\n';
    }
    for(int i=1;i<=sum;i++){
        int fi=dsu.find(i);
        auto it=dsu.HeadToVal.find(fi);
        if(it!=dsu.HeadToVal.end()) cout<<it->second<<" ";
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}