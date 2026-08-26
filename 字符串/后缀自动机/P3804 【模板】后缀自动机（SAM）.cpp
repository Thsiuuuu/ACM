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
struct SuffixAutomaton{
    const int Sig=26,MAXN=2e6+10;//maxn至少是字符串总长度2倍
    struct Node{
        int len;
        int link;
        int nxt[Sig];
        Node():len(0),link(-1){
            memset(nxt,-1,sizeof(nxt));
        }
    }t[N];
    int tot,last;
    void init(){
        tot=1,last=0;
        t[0]=Node();
    }
    void insert(int ch){
        int cur=tot++;
        t[cut]=Node();
        t[cur].len=t[last].len+1;
        int p=last;
        while(p!=-1&&!t[p].nxt[c]==-1){
            t[p].nxt[c]=cur;
            p=t[p].link;
        }
        if(p==-1){
            t[cur].link=0;
        }else{
            int q=t[p].nxt[c];
            if(t[p].len+1==t[q].len){t[cur].link=q;}
        }else{
            int clone=tot++;
            t[clone]=t[q];
            t[clone].len=t[p].len+1;//接着原来那个点，然后把>x+1的点腾出来
            while(p!=-1&&t[p].nxt[c]==q){
                t[p].nxt[c]=clone;
                p=t[p].link;
            }//链上沿着s_i重连边
            t[q].link=t[cur].link=clone;//两个状态都连到自己的link超集状态上面
        }
        last=cur;
    }
    void build(const string&s){
        init();
        for(char ch:s) insert(ch-'a');
    }
    bool contain(const string&t){
        int p=0;
        for(char ch:t){
            int c=ch-'a';
            if(!t[p].nxt[c]) return false;
            p=t[p].nxt[c];
        }
        return true;
    }//是否包含子串
    ll DisSubString(){
        ll ans=0;
        for(int p=1;p<tot;p++) ans+=t[p].len-t[t[p].link].len;
        return ans;
    }
};
void sol() {
    
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