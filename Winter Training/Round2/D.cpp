#include <bits/stdc++.h>
using namespace std;
/*

    一段之后需要接上一段，然后变成一个回文串
    那么必然有一个对称轴，那么前缀的部分就是要添加的匹配的部分
    显然需要找到最长回文后缀
    有两种方法
    第一种是字符串哈希，正反做两次字符串哈希，枚举对称轴即可
    第二种是KMP，把字符串反过来，加上分隔符拼在一起，最长回文后缀显然就是这个字符串的最长boarder

*/
#define int long long 
const int base=1333331;

void sol() {
    int n;
    string s;
    cin>>n>>s;

    vector<int> pre(n+1,0),suf(n+2,0),p(n+1,0);
    s=' '+s;
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*base;
        pre[i]=pre[i-1]*base+s[i]-'a';
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]*base+s[i]-'a';
    }

    for(int i=1;i<=n;i++){
        int l,r;
        if((n-i+1)%2==0){
            l=(n+i)/2;
            r=(n+i)/2+1;
        }else{
            l=r=(n+i)/2;
        }
        int left=pre[l]-p[l-i+1]*pre[i-1];
        int right=suf[r]-p[n-r+1]*suf[n+1];
        if(left==right){
            cout<<i-1;
            return ;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}