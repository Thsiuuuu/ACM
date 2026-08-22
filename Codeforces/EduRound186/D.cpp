#include <bits/stdc++.h>
using namespace std;
#define int  long long 
const int mod=998244353;
vector<int> fb(51);
vector<vector<int>> c(51,vector<int>(51));


void init(){
    fb[0]=fb[1]=1;
    for(int i=0;i<=50;i++){
        if(i==0||i==1) fb[i]=1;
        else fb[i]=(i*fb[i-1])%mod;
        for(int j=0;j<=i;j++){
            if(j==0) c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}


/*

    尽可能的抹平
    比赛时候代码有两处错误，第一处是如果还剩下很多的话，是一层一层涂的，要取模
    第二处是写阶乘只写了角标......
    算是新年的第一题了。
    记于2026.01.01 1：57
*/
void sol() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.end(),greater<int>());
    int mx=a[1];
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=((mx-1-a[i])*(a[i]!=mx));
    }
    // cout<<"sum "<<sum<<'\n';
    if(n==1){
        cout<<"1\n";
    }else if(sum>a[0]){
        cout<<"0\n";
    }else{
        int cnt2=0,cnt1=0;
        for(int i=1;i<=n;i++){
            if(a[i]<mx){
                cnt2++;
                a[0]-=(mx-1-a[i]);
                a[i]=mx-1;
            }else cnt1++;
        }
        // cout<<cnt1<<" "<<cnt2<<" "<<a[0]<<'\n';
        if(cnt2>a[0]){
            cout<<((c[cnt2][a[0]])*((fb[cnt1+a[0]])%mod)%mod)*((fb[cnt2-a[0]]+mod)%mod)%mod<<'\n';
        }else{
            a[0]=(a[0]-cnt2+n)%n;
            cout<<((c[n][a[0]])*(fb[a[0]])%mod)*(fb[n-a[0]])%mod<<'\n';
        }
    }
}   

signed  main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}