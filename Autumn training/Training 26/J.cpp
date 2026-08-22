#include <bits/stdc++.h>
using namespace std;

struct DSU{
    int n;
    vector<int> fa,siz;

    DSU(int n_=0){
        fa.resize(n+1);
        for(int i=1;i<=n;i++){
            fa[i]=i;
            siz[i]=1;
        }
    }

    int find(int x){
        return (fa[x]==x)?x:(fa[x]=find(fa[x]));
    }
    void unite(int x,int y){
        int fx=find(x),fy=find(y);

        if(siz[fx]>siz[fy]){
            swap(fx,fy);
        }
        if(fx^fy){
            fa[fx]=fy;
            siz[fy]+=siz[fx];
        }
    }
};

void sol(){
    

    vector<map<string,int>> mp(2);
    int n;
    cin>>n;
    vector<pair<string,string>> pss;
    for(int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        pss.push_back({s1,s2});
        mp[0][s1]++,mp[1][s2]++;
    }

    mp[0][pss[0].first]--,mp[1][pss[0].second]--;
    for(int i=1;i<n;i++){
        auto [s1,s2]=pss[i];
        auto [sf1,sf2]=pss[i-1];


        // cout<<i<<" "<<mp[0][sf1]<<" "<<mp[1][sf2]<<'\n';

        if(s1!=sf1&&s2!=sf2){
            if(mp[0][sf1]==0&&mp[1][sf2]==0){
                mp[0][s1]--,mp[1][s2]--;
            }else{
                cout<<"No\n";
                return ;
            }
        }else{
            mp[0][s1]--,mp[1][s2]--;
        }
    }
    cout<<"Yes\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}