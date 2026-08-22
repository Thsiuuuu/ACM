#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define double long double
#define i128 __int128_t
#define ull unsigned long long  
#define vii vector<vector<int>> 
#define vll vector<vector<ll>>

const int N=2e6+500000;
const double eps=1e-9;

ll tree[N];
int lim;

void debug(){
    cout<<"hel\n";
}

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a;
        b>>=1,a=a*a;
    }
    return res;
}

int lowbit(int x){
    return x&(-x);
}

void add(int i,int v){
    while(i<=lim){
        tree[i]+=v;
        i+=lowbit(i);
    }
}
ll sum(int i){
    ll ans=0;
    while(i>0){
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

ll RegionSum(ll l,ll r){
    return sum(r)-sum(l-1);
}

struct C{
    ll x,y;
    ll r;
};

struct node{
    ll xa,ya;
    ll xb,yb;
};

struct event{

    /*
    
        写史了啊...像是史...就是史...
        type=0,区间查 这个也不要
        type=1,左查
        type=-1,右查
    
    */

    int id;
    int type;
    ll x;
    ll down,up;
    bool operator<(const event&other)const{
        return x<other.x;
    }
};

void sol() {

    int n,m;
    cin>>n>>m;
    vector<vector<C>> all(31);  
    vector<node> query(m+1);
    vector<ll> aft,ans(m+1,0);
    for(int i=1;i<=n;i++){
        ll x,y,r;
        cin>>x>>y>>r;
        all[r].push_back({x,y,r});
        aft.push_back(y);
    }

    for(int i=1;i<=30;i++){
        sort(all[i].begin(),all[i].end(),[&](const C&a,const C&b)->bool{
            return a.x<b.x;
        });
    }

    for(int i=1;i<=m;i++){
        cin>>query[i].xa>>query[i].ya>>query[i].xb>>query[i].yb;
        for(int R=0;R<=30;R++){
            aft.push_back(query[i].ya-R);
            aft.push_back(query[i].yb+R);
        }
    }

    // map<ll,ll> mp;
    sort(aft.begin(),aft.end());
    aft.erase(unique(aft.begin(),aft.end()),aft.end());
    lim=aft.size()+1;
    // for(int i=0;i<aft.size();i++){
    //     mp[aft[i]]=i+1;
    // }
    
    for(int R=1;R<=30;R++){
        vector<event> Q;
        for(int i=0;i<all[R].size();i++) all[R][i].y=lower_bound(aft.begin(),aft.end(),all[R][i].y)-aft.begin()+1;
        for(int i=1;i<=m;i++){
            auto& [xa,ya,xb,yb]=query[i];
            for(int k=0;k<=R;k++){
                ll ydb=lower_bound(aft.begin(),aft.end(),yb+k)-aft.begin()+1,
                   yda=lower_bound(aft.begin(),aft.end(),ya-k)-aft.begin()+1;
                ll lux=xa-(ll)(sqrt(R*R-k*k))-1,
                   rux=xb+(ll)(sqrt(R*R-k*k)),
                   ldx=xa-(ll)(sqrt(R*R-k*k))-1,
                   rdx=xb+(ll)(sqrt(R*R-k*k));
                if(k){
                    Q.push_back({i,-1,lux,ydb,ydb});
                    Q.push_back({i,1,rux,ydb,ydb});
                    Q.push_back({i,-1,ldx,yda,yda});
                    Q.push_back({i,1,rdx,yda,yda});
                }else{
                    Q.push_back({i,-1,lux,yda,ydb});
                    Q.push_back({i,1,rux,yda,ydb});
                }
            }
        }
        sort(Q.begin(),Q.end());
        int l=0;
        for(auto &[id,type,x,down,up]:Q){
            while(l<all[R].size()&&all[R][l].x<=x){
                add(all[R][l].y,1);
                l++;
            }
            ans[id]+=(type*RegionSum(down,up));
        }
        for(l=0;l<all[R].size();l++){
            add(all[R][l].y,-1);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<'\n';
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