#include <bits/stdc++.h>
using namespace std;
/*



*/
void sol() {
    int n,q;
    cin>>n>>q;
    vector<int> p(n+1,0),idx(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>p[i];
        idx[p[i]]=i;
    }
    while(q--){
        int lt,rt,k;
        cin>>lt>>rt>>k;
        if(idx[k]<lt||idx[k]>rt) cout<<"-1 ";
        else{
            int low=0,high=0,numlow,numhigh;
            numlow=numhigh=0;
            int remlow=k-1,remhigh=n-k;
            int l=lt,r=rt,mid;
            while(l<=r){
                mid=(l+r)>>1;
                if(p[mid]==k) break; 
                else if(mid<idx[k]){
                    l=mid+1;
                    if(p[mid]>k){
                        low++;
                        numhigh++;
                    }else remlow--;
                }else{
                    r=mid-1;
                    if(p[mid]<k){
                        high++;
                        numlow++;
                    }else remhigh--;
                }
            }
            if(low>remlow||high>remhigh) cout<<"-1 ";
            else{
                int extra=0;
                extra+=max(low-numlow,0);
                extra+=max(high-numhigh,0);
                cout<<low+high+extra<<" ";
            }

        }
    }
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