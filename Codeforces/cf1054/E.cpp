#include <bits/stdc++.h>
using namespace std;
/*


    枚举左端点，然后分别记录一下每一个左端点对应的最左和最右符合点就可以


*/

using LL=long long ;

void sol(){
    LL n,k,b,c;
    cin>>n>>k>>b>>c;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
   
    LL lim1=1,lim2=1,ans=0,cpy=0;
    LL cnt=0;
    map<LL,LL> mp,cp;
    
    for(int l=1;l<=n;l++){
        while(lim1<=n&&ans<k){
            if(++mp[a[lim1++]]==1){
                ans++;
            }
        }//最后是第一个满足条件的位置下一位
        LL lim11=lim1-1;
        
        if(ans<k)  break;
        while(lim2<=n){
            if(cp[a[lim2]]==0&&cpy+1>k){
                break;
            }
            if(cp[a[lim2]]==0) cpy++;
            cp[a[lim2++]]++;
        }

        // cout<<"l="<<l<<'\n';
        // cout<<lim1<<" "<<lim2<<'\n';
        if(lim2-l<b||lim11-l+1>c){}
        else cnt+=(min(c,lim2-l)-max(b,lim11-l+1)+1);
        // cout<<cnt<<'\n';

        // else    cout<<min(c,lim2-l)<<" "<<max(b,lim1-l+1)<<'\n'; 
        // cout<<(min(c,lim2-l)-max(b,lim1-l+1))<<'\n';
        if(--mp[a[l]]==0){
            ans--;
        }
        if(--cp[a[l]]==0){
            cpy--;
        }
    }
    cout<<cnt<<'\n';
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
