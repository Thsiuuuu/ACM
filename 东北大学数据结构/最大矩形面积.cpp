#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

const int maxn=1e5+10;
int stk[maxn];
int r=0;

signed main(){

    int n;
   	cin>>n;
    vector<int> number(n);
    for(int i=0;i<n;i++) cin>>number[i];
    int ans=0,cur,left;
    for(int i=0;i<n;i++){
        while(r>0&&number[stk[r-1]]>=number[i]){
            cur=stk[--r];
            left=r==0?-1:stk[r-1];
            ans=max(ans,number[cur]*(i-left-1));
        }
        stk[r++]=i;
    }
    while(r>0){
        cur=stk[--r];
        left=r==0?-1:stk[r-1];
        ans=max(ans,(n-left-1)*number[cur]);
    }
    cout<<ans;
    return 0;

}