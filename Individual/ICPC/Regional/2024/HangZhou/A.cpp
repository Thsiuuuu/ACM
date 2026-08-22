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
int fa[26],siz[26];
int find(int x){
    return x==fa[x]?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx^fy){
        if(siz[fx]<siz[fy]) swap(fx,fy);
        siz[fx]+=siz[fy];
        fa[fy]=fx;
    }
}
int z(char c){
    return c-'a';
}
void sol() {
    string s1,s2,s3;cin>>s1>>s2>>s3;
    if(s1.size()!=s2.size()){
        cout<<"NO\n";
        return ;
    }
    for(int i=0;i<26;i++) fa[i]=i,siz[i]=1;
    for(int i=0;i<s1.size();i++){
        int x=z(s1[i]),y=z(s2[i]);
        if(find(x)^find(y)){
            merge(x,y);
        }
    }
    if(s2.size()!=s3.size()){
        cout<<"YES\n";
        return ;
    }
    // for(int i=0;i<26;i++){
    //     cout<<(char)('a'+i)<<" "<<fa[i]<<'\n';
    // }
    for(int i=0;i<s3.size();i++){
        int x=z(s2[i]),y=z(s3[i]);
        if(find(x)^find(y)){
            cout<<"YES\n";
            return ;
        }
    }
    cout<<"NO\n";
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