#include <bits/stdc++.h>
using namespace std;
/*

    有点像线性基?

*/
#define ll long long 
#define pii pair<int,int>
#define double long double
#define pll pair<ll,ll>
#define i128 __int128_t
#define ull unsigned long long  


struct node{
    ll num,len=0;
    bool operator<(const node&other)const{
        if(len==other.len) return num<other.num;
        return len>other.len;
    }
};

void dfs(ll mul,ll &step){
    if(mul<10) return ;
    else{
        step++;
        ll cur=1;
        string s=to_string(mul);
        for(int i=0;i<s.size();i++) cur*=(s[i]-'0');
        dfs(cur,step);
    }
}

void sol() {
    ll a,b;cin>>a>>b;
    vector<node> ans(b-a+1);
    for(int x=a;x<=b;x++){
        ans[x-a].num=x;
        dfs(x,ans[x-a].len);
    }    
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        int j=0;
        cout<<ans[i].len<<'\n';
        while(j<ans.size()&&ans[j].len==ans[i].len){
            if(j!=0) cout<<" ";
            cout<<ans[j].num;
            j++;
        }
        break;
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