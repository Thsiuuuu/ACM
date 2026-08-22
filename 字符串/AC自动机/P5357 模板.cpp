#include <bits/stdc++.h>
using namespace std;

const int N=2e5+6;
const int LEN=2e6+6;
const int SIZE=2e5+6;

int n;


namespace AC{
    struct Node{
        int son[26];//子节点
        int ans;//匹配计数
        int fail;//fail指针
        int du;//入度
        int idx;

        void init(){
            memset(son,0,sizeof(son));
            ans=fail=idx=0;
        }
    }tr[SIZE];

    int tot;//节点总数
    int ans[N],pidx;

    void init(){
        tot=pidx=0;
        tr[0].init();
    }

    void insert(const string& s,int &idx){
        int u=0;
        for(int i=1;i<s.size();i++){
            int &son=tr[u].son[s[i]-'a'];//下一个子节点的引用
            if(!son){//如果没有则插入新节点，并初始化
                son=++tot,tr[son].init();//从下一个节点继续
            }
            u=son;
        }

        //由于有可能有多个相同的模式串，需要将相同的模式串映射到同一个编号
        if(!tr[u].idx){
            tr[u].idx=++pidx;//第一次出现，新增编号
        }
        idx=tr[u].idx;//这个模式串的编号对应这个节点的编号
    }

    void build(){
        queue<int> q;
        for(int i=0;i<26;i++){
            if(tr[0].son[i]){
                q.push(tr[0].son[i]);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<26;i++){
                if(tr[u].son[i]){//存在对应子节点
                    tr[tr[u].son[i]].fail=tr[tr[u].fail].son[i];//只用跳一次fail指针
                    tr[tr[tr[u].fail].son[i]].du++;//入度计数
                    q.push(tr[u].son[i]);//加入队列
                }else{
                    tr[u].son[i]=tr[tr[u].fail].son[i];//将不存在的字典树的状态连接到失配指针的对应状态
                }
            }
        }
    }

    void query(const string& t){
        int u=0;
        for(int i=1;i<t.size();i++){
            u=tr[u].son[t[i]-'a'];
            tr[u].ans++;
        }
    }

    void topu(){
        queue<int> q;
        for(int i=0;i<=tot;i++){
            if(tr[i].du==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans[tr[u].idx]=tr[u].ans;
            int v=tr[u].fail;
            tr[v].ans+=tr[u].ans;
            if(!--tr[v].du) q.push(v);
        }
    }
}

int idx[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    AC::init();
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        s=' '+s;
        AC::insert(s,idx[i]);
        AC::ans[i]=0;
    }
    AC::build();
    string s;
    cin>>s;
    s=' '+s;
    AC::query(s);
    AC::topu();
    for(int i=1;i<=n;i++){
        cout<<AC::ans[idx[i]]<<'\n';
    }
    return 0;
}