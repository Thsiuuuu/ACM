#include <bits/stdc++.h>
using namespace std;

#define ll long long 

const int N=1e3+10;
int dfn[N],low[N],idx;
stack<int> stk;
int m;
vector<int> e[N];
bool is[N],flag[N];
ll mul=1,ans=0;

vector<vector<int>> bcc;


void Tarjan(int u,int fa){
    dfn[u]=low[u]=++idx;
    stk.push(u);
    int child=0;
    for(int v:e[u]){
        if(!dfn[v]){
            child++;
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                if(fa^u)  flag[u]=true;
                int x;
                vector<int> res;
                res.push_back(u);
                do{
                    x=stk.top();
                    res.push_back(x);
                    stk.pop();
                }while(x^v);
                bcc.push_back(res);
            }
        }else low[u]=min(low[u],dfn[v]);
    }
    if(fa==u&&child>=2) flag[u]=true;
}

void sol(){
    for(int i=1;i<=N-5;i++){
        dfn[i]=low[i]=0;
        is[i]=flag[i]=false;
        e[i].clear();
    }
    mul=1,ans=idx=0; 
    for(int i=0;i<m;i++){
        int s,t;
        cin>>s>>t;
        e[s].push_back(t),e[t].push_back(s);
        is[s]=is[t]=true;
    }

    for(int i=1;i<N;i++){
        if(is[i]){
            Tarjan(i,i);
            break;
        }
    }

    if(bcc.size()==1){
        ans=2,mul=idx*(idx-1)/2;
    }else{
        for(auto res:bcc){
            int cnt=0;
            for(int x:res){
                if(flag[x]) cnt++;
            }
            if(cnt==1) ans+=1,mul*=(res.size()-1ll);
        }
    }
    bcc.clear();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int cnt=1;
    while(1){
        cin>>m;
        if(!m) return 0;
        sol();
        cout<<"Case "<<(cnt++)<<": "<<ans<<" "<<mul<<'\n';
    }
}