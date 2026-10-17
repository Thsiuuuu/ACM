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
void Z_function(const string&s,vector<int>&z){
    int n=(int)s.size();
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r&&z[i-l]<r-i+1){
            z[i]=z[i-l];
        }else{
            z[i]=max(0,r-i+1);
            while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) ++z[i];
        }
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
}
void Manacher(const string&s,vector<int>&d1){
    int n=s.size();
    d1.resize(n);
    //l,r分别表示最右回文串的左右端点（恰好属于回文串边界）
    //d1奇数长度回文半径(含上中心是奇数，不含是偶数),d2是把自己的一半偏右为中心，半径是一半 
    //回文串长度2*d1[i]-1,2*d2[i],区间[i-d1[i]+1,i+d1[i]-1],[i-d2[i],i+d2[i]-1]
    for(int i=0,l=0,r=-1;i<n;i++){
        int k=(i>r)?1:min(d1[l+r-i],r-i+1);//找到对称点位置
        while(i-k>=0&&i+k<n&&s[i-k]==s[i+k]) k++;
        d1[i]=k--;//换算成偏移量
        if(i+k>r){
            l=i-k;r=i+k;
        }
    }
}
void sol() {
    string s;cin>>s;
    int n=s.size();
    ll ans=0;
    VI d1,z(n);
    Manacher(s,d1);
    Z_function(s,z);
    auto getlen=[&](int m){
        if(m==0){
            return n==1?1:z[1]+1;
        }
        if(d1[m]<(m+1)) return m+d1[m];
        return 2*m+z[2*m];
    };
    int m=0;
    for(int i=0;i<n;i++){
        while(getlen(m)<i+1) m++;
        ans^=(1ll*(m+1)*(i+1));
    }
    cout<<ans<<'\n';
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