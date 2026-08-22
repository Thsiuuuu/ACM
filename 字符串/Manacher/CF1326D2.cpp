#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long

const int N=2e6+10;
int r1[N<<1],r2[N<<1];

int Manacher(const string&t,int*R){
    //R记录i位置的最长回文半径（不含自己），r是回文串最右侧再+1，最后的len是最长回文半径（不含自己）+1，每次通过取min更新len的时候，r-i的len是已知最长合法+1，R和0都是已知最长合法(不含自己)
    string s="#";
    for(auto c:t) s+=c,s+='#';
    int n=s.size();
    int ans=0;
    for(int i=0,r=0,len,c;i<n;i++){
        len=i<r?min(r-i,R[c*2-i]):0;
        while(i-len>=0&&i+len<n&&s[i-len]==s[i+len]) len++;
        R[i]=len-1;
        if(i==R[i]) ans=max(ans,R[i]);
        if(i+len>r){
            r=i+len;
            c=i;
        }
    }
    return ans;
}
void sol() {
    string s,t;cin>>s;t=s;reverse(t.begin(),t.end());   
    for(int i=0;i<2*s.size()+5;i++){
        r1[i]=r2[i]=0;
    }
    int st,rem;
    for(int i=0;2*(i+1)<=s.size();i++){
        st=i;
        if(s[i]!=t[i]) break; 
    }
    st--;rem=s.size()-2*(st+1);

    // cout<<st<<" "<<rem<<'\n';
    if(rem<=1){cout<<s<<'\n';return;}
    string ns=s.substr(st+1,rem),nt=ns;reverse(nt.begin(),nt.end());
    int l1=Manacher(ns,r1);
    int l2=Manacher(nt,r2);
    string tmp;
    if(l1>=l2) tmp=ns.substr(0,l1);
    else{ tmp=nt.substr(0,l2);reverse(tmp.begin(),tmp.end());}
    cout<<s.substr(0,st+1);
    cout<<tmp;
    cout<<s.substr(s.size()-st-1,st+1);
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}