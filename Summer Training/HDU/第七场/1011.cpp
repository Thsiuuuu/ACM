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

const int N=1e6+10,M=1e9;
int fa[N],s[N];
ll rt[N],b[N];
bool que[N];
int find(int x){
    if(fa[x]^x){
        int nx=fa[x];
        fa[x]=find(fa[x]);
        b[x]+=s[x]*b[nx];
        s[x]*=s[nx];
    }
    return fa[x];
}
void unite(int x,int y,ll c){
    int fx=find(x),fy=find(y);
    if(que[fy]){
        swap(x,y);
        swap(fx,fy);
    }
    //要永远让y是被修改的那个
    b[fy]=(2*c-b[y]-b[x])/s[y],s[fy]=-s[x]/s[y];
    fa[fy]=fx;
}
void sol() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        s[i]=1,b[i]=que[i]=0;
    }
    int k=0;
    for(int tt=0;tt<m;tt++){
        int A,B,D;cin>>A>>B>>D;
        int i=(A+k-1)%n+1,
            j=(B+k-1)%n+1,
            c=(D+k)%M+1;    
        int fi=find(i),fj=find(j);
        if(que[fi]&&que[fj]){
            if(s[i]*rt[fi]+b[i]+s[j]*rt[fj]+b[j]==2*c){
                cout<<"Yes\n";
                k++;
            }else cout<<"No\n";
        }else if(fi^fj){
            unite(i,j,c);
            k++;
            cout<<"Yes\n";
        }else{
            if(s[i]==s[j]){
                rt[fi]=(2*c-b[i]-b[j])/(s[i]+s[j]);
                que[fi]=true;
                k++;cout<<"Yes\n";
            }else{
                if(b[i]+b[j]!=2*c) cout<<"No\n";
                else{
                    cout<<"Yes\n";k++;
                }
            }
        }
    }
    cout<<'\n';
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