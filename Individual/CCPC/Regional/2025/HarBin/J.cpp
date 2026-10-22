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
const int N=4e7+10;
int P[N];
double val[N],pre[N];
int mxidx,mxval,curidx,mxlen;
string tt,cpy;
void Manacher(const string&s,int*P){
    //R记录i位置的最长回文半径（不含自己），r是回文串最右侧再+1，最后的len是最长回文半径（不含自己）+1，每次通过取min更新len的时候，r-i的len是已知最长合法+1，R和0都是已知最长合法(不含自己)

    //模板中的R是在原串当中的最长回文直径
    int n=s.size();
    pre[0]=0;
    for(int i=1;i<n;i++) pre[i]=pre[i-1]+val[i];
    mxidx=0,mxval=0,mxlen=0;
    for(int i=0,r=0,len,c;i<n;i++){
        len=i<r?min(r-i,P[c*2-i]):0;
        int L=i-len,R=i+len;
        if(len>=3){ 
            if(L+3==0&&ceil(pre[R-3])==pre[R-3]&&pre[R-3]>mxval){
                mxidx=L+3,mxval=pre[R-3],mxlen=2*(len-3)+1;
            }else if(L+3&&(ceil(pre[R-3]-pre[L+2])==(pre[R-3]-pre[L+2]))&&pre[R-3]-pre[L+2]>mxval){
                mxidx=L+3,mxval=pre[R-3]-pre[L+2],mxlen=2*(len-3)+1;
            }
        }
        if(len>=1){
            if(L+1==0&&ceil(pre[R-1])==pre[R-1]&&pre[R-1]>mxval){
                mxidx=L+1,mxval=pre[R-1],mxlen=2*(len-1)+1;
            }else if(L+1&&(ceil(pre[R-1]-pre[L])==(pre[R-1]-pre[L]))&&pre[R-1]-pre[L]>mxval){
                mxidx=L+1,mxval=pre[R-1]-pre[L],mxlen=2*(len-1)+1;
            }
        }
        while(i-len>=0&&i+len<n&&s[i-len]==s[i+len]){
            L=i-len,R=i+len;
            if(L==0&&ceil(pre[R])==pre[R]&&pre[R]>mxval){
                mxidx=L,mxval=pre[R],mxlen=2*len+1;
            }else if(L&&(ceil(pre[R]-pre[L-1])==(pre[R]-pre[L-1]))&&pre[R]-pre[L-1]>mxval){
                mxidx=L,mxval=pre[R]-pre[L-1],mxlen=2*len+1;
            }
            len++;
        }
        P[i]=len-1;
        if(i+len>r){
            r=i+len;
            c=i;
        }
    }
    for(int i=0;i<mxlen;i++){
        if(s[i+mxidx]=='#') continue;
        if(val[i+mxidx]==0.5){
            cout<<"w";
            i+=2;
        }
        else cout<<s[i+mxidx];
    }
    cout<<'\n';
}
void sol() {
    int n;cin>>n;
    cin>>tt;
    cpy="#";
    curidx=0;  
    for(int i=0;i<n;i++){
        if(tt[i]!='w'){
            cpy.push_back(tt[i]);
            cpy.push_back('#');
            val[++curidx]=1,val[++curidx]=0;
        }else {
            cpy.push_back('v');
            cpy.push_back('#');
            cpy.push_back('v');
            cpy.push_back('#');
            val[++curidx]=0.5,val[++curidx]=0;
            val[++curidx]=0.5,val[++curidx]=0;
        }
    }
    Manacher(cpy,P);
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