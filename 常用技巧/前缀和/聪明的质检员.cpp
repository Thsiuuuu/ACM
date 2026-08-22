#include <iostream>

using namespace std;

#define int long long 


const int maxn=2e6+10,tp=2e18;
int m,s,n,ans=tp;
int op[maxn][3],val[maxn],wgt[maxn],sum1[maxn],sum2[maxn];




bool check(int w){

    memset(sum1,0,sizeof(sum1));
    memset(sum2,0,sizeof(sum2));
    for(int i=1;i<=n;i++){
        if(wgt[i]>=w){
            sum1[i]=sum1[i-1]+1,sum2[i]=sum2[i-1]+val[i];
        }else{
            sum1[i]=sum1[i-1],sum2[i]=sum2[i-1];
        }
    }

    int all=0;
    for(int i=1;i<=m;i++){
        all+=(sum1[op[i][2]]-sum1[op[i][1]-1])*(sum2[op[i][2]]-sum2[op[i][1]-1]);
    }
    ans=min(abs(all-s),ans);
    return all<s;
}


signed main(){

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>m>>s;

    for(int i=1;i<=n;i++){
        cin>>wgt[i]>>val[i];
    }
    for(int i=1;i<=m;i++){
        cin>>op[i][1]>>op[i][2];
    }

    int l=0,r=tp;
    while(l<=r){
        int mid=(r-l)/2+l;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;

}