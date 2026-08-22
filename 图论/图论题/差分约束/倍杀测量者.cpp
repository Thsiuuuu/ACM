#include <bits/stdc++.h>
using namespace std;
#define double long double 

const int N=1e3+10;
const double eps=1e-6;


struct edge{
    int v;
    double w;
    int number;
};

vector<vector<edge>> e(N),cpy(N),score(N);



bool spfa(double t,int n){
    vector<int> cnt(N,0),vis(N,0);
    vector<double> dis(N,1145141010);
    dis[0]=0,vis[0]=1;
    queue<int> q;
    q.push(0);
    cpy=score;

    for(int a=1;a<=n;a++){
        for(auto [b,w,number]:e[a]){
            if(number==1){
                if(w-t<=eps){
                    continue;
                }
                cpy[a].push_back({b,-log2l(w-t),1});
            }else{
                cpy[a].push_back({b,log2l(w+t),1});
            }
        }
    }
    
    while(q.size()){
        int u=q.front();
        q.pop(),vis[u]=0;
        for(auto [v,w,number]:cpy[u]){
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n) return false;
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    int n,s,t;
    cin>>n>>s>>t;
    
    for(int i=0;i<s;i++){
        int op,a,b;
        double k;
        cin>>op>>a>>b>>k;
        if(op==1){
            e[a].push_back({b,k,1});
        }else{
            e[a].push_back({b,k,2});
        }
    }
    for(int i=0;i<t;i++){
        int c;
        double x;
        cin>>c>>x;
        score[0].push_back({c,log2l(x),0});
        score[c].push_back({0,-log2l(x),0});
    }
    double l=0,r=10;
    double mid;
    double ans=-1;
    while(r-l>=eps){
        mid=(l+r)/2;
        if(!spfa(mid,n)){
            ans=mid;
            l=mid;
        }else{
            r=mid;
        }
    }

    if(llabs(ans+1.0)<=eps){
        cout<<"-1";
    }else{
        cout<<fixed<<setprecision(10)<<ans<<'\n';
    }

    return 0;
}