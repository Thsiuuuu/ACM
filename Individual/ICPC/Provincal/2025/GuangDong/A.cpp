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
int n,m,a,b;
const int N=1e6+10,M=(1<<10)+12;
VL p[M],all[M];
int mp[N][11]; 
void sol() {
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x;cin>>x;mp[i][j]=x-'0';
        }
    }
    for(int i=1;i<=n;i++){
        int mask=0;
        ll w=0;
        for(int j=m;j>=1;j--){
            mask=(mask<<1)|mp[i][j];
            w+=mp[i][j]*1ll*j;
        }
        all[mask].push_back(i);
        ll cnt=__builtin_popcount(mask);
        p[mask].push_back(i);
    }
    for(int mask=0;mask<(1<<m);mask++){
        for(int i=1;i<p[mask].size();i++) p[mask][i]+=p[mask][i-1];
    }
    ll res=INT64_MIN;
    for(int mask=0;mask<(1<<m);mask++){
        ll tmp=0;
        for(int other=0;other<(1<<m);other++){
            if(all[other].size()==0) continue;
            int tot=mask^other;
            int l=0,r=(int)all[other].size()-1,mid,ans=-1;
            ll cnt=__builtin_popcount(tot),sum=0;
            for(int j=1;j<=m;j++) sum+=((tot>>(j-1)&1)*1ll*j);
            while(l<=r){
                mid=(l+r)>>1;
                ll cur=(2*cnt-m)*a*all[other][mid]+b*(2*sum-m*(m+1)/2);
                if(cur<=0){
                    if((2*cnt-m)*a<=0) r=mid-1;
                    else l=mid+1,ans=mid;
                }else{
                    if((2*cnt-m)*a>0) r=mid-1;
                    else l=mid+1,ans=mid;
                }
            }
            if(ans==-1){
                if((2*cnt-m)*a>0) tmp+=cnt*a*p[other].back()+b*sum*p[other].size();
                else tmp+=(m-cnt)*a*p[other].back()+b*(m*(m+1)/2-sum)*((ll)p[other].size());
            }
            else{
                if((2*cnt-m)*a>0)  tmp+=(m-cnt)*a*p[other][ans]+b*(m*(m+1)/2-sum)*(ans+1)+cnt*a*(p[other].back()-p[other][ans])+b*sum*((ll)p[other].size()-1-ans);
                else tmp+=cnt*a*p[other][ans]+b*sum*(ans+1)+(m-cnt)*a*(p[other].back()-p[other][ans])+b*(m*(m+1)/2-sum)*((ll)p[other].size()-1-ans);
            }
        }
        res=max(res,tmp);
    }
    cout<<res;
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