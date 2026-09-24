#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
#define u128 __uint128_t
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

#define ls (i<<1)
#define rs ((i<<1)|1)
int cnt[(1<<18)+1],n,q,tr[1<<19],tot[1<<19];
const ll mod=998244353;
void sol() {
    cin>>n>>q;
    VII query((1<<(n+1)));
    for(int i=1;i<(1<<(n+1));i++) tr[i]=1e9;
    bool is=true;    
    for(int i=0;i<q;i++){
        int u,x;cin>>u>>x;
        if(tot[u]==0) tot[u]=x;
        else if(tot[u]^x) is=false;
        query[x].push_back(u);
    }
    bool ck=true;
    for(int x:query[1<<n]){
        if(x==1) ck=false;
    }
    if(ck) query[1<<n].push_back(1);
    for(int i=1;i<query.size();i++){
        if(query[i].size()==0) continue;
        if(query[i].size()>=1){
            sort(query[i].begin(),query[i].end());
            query[i].erase(unique(query[i].begin(),query[i].end()),query[i].end());
            tr[query[i][0]]=i;
            for(int j=1;j<query[i].size();j++){
                ck=false;
                for(int tt=0;tt<=18;tt++){
                    if((query[i][j]>>tt)==query[i][j-1]){ck=true;break;}
                }
                if(!ck) {cout<<"0\n";return ;}
                tr[query[i][j]]=i;
            }
        }
        // cout<<query[i].back()<<" "<<tr[query[i].back()]<<'\n';
    }
    // for(int i=1;i<(1<<(n+1));i++) cout<<i<<" "<<tr[i]<<'\n';
    for(int i=1;i<(1<<n);i++){
        if(tr[ls]!=1e9&&tr[ls]>tr[i]){
            is=false;
            break;
        }
        else tr[ls]=min(tr[ls],tr[i]);
        if(tr[rs]!=1e9&&tr[rs]>tr[i]){
            is=false;
            break;
        }
        else tr[rs]=min(tr[rs],tr[i]);
    }
    if(!is){
        cout<<"0";return ;
    }
    // cout<<'\n';
    ll ans=1;
    for(int i=1;i<query.size();i++){
        if(query[i].size()==0) continue;
        int L,R;L=R=query[i].back();
        while(L<(1<<n)) L<<=1,R<<=1,R|=1;
        ll res=0;
        for(int j=L;j<=R;j++) res+=(tr[j]==i);
        ans*=res;
        ans%=mod;
    }
    for(int i=(1<<n);i<(1<<(n+1));i++){
        // cout<<i<<" "<<tr[i]<<'\n';
        cnt[tr[i]]++;
        // cout<<i<<" "<<tr[i]<<" "<<cnt[tr[i]]<<'\n';
    }
    if(!is){
        cout<<"0\n";
        return ;
    }
    // cout<<ans<<'\n';
    VI a;
    for(int i=1;i<=(1<<n);i++){
        for(int j=0;j<cnt[i]-1;j++) a.push_back(i);
    }
    for(int i=1;i<=(1<<n);i++) cnt[i]=0;
    for(int i=0;i<a.size();i++){
        if(cnt[a[i]]) continue;
        cnt[a[i]]=a[i];
    }
    // for(int x:a) cout<<x<<" ";
    // cout<<'\n';
    for(int i=0,sum=0,k=0;i<a.size();i++){
        while(k+1<query.size()&&k+1<=a[i]) k++,sum+=(query[k].size()>0);
        int j=i;
        cnt[a[i]]-=sum;
        while(j+1<a.size()&&a[j+1]==a[i]){
            j++;
        }
        i=j;
    }
    // for(int i=1;i<=(1<<n);i++){
    //     cout<<i<<" "<<cnt[i]<<'\n';
    // }
    for(int i=0;i<a.size();i++){
        if(cnt[a[i]]-i>0) ans*=(1ll*cnt[a[i]]-i+mod)%mod,ans%=mod;
        else{
            cout<<"0";
            return ;
        }
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