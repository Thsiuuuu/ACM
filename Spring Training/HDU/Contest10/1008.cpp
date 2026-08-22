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

#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
const ll mod=998244353;
const int N=1e5+10;
ll tr[N<<2],tg[N<<2],mul[N<<2],a[N],len[N<<2];

void up(int u){
    mul[u]=((tr[ls]*tr[rs]%mod+mul[ls])%mod+mul[rs])%mod;
    tr[u]=(tr[ls]+tr[rs])%mod;
}

void down(int u){
    if(len[ls]^1){
        mul[ls]=(
            (mul[ls]
                +
             tg[u]*(len[ls]-1)%mod*tr[ls]%mod)%mod
                +
             len[ls]*(len[ls]-1)/2%mod*tg[u]%mod*tg[u]%mod
        )%mod;
    }
    if(len[rs]^1){
        mul[rs]=(
            (mul[rs]
                +
                tg[u]*(len[rs]-1)%mod*tr[rs]%mod)%mod
                +
                len[rs]*(len[rs]-1)/2%mod*tg[u]%mod*tg[u]%mod
        )%mod;
    }
    tr[ls]=(tr[ls]+len[ls]*tg[u]%mod)%mod;
    tg[ls]=(tg[ls]+tg[u])%mod;
    tr[rs]=(tr[rs]+len[rs]*tg[u]%mod)%mod;
    tg[rs]=(tg[rs]+tg[u])%mod;
    tg[u]=0;
}

void build(int l,int r,int u){
    tg[u]=0;
    if(l==r){
        tr[u]=a[l];
        mul[u]=0;
        len[u]=1;
        return ;
    }
    build(l,mid,ls);
    build(mid+1,r,rs);
    up(u);
    len[u]=len[rs]+len[ls];
}

void add(int u,int l,int r,int jl,int jr,ll jv){
    if(jl<=l&&r<=jr){
        if(len[u]!=1){
            mul[u]=(
                (mul[u]
                    +
                jv*(len[u]-1)%mod*tr[u]%mod)%mod
                    +
                len[u]*(len[u]-1)/2%mod*jv%mod*jv%mod
            )%mod;
        }
        tr[u]=(tr[u]+len[u]*jv%mod)%mod;
        tg[u]=(tg[u]+jv)%mod;
        return ;
    }
    if(jl<=mid){
        if(tg[u]){
            down(u);
        }
        add(ls,l,mid,jl,jr,jv);
    }
    if(jr>mid){
        if(tg[u]){
            down(u);
        }
        add(rs,mid+1,r,jl,jr,jv);
    }
    up(u);
}

ll query(int u,int l,int r,int jl,int jr,ll& ans){
    if(l==r){
        // cout<<"hel\n";
        return tr[u];
    }
    
    // cout<<u<<'\n';
    if(jl<=l&&r<=jr){
        ans=(ans+mul[u])%mod;
        return tr[u];
    }
    ll Lsum,Rsum;
    Lsum=Rsum=0;
    if(jl<=mid){
        if(tg[u]){
            down(u);
        }
        Lsum=query(ls,l,mid,jl,jr,ans);
    }
    if(jr>mid){
        if(tg[u]){
            down(u);
        }
        Rsum=query(rs,mid+1,r,jl,jr,ans);
    }
    // cout<<"hel\n";
    ans=(ans+Lsum*Rsum%mod)%mod;
    return (Lsum+Rsum)%mod;
}

void sol() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    while(q--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            ll d;
            cin>>d;
            add(1,1,n,l,r,d);
        }else{
            ll ans=0;
            query(1,1,n,l,r,ans);
            cout<<ans<<'\n';
        }
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