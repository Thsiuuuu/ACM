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
/*
多测清空，long long ，是否对需要修改的变量赋值了
想不出来注意换思路
注意数据范围，枚举答案是否可行
*/
const int N=54;
int ff[N],ss[N],lbt[N],cnt[N][N],n,p[N],vis[N];
int f1[N],s1[N],lbt1[N],cnt1[N][N];
int small(char x){
    return x-'a';
}
int big(char x){
    return 26+x-'A';
}
int dis(char x){
    if(x>='a'&&x<='z') return small(x);
    else return big(x);
}
bool ck(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cnt[i][j]!=cnt1[p[i]][p[j]]){
                return false;
            }
        }
    }
    return true;
}
bool dfs(int number){
    if(number==n){
        if(ck()){
            for(int i=0;i<n;i++) cout<<((p[i]<26)?(char)(p[i]+'a'):(char)('A'+p[i]-26));
            cout<<'\n';
            return true; 
        }
        return false;
    }
    for(int i=0;i<n;i++){
        if(vis[i]||f1[i]!=ff[number]||s1[i]!=ss[number]||lbt1[i]!=lbt[number]) continue;
        p[number]=i;
        vis[i]=1;
        bool is=dfs(number+1);
        if(is) return is;
        vis[i]=0;
    }
    return false;
}
void sol() {
    cin>>n;
    for(int i=0;i<n;i++){
        ff[i]=ss[i]=lbt[i]=0;
        f1[i]=s1[i]=lbt1[i]=0;
        p[i]=0;
        vis[i]=0;
        for(int j=0;j<n;j++) cnt1[i][j]=cnt[i][j]=0;
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        int x=i*j;
        if(x<n){
            lbt[x]++;
        }else{
            ss[x/n]++;
            ff[x%n]++;
            cnt[x/n][x%n]++;
        }
    }
    for(int i=0;i<n*n;i++){
        string s;cin>>s;
        if(s.size()==1) lbt1[dis(s[0])]++;
        else f1[dis(s[1])]++,s1[dis(s[0])]++,cnt1[dis(s[0])][dis(s[1])]++;
    }
    dfs(0);
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