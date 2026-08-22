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
const int N=1e6+10;
ll a[N],st[N],lazy[1010];
int bi[N],bl[1010],br[1010];
int blo,num;
//对第k块进行拷贝并排序
void Sort(int k){
    for(int i=bl[k];i<=br[k];i++) st[i]=a[i];
    sort(st+bl[k],st+br[k]+1);
}
void Modify(int l,int r,ll c){
    int x=bi[l],y=bi[r];
    if(x==y){
        for(int i=l;i<=r;i++) a[i]+=c;
        Sort(x);
    }else{
        for(int i=l;i<=br[x];i++) a[i]+=c;
        for(int i=bl[y];i<=r;i++) a[i]+=c;
        for(int i=x+1;i<y;i++){
            lazy[i]+=c;
        }
        Sort(x);
        Sort(y);
    }
}
ll query(int l,int r,ll c){
    int x=bi[l],y=bi[r],ans=0;
    if(x==y){
        for(int i=l;i<=r;i++) ans+=(a[i]>=(c-lazy[x]));
    }else{
        for(int i=l;i<=br[x];i++) ans+=(a[i]>=(c-lazy[x]));
        for(int i=bl[y];i<=r;i++) ans+=(a[i]>=(c-lazy[y]));
        for(int i=x+1;i<=y-1;i++){
            ans+=(st+br[i]+1-lower_bound(st+bl[i],st+br[i]+1,c-lazy[i]));
        }
    }
    return ans;
}
void sol() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st[i]=a[i];
    }
    blo=sqrt(n);
    num=(n+blo-1)/blo;
    for(int i=1;i<=n;i++){
        bi[i]=(i-1)/blo+1;
    }
    for(int i=1;i<=num;i++){
        bl[i]=blo*(i-1)+1;
        br[i]=min(i*blo,n);
    }
    for(int i=1;i<=num;i++){
        sort(st+bl[i],st+br[i]+1);
    }
    while(q--){
        char op;
        int l,r,w;
        cin>>op;
        cin>>l>>r>>w;
        if(op=='A'){
            cout<<query(l,r,w)<<'\n';
        }else{
            Modify(l,r,w);
        }
    }
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