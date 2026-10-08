#include <bits/stdc++.h>
using namespace std;
/*
      /\_/\
     ( =o.o= ) *
      / >  \>
*/
#define int long long 
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
// const ll INF=1e9;
void sol() {
    ll n,m,k,w;cin>>n>>m>>k>>w;
    vector<pii> all;
    VI a(n),b(m);
    all.push_back({0,0});
    for(int i=0;i<n;i++){
        cin>>a[i];
        all.push_back({a[i],1});
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        all.push_back({b[i],0});
    }
    all.push_back({w+1,0});
    sort(all.begin(),all.end(),[&](const pii&A,const pii&B)->bool{
        return A.first<B.first;
    });
    int last=0;
    VI ans;
    // int cnt=0;
    for(int i=0;i+1<all.size();i++){
        if(all[i].second==0&&all[i+1].second==1){
            int nxt=0;
            VI ret,RR;
            int number=0,cur=0;
            for(int j=i+1;j<all.size()&&all[j].second==1;j++){
                if(cur<all[j].first){
                    ret.push_back(all[j].first);
                    RR.push_back(all[j].first+k-1);
                    number++;
                    cur=all[j].first+k-1;
                }//存新增的红色，然后微操
                if(nxt==0&&j+1<all.size()&&all[j+1].second==0) nxt=all[j+1].first;
            }
            if(RR.size()){
                RR.back()=min(RR.back(),nxt-1);
            }
            last=all[i].first;
            int len=nxt-last-1;//len间距,nxt右边黑色，last左边黑色，ret当前所有的红色起点,number所有红色起点的个数
            if(number==0) continue;
            if(len<k||number*k>len){
                cout<<"-1\n";
                return ;
            }
            if(cur<nxt){
                for(int x:ret) ans.push_back(x);
                continue;//当前右端点就在最右边黑色左侧
            }
            // cout<<last<<"!\n";
            int rem=cur-nxt+1;
            // cout<<rem<<'\n';
            //从右向左去微操
            for(int j=number-1;j>=0;j--){
                int L1=ret[j],R1=RR[j];
                int tmp1=k-(R1-L1+1);
                if(tmp1==0) continue;
                if(j){
                    int L0=ret[j-1],R0=RR[j-1];
                    if(R0>=L1-tmp1){
                        rem-=L1-R0-1;
                        R0=L1-tmp1-1;
                    }else{
                        rem-=(L1-tmp1);
                    }
                    L1-=tmp1;
                    RR[j-1]=R0;
                }else{
                    L1-=tmp1;
                }
                ret[j]=L1;
            }
            if(ret[0]<=last){
                cout<<"-1\n";
                return ;
            }
            for(int x:ret) ans.push_back(x);
        }
    }
    for(int i=1;i<ans.size();i++){
        if(ans[i]-ans[i-1]<k){
            cout<<"-1\n";
            return ;
        }
    }
    cout<<ans.size()<<'\n';
    for(int x:ans) cout<<x<<" ";
    cout<<'\n';
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