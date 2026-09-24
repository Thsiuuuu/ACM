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
const int maxn=5e5+10;
struct PAM{
    int num[maxn],s[maxn],nxt[maxn][26],fail[maxn],len[maxn],last,tot,now;
    void clear(){
        fail[0]=tot=now=1;
        len[1]=s[0]=-1;
        memset(nxt[0],0,sizeof(nxt[0]));
        memset(nxt[1],0,sizeof(nxt[1]));
    }
    PAM(){clear();}
    int newnode(int length){
        tot++;
        memset(nxt[tot],0,sizeof(nxt[tot]));
        fail[tot]=num[tot]=0;
        len[tot]=length;
        return tot;
    }
    int get_fail(int x){
        while(s[now-len[x]-2]!=s[now-1]) x=fail[x];
        return x;
    }
    void insert(int ch){
        s[now++]=ch;
        int cur=get_fail(last);
        if(!nxt[cur][ch]){
            int tt=newnode(len[cur]+2);
            fail[tt]=nxt[get_fail(fail[cur])][ch];
            nxt[cur][ch]=tt;
            num[tt]=num[fail[tt]]+1;
        }
        last=nxt[cur][ch];
    }
}pam;
void sol() {
    char c;
    int ans=0;
    while(cin>>c){
        c=(c-97+ans)%(26)+97;
        pam.insert(c-'a');
        ans=pam.num[pam.last];
        cout<<ans<<' ';
    }
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