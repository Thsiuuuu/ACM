#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 
#define i128 __int128_t
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long

int dir[5]={-1,0,1,0,-1};

struct node{
    int a,b,c,d;
    bool operator<(const node&other)const{
        if(a==other.a){
            if(b==other.b){
                if(c==other.c){
                    return d<other.d;
                }
                return c<other.c;
            }
            return b<other.b;
        }
        return a<other.a;
    }
};

void sol() {
    int r,c;
    cin>>r>>c;
    vector<vector<char>> a(r+1,vector<char>(c+1,'0')),b;
    b=a;
    queue<pair<node,int>> Q;
    pii s1,s2,d;
    map<node,int> mp;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
            if(a[i][j]=='S') s1={i,j};
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>b[i][j];
            if(b[i][j]=='S') s2={i,j};
            else if(b[i][j]=='D') d={i,j};
        }
    }
    mp[{s1.first,s1.second,s2.first,s2.second}]=1;
    Q.push(make_pair(node{s1.first,s1.second,s2.first,s2.second},0));
    while(Q.size()){
        auto [tmp,dis]=Q.front();
        auto [a1,b1,a2,b2]=tmp;
        if(d==make_pair(a2,b2)){
            cout<<dis<<'\n';
            return ;
        }
        if(dis>=20000){
            cout<<"-1\n";
            return ;
        }
        Q.pop();
        // if(mp.find({a1,b1,a2,b2})!=mp.end()) continue;
        for(int i=0;i<4;i++){
            int fa1=a1+dir[i],fb1=b1+dir[i+1],fa2=a2+dir[i],fb2=b2+dir[i+1];
            if(fa1<=0||fb1<=0||fa1>r||fb1>c||a[fa1][fb1]=='X') continue;
            if(fa2<=0||fa2>r) fa2=a2;
            if(fb2<=0||fb2>c) fb2=b2;
            if(b[fa2][fb2]=='X') fa2=a2,fb2=b2;
            if(mp.find({fa1,fb1,fa2,fb2})!=mp.end()) continue;
            Q.push(make_pair(node{fa1,fb1,fa2,fb2},dis+1));
            mp[{fa1,fb1,fa2,fb2}]=1;
        }
    }
    cout<<"-1\n";
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