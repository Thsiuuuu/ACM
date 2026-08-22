#include <bits/stdc++.h>
using namespace std;
/*



*/

const int N=160;
const int SIZE=11000;

namespace AC{
    struct NODE{
        int son[26];
        int ans;
        int fail;
        int du;
        int idx;
        
        void init(){
            memset(son,0,sizeof(son));
            ans=fail=idx=0;
        }
    }tr[SIZE];

    int tot;
    int ans[N],pidx;
    void init(){
        tot=pidx=0;
        tr[0].init();
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
        while(q.size()){
            int u=q.front();
            q.pop();
            ans[tr[u].idx]=tr[u].ans;
            int v=tr[u].fail;
            tr[v].ans+=tr[u].ans;
            if(!--tr[v].du){
                q.push(v);
            }
        }
    }
}

void sol(int n) {
    AC::init();

    vector<string> vec(n+1);
    vector<int> idx(n+1,0);
    for(int i=1;i<=n;i++){
        string s;
        cin>>vec[i];
        s=' '+vec[i];
        AC::insert(s,idx[i]);
        AC::ans[i]=0;
    }

    AC::build();
    string t;
    cin>>t;
    t=' '+t;

    // for(int i=1;i<=n;i++){
    //     cout<<vec[i]<<" ";
    // }
    // cout<<'\n';
    int mx=-1;
    AC::query(t);
    AC::topu();
    for(int i=1;i<=n;i++){
        mx=max(mx,AC::ans[idx[i]]);
    }
    cout<<mx<<'\n';
    for(int i=1;i<=n;i++){
        if(mx==AC::ans[idx[i]]){
            cout<<vec[i]<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin>>t;

    int n;
    while (cin>>n) {
        if(n==0){
            return 0;
        }
        sol(n);
    }
    return 0;
}