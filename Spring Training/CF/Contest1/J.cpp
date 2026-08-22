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

const int N=2e5+10;
vector<int> e[N];

void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
    int ans=0;
    for(int i=1;i<=n;i++){
        if(e[i].size()<=1) continue;
        else if(e[i].size()>=4){
            ans++;
            continue;
        }
        vector<pii> tmp;
        for(int u:e[i]){
            pii res={e[u].size(),u};
            for(int v:e[i]){
                auto it=lower_bound(e[u].begin(),e[u].end(),v);
                if((v^u)&&it!=e[u].end()&&*it==v){
                    res.first--;
                }
            }
            tmp.push_back(res);
        }
        sort(tmp.begin(),tmp.end(),[&](const pii&a,const pii&b)->bool{
            return a.first>b.first;
        });
        if(tmp[1].first>=3||(tmp.size()==3&&tmp[1].first>=2)) ans++;
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}