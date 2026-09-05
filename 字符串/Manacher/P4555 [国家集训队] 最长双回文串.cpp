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
const int N=2e5+10;
int R[N],ls[N],rs[N];
void Manacher(string&t,int*R){
    //R记录i位置的最长回文半径（不含自己），r是回文串最右侧再+1，最后的len是最长回文半径（不含自己）+1，每次通过取min更新len的时候，r-i的len是已知最长合法+1，R和0都是已知最长合法(不含自己)

    //模板中的R是在原串当中的最长回文直径
    string s="#";
    for(auto c:t) s+=c,s+='#';
    int n=s.size();
    for(int i=0,r=0,len,c;i<n;i++){
        len=i<r?min(r-i,R[c*2-i]):0;
        while(i-len>=0&&i+len<n&&s[i-len]==s[i+len]) len++;
        R[i]=len-1;
        ls[i-R[i]]=max(ls[i-R[i]],R[i]);
        rs[i+R[i]]=max(rs[i+R[i]],R[i]);
        if(i+len>r){
            r=i+len;
            c=i;
        }
    }
    for(int i=0;i<n;i++){
        if(i-2>=0) ls[i]=max(ls[i],ls[i-2]-2);
    }
    for(int i=n-1;i>=0;i--){
        if(i+2<n) rs[i]=max(rs[i],rs[i+2]-2);
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        if(s[i]=='#')  ans=max(ans,ls[i]+rs[i]);
    }
    cout<<ans;
}
void sol() {
    string s;cin>>s;
    Manacher(s,R);
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