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

const int N=3e5+10;
char s[N];
int n,m,p,rk[N<<1],oldrk[N<<1],sa[N<<1],id[N],cnt[N],height[N];
ll a[N];
int siz[N],fa[N];
pll Mx[N],Mn[N],Res[N];//都是最,次/大,小
ll Ans,CntAns=INT64_MIN;
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
ll cal(ll x){
    return (ll)(x*(x-1))>>1;
}
void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx^fy){
        if(siz[fx]<siz[fy]) swap(fx,fy);
        Ans-=cal(siz[fx]);
        Ans-=cal(siz[fy]);
        Ans+=cal(siz[fx]+siz[fy]);

        vector<ll> a1,a2;//最大，最小
        a1.push_back(Mx[fx].first);
        a1.push_back(Mx[fx].second);
        a1.push_back(Mx[fy].first);
        a1.push_back(Mx[fy].second);

        a2.push_back(Mn[fx].first);
        a2.push_back(Mn[fx].second);
        a2.push_back(Mn[fy].first);
        a2.push_back(Mn[fy].second);
        sort(a1.begin(),a1.end(),greater<ll>());
        sort(a2.begin(),a2.end());
        Mx[fx]=make_pair(a1[0],a1[1]);
        Mn[fx]=make_pair(a2[0],a2[1]);

        siz[fx]+=siz[fy];
        fa[fy]=fx;

        // cout<<sa[fx]<<" "<<sa[fy]<<"::\n";
        // cout<<a1[0]<<" "<<a1[1]<<" "<<a2[0]<<" "<<a2[1]<<'\n';
        
        CntAns=max({CntAns,(ll)a1[0]*a1[1],(ll)a2[0]*a2[1]});
    }
}

void sol() {
    cin>>n;
    scanf("%s", s + 1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
        siz[i]=1;
        Mx[i]={a[i],INT64_MIN};
        Mn[i]={INT64_MAX,a[i]};
    }
    m = 128;

    for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;

    for (int w = 1;; w <<= 1, m = p) {  // m = p 即为值域优化
        int cur = 0;
        for (int i = n - w + 1; i <= n; i++) id[++cur] = i;
        for (int i = 1; i <= n; i++)
        if (sa[i] > w) id[++cur] = sa[i] - w;

        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++) cnt[rk[i]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];

        p = 0;
        memcpy(oldrk, rk, sizeof(oldrk));
        for (int i = 1; i <= n; i++) {
        if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
            oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
            rk[sa[i]] = p;
        else
            rk[sa[i]] = ++p;
        }

        if (p == n) break;  // p = n 时无需再排序
    }
    for(int i=1,k=0;i<=n;i++){
        if(rk[i]==1) continue;
        if(k) k--;
        while(s[i+k]==s[sa[rk[i]-1]+k]) k++;
        height[rk[i]]=k;
    }
    vector<VI> Seq(n);
    for(int i=1;i<=n;i++){
        if(i==1) continue;
        Seq[height[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        if(Seq[i].size()){
            sort(Seq[i].begin(),Seq[i].end());
        }
    }
    
    for(int len=n-1;len>=0;len--){
        // cout<<"\nLen: "<<len<<'\n';
        for(auto& idx:Seq[len]){
            // cout<<idx<<" ";    
            unite(sa[idx-1],sa[idx]);
        }
        Res[len].first=Ans,Res[len].second=(CntAns==INT64_MIN?0:CntAns);
    }
    for(int i=0;i<n;i++){
        printf("%lld %lld\n",Res[i].first,Res[i].second);
    }
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}