#include <bits/stdc++.h>
using namespace std;
/*

    式子写出来，等价于外层是枚举坐标，内层是每个行的mex
    可以用贡献法，考虑一个mex有几种情况分别出现了几次，本质上就是交换了枚举的顺序，变为先枚举mex，然后考虑每个坐标对他的mex值的影响

*/
#define ll long long 
#define pii pair<int,int>

void sol() {
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    vector<pii> mex(n,{-1,-1});
    vector<map<int,int>> mp(n);
    map<int,int> cnt;//唐氏错误，卡一个n的vector长度是O(n)的
    int all=0;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        all+=l;
        a[i].assign(l,0);
        set<int> st;
        for(int j=0;j<l;j++){
            cin>>a[i][j];
            st.insert(a[i][j]);
            mp[i][a[i][j]]++;
            cnt[a[i][j]]++;
        }
    
        for(int j=0;j<=l+2;j++){
            if(st.find(j)==st.end()){
                if(mex[i].first==-1){
                    mex[i].first=j;
                }else if(mex[i].second==-1){
                    mex[i].second=j;
                    break;
                }
            }
        }
    }

    ll ans=0;
    for(int i=0;i<n;i++){
        int ma,mb;
        ma=mex[i].first,mb=mex[i].second;
        ans+=((n-2)*(all-a[i].size())*ma);
        ans+=((ll)mb*(cnt[ma]-mp[i][ma])+(ll)ma*(all-a[i].size()-(cnt[ma]-mp[i][ma])));
        for(int j=0;j<a[i].size();j++){
            ans+=((n-1)*((a[i][j]<ma&&mp[i][a[i][j]]==1)?a[i][j]:ma));
        }
    }
    cout<<ans<<'\n';
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