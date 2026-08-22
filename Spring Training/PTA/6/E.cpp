#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ull unsigned long long 

ll ksm(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a;
        b>>=1,a=a*a;
    }
    return res;
}

int n;
ll a,b;
bool f=false;
void dfs(ll sum,int i){
    if(sum>b) return ;
    if(i==n&&sum>=a&&sum<=b){
        cout<<sum<<'\n';
        f=true;
    }else{
        if((i+1)==10){
            dfs(sum*10,i+1);
        }else if((i+1)%2==0){
            for(int x=0;x<=8;x+=2){
                if((sum*10+x)%(i+1)==0) dfs(sum*10+x,i+1);
            }
        }else{
            for(int x=0;x<=9;x++){
                if(i==0&&x==0) continue;
                if((sum*10+x)%(i+1)==0) dfs(sum*10+x,i+1);
            }
        }
    }
}

void sol(){
    cin>>n;
    cin>>a>>b;
    a=max(ksm(10,n-1),a);
    b=min(ksm(10,n)-1,b);
    dfs(0,0);
    if(!f) cout<<"No Solution";
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