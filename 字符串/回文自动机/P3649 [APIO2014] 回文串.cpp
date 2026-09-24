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
const int maxn=3e5+10;
struct Palindromic_AutoMaton{
    int num[maxn];
    int s[maxn];//把字符串存到了1-base的s里面
    //tot最新节点编号,now下一个准备写入的字符串s的下标
    int nxt[maxn][26],fail[maxn],len[maxn],last,tot,now;
    void clear(){
        fail[0]=tot=now=1;
        last=len[0]=0;
        len[1]=s[0]=-1;
        memset(nxt[0],0,sizeof(nxt[0]));
        memset(nxt[1],0,sizeof(nxt[1]));
    }
    Palindromic_AutoMaton(){clear();}
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
        }
        last=nxt[cur][ch];
        num[last]++;
    }
    void build(){
        for(int i=tot;i>=2;i--){
            num[fail[i]]+=num[i];
        }
        num[0]=num[1]=0;
    }
}pam;
void sol() {
    string  s;cin>>s;
    for(int i=0;i<s.size();i++){
        pam.insert(s[i]-'a');
    }
    pam.build();
    ll ans=0;
    for(int i=2;i<=pam.tot;i++){
        ans=max(ans,1ll*pam.len[i]*pam.num[i]);
    }
    cout<<ans;
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