#include <bits/stdc++.h>
using namespace std;

struct node{
    string s=" ";
    int len;
    bool operator<(const node&others)const{
        return s<others.s;
    }
};
void sol(){
    int n;
    cin>>n;
    vector<node> st(n+1);
    int mx=-1;
    for(int i=1;i<=n;i++){
        int k,x;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x;
            st[i].s=st[i].s+(char)('0'+x);
        }
        st[i].len=k;
        mx=max(k,mx);
    }

    for(int i=1;i<=n;i++){
        for(int j=mx;j>st[i].len;j--){
            st[i].s+='0';
        }
    }
    // for(const auto&[s,len]:st){
    //     cout<<s<<'\n';
    // }
    sort(st.begin()+1,st.end());
    int nx=1;
    for(int i=1;i<=n;i++){
        while(nx<=st[i].len){
            cout<<st[i].s[nx]<<" ";
            nx++;
        }
    }
    cout<<'\n';

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}