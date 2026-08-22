#include <bits/stdc++.h>
using namespace std;

/*

    正解是AC自动机，学完AC自动机来补题了
    这个无限长的安全代码，即不含有任何一个模式串
    等价于对安全代码进行匹配，一直匹配过程中不会访问到模式串末尾对应的节点，同时fail指向这些模式串对应节点也不会访问，因为fail指过去，就意味着那个字符串是自己的最长后缀子串，匹配到自己就说明包含某一个模式串
    所以说一直匹配下去，必然会有环

    如果说，从根节点出发，并且有一个带环的路，使得可以不含有上述的非法节点，那么就相当于匹配过程当中不会匹配到非法节点
    
    所以说从0号节点出发，dfs找环即可



*/

const int SIZE=3e4+10;

namespace AC{
    struct NODE{
        int son[2];
        int fail;
        int idx;
        int du;
        bool danger;

        vector<int> defail;

        void init(){
            memset(son,0,sizeof(son));
            fail=idx=du=0;
            danger=false;
        }
    }tr[SIZE];

    int pidx,tot;
    void init(){
        pidx=tot=0;
        tr[0].init();
    }

    void insert(string s){
        int u=0;
        for(int i=1;i<s.size();i++){
            int &son=tr[u].son[s[i]-'0'];
            if(!son){
                son=++tot;
                tr[tot].init();
            }
            u=son;
        }
        if(!tr[u].idx){
            tr[u].idx=++pidx;
            tr[u].danger=true;
        }
    }

    void build(){
        queue<int> q;
        for(int i=0;i<2;i++){
            if(tr[0].son[i]){
                q.push(tr[0].son[i]);
            }
        }
        while(q.size()){
            int u=q.front();
            q.pop();
            for(int i=0;i<2;i++){
                if(tr[u].son[i]){
                    tr[tr[u].son[i]].fail=tr[tr[u].fail].son[i];
                    tr[tr[tr[u].fail].son[i]].defail.push_back(tr[u].son[i]);
                    q.push(tr[u].son[i]);
                }else{
                    tr[u].son[i]=tr[tr[u].fail].son[i];
                }
            }
        }


        for(int i=0;i<=tot;i++){
            if(tr[i].danger){
                q.push(i);
            }
        }
        while(q.size()){
            int u=q.front();
            q.pop();
            for(int v:tr[u].defail){
                tr[v].danger=true;
                q.push(v);
            }
        }
    }

    void query(){
        int u=0;
        vector<int> instk(tot+1,0),vis(tot+1,0);
        auto dfs=[&](auto &&self,int u,bool &flag){
            instk[u]=1,vis[u]=1;
            for(int i=0;i<2;i++){
                if(flag){
                    return ;
                }
                int v=tr[u].son[i];
                if(!tr[tr[u].son[i]].danger){
                    if(vis[v]&&instk[v]){
                        flag=true;
                    }
                    if(!vis[v]){
                        self(self,v,flag);
                    }
                }
            }
            instk[u]=0;
        };

        bool flag=false;
        dfs(dfs,0,flag);
        if(flag){
            cout<<"TAK\n";
        }else{
            cout<<"NIE\n";
        }
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    AC::init();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        AC::insert(' '+s);
    }
    AC::build();
    AC::query();

    // for(int i=0;i<=AC::tot;i++){
    //     cout<<AC::
    // }

    // int n;
    // cin>>n;
    // bool f1,f2,f3,f4;
    // f1=f2=f3=f4=true;//f1,f2,f3,f4 全0,全1,01,10
    // int cnt=0;
    // vector<string> st;
    // for(int i=0;i<n;i++){
    //     string s;
    //     cin>>s;
    //     st.push_back(s);
    //     if(count(s.begin(),s.end(),'1')==s.size()&&f2){
    //         cnt++;
    //         f2=false;
    //     }else if(count(s.begin(),s.end(),'1')==0&&f1){
    //         cnt++;
    //         f1=false;
    //     }else if(s=="01"&&f3){
    //         cnt++;
    //         f3=false;
    //     }else if(s=="10"&&f4){
    //         cnt++;
    //         f4=false;
    //     }
    // }
    // if(find(st.begin(),st.end(),'1')!=st.end()&&find(st.begin(),st.end(),'0')!=st.end()){
    //     cout<<"NIE";
    // }
    // if(!(f1&&f2)){
    //     cout<<"TAK";
    // }
    // else if(cnt>=3){
    //     cout<<"NIE";
    // }else{
    //     cout<<"TAK";
    // }
    return 0;
}