#include <bits/stdc++.h>
using namespace std;
/*

    只允许某个单词以其中一个单词子串的形式出现，不能是拼接的，类似于真实的文章
    就可以用在其中加上间隔符进行分隔,匹配到分隔符手动跳转即可

*/



namespace AC{
    const int SIZE=1e6+5;
    const int N=210;
    struct NODE{
        int son[26];
        int ans;
        int idx;
        int fail;
        int du;
        
        void init(){
            memset(son,0,sizeof(son));
            ans=idx=fail=du=0;
        }
    }tr[SIZE];

    int tot,pidx;
    int ans[N];
    void init(){
        tr[0].init();
        tot=pidx=0;
    }

    void insert(string s,int &idx){
        int u=0;
        for(int i=1;i<s.size();i++){
            int &son=tr[u].son[s[i]-'a'];
            if(!son){
                son=++tot;
                tr[son].init();
            }
            u=son;
        }
        if(!tr[u].idx){
            tr[u].idx=++pidx;
        }
        idx=tr[u].idx;
    }

    void build(){
        queue<int> q;
        for(int i=0;i<26;i++){
            if(tr[0].son[i]){
                q.push(tr[0].son[i]);
            }
        }
        while(q.size()){
            int u=q.front();
            q.pop();
            for(int i=0;i<26;i++){
                if(tr[u].son[i]){
                    tr[tr[u].son[i]].fail=tr[tr[u].fail].son[i];
                    tr[tr[tr[u].fail].son[i]].du++;
                    q.push(tr[u].son[i]);
                }else{
                    tr[u].son[i]=tr[tr[u].fail].son[i];
                }
            }
        }
    }

    void query(string t){
        int u=0;
        for(int i=1;i<t.size();i++){
            if(t[i]=='#'){
                u=0;
            }else{
                u=tr[u].son[t[i]-'a'];
            }
            tr[u].ans++;
        }
    }

    void topu(){
        queue<int> q;
        for(int i=0;i<=tot;i++){
            if(!tr[i].du){
                q.push(i);
            }
        }
        while(q.size()){
            int u=q.front();
            q.pop();
            ans[tr[u].idx]=tr[u].ans;
            int v=tr[u].fail;
            tr[v].ans+=tr[u].ans;
            if(!--tr[v].du) q.push(v);
        }
    }



}
void sol() {
    int n;
    cin>>n;
    string t="";
    AC::init();
    vector<string> vec(n+1);
    vector<int> idx(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
        AC::insert(' '+vec[i],idx[i]);
        t=t+vec[i]+"#";
        AC::ans[i]=0;
    }
    AC::build();
    AC::query(' '+t);
    AC::topu();
    for(int i=1;i<=n;i++){
        cout<<AC::ans[idx[i]]<<'\n';
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}