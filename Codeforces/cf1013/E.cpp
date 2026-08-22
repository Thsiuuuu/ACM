#include <bits/stdc++.h>
using namespace std;
/*

    对lcm进行转化
    是ab/(gcd^2)
    因为是质数，所以说至少一个数/gcd为1，又因为a小，所以a=gcd(a,b)
    并且只有a/gcd=1
    两种方法：
    1.枚举a，用双指针维护
    2.枚举每一个质数y，每次加上n/y

*/

#define ll long long 
void sol() {
    int n;
    cin>>n;

    vector<bool> visit(n+1,false);
    vector<int> prime;
    for(int i=2;i<=n;i++){
        if(!visit[i]){
            prime.push_back(i);
        }
        for(int j=0;j<prime.size();j++){
            if((long long)i*prime[j]>n){
                break;
            }
            visit[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }

    ll ans=0;
    for(int l=1,r=prime.size()-1;l<n;l++){
        while(r>=0&&l*prime[r]>n){
            r--;
        }
        if(r>=0){
            ans+=(r+1);
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