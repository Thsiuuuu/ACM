#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

#define int long long 

/*
    强连通分量然后判环
       
*/


const int N=2e5+10;
int low[N],dfn[N],tot;
int stk[N],instk[N],cnt,top;
int siz[N],scc[N];
int number[N];
vector<int> e[N];

int n,m;


void tarjan(int x){
    low[x]=dfn[x]=++tot;
    stk[++top]=x;
    instk[x]=1;
    for(int y:e[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[y],low[x]);
        }else if(instk[y]){
            low[x]=min(low[x],dfn[y]);
        }
    }

    if(low[x]==dfn[x]){

        //只有自己一个节点，看子节点有没有在环内的
        if(stk[top]==x){


             //cout<<"t1\n";

            bool st=true;
            for(int y:e[x]){
                if(siz[scc[y]]){//比赛时候这里写错了，tarjan算法一定要注意用的是缩点之后的索引还是原来的索引
                    st=false;
                    scc[x]=scc[y];
                    siz[scc[x]]++;
                    instk[x]=0;
                    top--;
                    break;
                }
            }

            if(st){
                siz[++cnt]=0;
                instk[x]=0;
                scc[x]=cnt;
                top--;
            }
            
        }else{


            // cout<<"t2\n";

            int y;
            cnt++;
            do{
                 y=stk[top--];
                 scc[y]=cnt;
                 siz[scc[y]]++;
                 instk[y]=0;

            }while(y!=x);
        }
    }
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
    }


    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    
    int sum=0;

    // for(int i=1;i<=n;i++){
    //     cout<<scc[i]<<" ";
    // }


    // cout<<cnt<<" ";
    // for(int i=1;i<=cnt;i++) cout<<siz[i]<<" ";
    
    for(int i=1;i<=cnt;i++){
        if(siz[i]) sum+=siz[i];
    }

    cout<<sum;

    return 0;
}

