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
const int N=1e6+10;
int pre[3][N],x,y,f[N],dp[N][2];//pre0,pre1 元，辅,?前缀和
bool ckyuan(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
void sol(int id) {
    string s;cin>>s;
    int n=s.size();
    s=' '+s;
    cin>>x>>y;
    for(int i=1;i<s.size();i++){
        for(int j=0;j<=2;j++) pre[j][i]=pre[j][i-1];
        if(s[i]=='?'){
            pre[2][i]++;
            continue;
            
        }else if(ckyuan(s[i])){
            pre[0][i]+=1;
        }else{
            pre[1][i]+=1;
        }
    }
    bool is=true;
    for(int i=1;i<s.size();i++){
        if(i>=x&&pre[0][i]-pre[0][i-x]==x){
            is=false;
            break;
        }
        if(i>=y&&pre[1][i]-pre[1][i-y]==y){
            is=false;
            break;
        }
    }
    if(!is){
        cout<<"Case #"<<id<<": "<<"DISLIKE\n";
        return ;
    }
    if(pre[2][n]==0){
        cout<<"Case #"<<id<<": "<<"LIKE\n";
        return ;
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(s[i]=='?'||ckyuan(s[i])){
            f[i]++;
        }
        if(i>=x&&f[i]-f[i-x]==x){
            is=false;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1];
        if(s[i]=='?'||!ckyuan(s[i])){
            f[i]++;
        }
        if(i>=y&&f[i]-f[i-y]==y){
            is=false;
            break;
        }
    }
    bool i2=true;
    for(int i=1;i<=n;i++) dp[i][1]=dp[i][0]=1e9;
    for(int i=1;i<=n;i++){
        if(s[i]=='?'){
            dp[i][0]=((dp[i-1][1]>=y)?dp[i-1][0]+1:1);
            dp[i][1]=((dp[i-1][0]>=x)?dp[i-1][1]+1:1);
            if(dp[i][0]>=x&&dp[i][1]>=y){
                i2=false;
                break;
            }
        }else if(ckyuan(s[i])){
            dp[i][0]=((dp[i-1][1]>=y)?dp[i-1][0]+1:1);
            if(dp[i][0]==x){
                i2=false;
                break;
            }
        }else{
            dp[i][1]=((dp[i-1][0]>=x)?dp[i-1][1]+1:1);
            if(dp[i][1]==y){
                i2=false;
                break;
            }
        }
    }
    if(is) cout<<"Case #"<<id<<": "<<"LIKE\n";
    else{
        if(i2) cout<<"Case #"<<id<<": "<<"SURPRISE\n";
        else cout<<"Case #"<<id<<": "<<"DISLIKE\n";
    }
    // cout<<"Case #"<<id<<": "<<" ";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}