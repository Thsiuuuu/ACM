#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define ll long long 
#define i128 __int128_t
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
int  check(const string&s,const string&a){
    int res=0;
    int top=0;
    for(int i=0;i<s.size();i++){
        if(a[i]=='1') continue;
        else{
            if(s[i]=='(') top++;
            else if(s[i]==')'&&top) top--,res++;
        }
    }
    return res;
}
void sol() {
    int n,k;
    cin>>n>>k;
    int l,r;
    string s,ans(n,'0');cin>>s;
    int num;
    l=0,r=n-1;
    while(l<n&&s[l]==')'){
        l++;
    }
    while(r>=0&&s[r]=='('){
        r--;
    }
    if(l==n||r==0){
        cout<<ans<<'\n';
        return ;
    }
    string t;
    for(num=0;num<=k;num++){
        t.assign(n,'0');
        int lc=num,rc=k-num;
        for(int i=0;i<n&&lc;i++){
            if(s[i]=='(') lc--,t[i]='1';
        }
        for(int i=n-1;i>=0&&rc;i--){
            if(s[i]==')') rc--,t[i]='1';
        }
        if(check(s,t)<check(s,ans)) ans=t;
    }
    // int cur=0;
    // for(int i=r;i>=l;i--){
    //     if(s[i]==')') cur++;
    //     else if(s[i]=='('&&cur>0) cur--;
    // }
    // if(cur>0){
    //     for(int i=l;i<=r&&num>0;i++){
    //         if(s[i]=='(') ans[i]='1',num--;
    //     }
    // }else{
    //     for(int i=r;i>=l&&num>0;i--){
    //         if(s[i]==')') ans[i]='1',num--;
    //     }
    // }
    // cout<<cur;
    
    // int L=l,R=r;
    // string ho(n,'0');
    // num=k;
    // while(L<=R&&num>0){
    //     // cout<<L<<" "<<R<<" "<<num<<'\n';
    //     if(s[L]=='('&&s[R]==')'){
    //         if(num>=2){
    //             num-=2;
    //             ho[L]='1',ho[R]='1';
    //             L++,R--;
    //         }else{
    //             num--;
    //             cur=0;
    //             for(int i=R;i>=L;i--){
    //                 if(s[i]==')') cur++;
    //                 else if(s[i]=='('&&cur>0) cur--;
    //             }
    //             if(cur>0) ho[L]='1';
    //             else ho[R]='1';
    //         }
    //     }else if(s[L]!='(') L++;
    //     else if(s[R]!=')') R--;
    // }
    // // cout<<ho<<'\n';
    // // cout<<ans<<'\n';
    // if(check(s,ho)<check(s,ans)) ans=ho;
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