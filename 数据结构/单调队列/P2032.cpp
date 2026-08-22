#include <bits/stdc++.h>
using namespace std;
#define int long long 

/*

    单调队列板子题

*/
const int N=2e6+10;
int que[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int head=0,tail=-1;
    for(int i=1;i<=k-1;i++){
        while(head<=tail&&a[que[tail]]<=a[i]) tail--;
        que[++tail]=i;
    }
    for(int i=k;i<=n;i++){
        while(head<=tail&&a[que[tail]]<=a[i]) tail--;
        que[++tail]=i;
        while(head<=tail&&que[head]<i-k+1) head++;
        cout<<a[que[head]]<<'\n';
    }
    return 0;
}