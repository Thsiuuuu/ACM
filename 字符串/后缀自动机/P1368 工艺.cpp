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
const int sig=30,N=12e5+10;
struct SuffixAutomaton{
    struct Node{
        int len,link,nxt[sig];
        Node():len(0),link(-1){
            memset(nxt,-1,sizeof(nxt));
        }
    }t[N];
    int tot,last;
    void init(){
        tot=1,last=0;
        t[0]=Node();
    }
    void insert(int c){
        int cur=tot++;
        t[cur]=Node();
        t[cur].len=t[last].len+1;
        int p=last;
        while(p!=-1&&t[p].nxt[c]==-1){
            t[p].nxt[c]=cur;
            p=t[p].link;
        }
        if(p==-1) t[cur].link=0;
        else{
            int q=t[p].nxt[c];
            if(t[q].len==t[p].len+1){
                t[cur].link=q;
            }else{
                int clone=tot++;
                t[clone]=t[q];
                t[clone].len=t[p].len+1;
                while(p!=-1&&t[p].nxt[c]==q) {
                    t[p].nxt[c]=clone;
                    p=t[p].link;
                }
                t[q].link=t[cur].link=clone;
            }
        }
        last=cur;
    }
    void bfs(int siz){
        for(int nw=0,tim=0;tim<siz;tim++){
            for(int i=0;i<30;i++){
                if(t[nw].nxt[i]!=-1){
                    nw=t[nw].nxt[i];
                    cout<<i<<" ";
                    break;
                }
            }
        }
    }
};
SuffixAutomaton S;
void sol() {
    int n;cin>>n;
    S.init();
    VI all(n<<1);
    for(int i=0;i<n;i++){
        cin>>all[i];
        all[i+n]=all[i];
    }
    for(int i=0;i<all.size();i++){
        S.insert(all[i]);
    }
    S.bfs(n);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;

    while (t--) {
        sol();
    }
    return 0;
}