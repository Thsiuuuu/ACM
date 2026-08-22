#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define ll long long 
const int N=5e5+10;
ll a[N],st[N];
int bi[N],bl[2010],br[2010];
int n,q;
int blo,tot;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    blo=sqrt(n);
    tot=(n+blo-1)/blo;
    for(int i=1,cur=1,num=0;i<=n;i++){
        bi[i]=cur;
        if(num==0) bl[cur]=i;
        if(num==blo-1||i==n) br[cur]=i;
        if(num==blo-1){
            num=0;
            cur++;
        }else num++;
        
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st[i]=a[i];
    }
    for(int i=1;i<=tot;i++){
        sort(st+bl[i],st+br[i]+1);
    }
    cin>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==0){
            int l,r,c;
            cin>>l>>r>>c;
            int ans=0;
            if(bi[l]==bi[r]){
                for(int i=l;i<=r;i++) ans+=(a[i]>=c);
            }else{
                for(int i=l;i<=br[bi[l]];i++){
                    ans+=(a[i]>=c);
                }
                for(int i=bl[bi[r]];i<=r;i++){
                    ans+=(a[i]>=c);
                }
                for(int i=bi[l]+1;i<=bi[r]-1;i++){
                    ans+=(st+br[i]+1-lower_bound(st+bl[i],st+br[i]+1,c));
                }
            }
            cout<<ans<<'\n';
        }else{
            int idx,c;
            cin>>idx>>c;
            a[idx]=c;
            for(int i=bl[bi[idx]];i<=br[bi[idx]];i++){
                st[i]=a[i];
            }
            sort(st+bl[bi[idx]],st+br[bi[idx]]+1);
        }
    }
    return 0;
}