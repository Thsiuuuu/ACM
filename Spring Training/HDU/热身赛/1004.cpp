#include <bits/stdc++.h>
using namespace std;
/*



*/
#define ll long long 

const int N=2e5+2;
int nxt[N][11];

int prime[32]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};

void sol() {
    int n;
    cin>>n;
    vector<int> a(2*n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n;i++){
        for(int j=0;j<=10;j++){
            nxt[i][j]=-1;
        }
    }
    vector<int> p(11,-1);
    for(int i=2*n;i>=1;i--){
        for(int j=1;j<=a[i];j++) p[j]=i;
        for(int j=1;j<=10;j++) nxt[i][j]=p[j];
    }

    int ans=0;
    for(int st=1;st<=n;st++){
        int cur=st,i=0,sum=0;
        // cout<<i<<"\n";
        while(i<30&&cur<st+n){
            // cout<<cur<<' ';
            int del=prime[i+1]-prime[i];
            if(nxt[cur][del]==-1||nxt[cur][del]-st>n-1) break;
            else{
                while(i<30&&prime[i+1]<=sum+a[nxt[cur][del]]){
                    ans=max(ans,prime[i+1]);
                    i++;
                }
                cur=nxt[cur][del]+1;
                sum=prime[i];
            }     
        }
        // cout<<'\n';
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=10;j++){
    //         cout<<i<<' '<<j<<' '<<nxt[i][j]<<'\n';
    //     }
    // }
    reverse(a.begin()+1,a.begin()+n+1);
    reverse(a.begin()+n+1,a.end());
    for(int i=0;i<=10;i++) p[i]=-1;
    for(int i=1;i<=2*n;i++){
        for(int j=0;j<=10;j++) nxt[i][j]=-1;
    }
    for(int i=2*n;i>=1;i--){
        for(int j=1;j<=a[i];j++) p[j]=i;
        for(int j=1;j<=10;j++) nxt[i][j]=p[j];
    }
    for(int st=1;st<=n;st++){
        int cur=st,i=0,sum=0;
        while(i<30&&cur<st+n){
            int del=prime[i+1]-prime[i];
            if(nxt[cur][del]==-1||nxt[cur][del]-st>n-1) break;
            else{
                while(i<30&&prime[i+1]<=sum+a[nxt[cur][del]]){
                    ans=max(ans,prime[i+1]);
                    i++;
                }
                cur=nxt[cur][del]+1;
                sum=prime[i];
            }     
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