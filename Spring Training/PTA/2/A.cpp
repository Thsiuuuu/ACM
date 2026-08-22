#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 
#define ls u<<1
#define rs u<<1|1
#define mid ((l+r)>>1)

const int N=2e6+2;
int win[N],fail[N];
int mn[N],k;


void up(int u){
    mn[u]=max({mn[ls],mn[rs],fail[u]});
}

void build(int u){
    if(u*2>=(1<<k)){
        mn[u]=fail[u];
        return ;
    }
    build(ls);
    build(rs);
    up(u);
}


void sol(){
    cin>>k;
    for(int i=1;i<=k;i++){
        for(int j=0;j<(1<<(k-i));j++){
            cin>>fail[(1<<(k-i))+j];
            // cout<<((1<<(k-i))+j)<<" "<<fail[(1<<(k-i))+j]<<'\n';
        }
    }

    cin>>win[1];
    build(1);
    for(int u=1;u<(1<<(k));u++){
        if(win[u]<fail[u]){
            cout<<"No Solution";
            return ;
        }
        // cout<<u<<" ";
        // cout<<mn[ls]<<" "<<mn[rs]<<'\n';
        if(win[u]>=mn[ls]&&fail[u]>=mn[rs]){
            win[ls]=win[u],win[rs]=fail[u];
        }else if(fail[u]>=mn[ls]&&win[u]>=mn[rs]){
            win[ls]=fail[u],win[rs]=win[u];
        }else{
            cout<<"No Solution";
            return ;
        }
    }
    for(int i=(1<<k);i<=(1<<(k+1))-1;i++){
        if(i!=(1<<k)) cout<<" ";
        cout<<win[i];
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t=1;
    // cin>>t;
    while(t--){
        sol();
    }
    return 0;
}