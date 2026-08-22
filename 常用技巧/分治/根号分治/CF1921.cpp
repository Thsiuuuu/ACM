#include <bits/stdc++.h>
using namespace std;
/*

    依旧根号分治，首先如果d>sqrt(n)，那么直接暴力查就可以时间复杂度O(sqrt(n))
    如果d<=sqrt(n)，这个式子无法通过简单的后缀和进行维护，但是是\sum i*a[i]的形式，所以可以通过做两次后缀和

    不妨令s1[i][d],s2[i][d]，分别表示第一次和第二次的后缀和
    第一次维护原始数组的后缀和，第二次对第一次的后缀和再求一次后缀和，相当于
    a1+a3+a5+a7+...
       a3+a5+a7+...
          a5+a7+...
    类似于如上原理，我们可以通过对后缀和再求一次后缀和就可以得到\sum i*a[i]，
    然后求某一段的和的时候，只需要
    s2[i][d]-s2[i+k*d][d]-k*s1[i+k*d][d]
    即可，前两项运算完相当于要求的区间和加上k倍的多余的后缀和，用i+k*d位置的后缀和*k减去就可以得到区间和
    

*/

const int N=1e5+4;
#define int long long 
int s1[N][320],s2[N][320];

void sol() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int block=sqrt(n);
    
    for(int i=n;i>=1;i--){
        for(int d=1;d<=block;d++){
            s1[i][d]=a[i];
            if(i+d<=n){
                s1[i][d]+=s1[i+d][d];
            }
        }
    }

    for(int i=n;i>=1;i--){
        for(int d=1;d<=block;d++){
            s2[i][d]=s1[i][d];
            if(i+d<=n){
                s2[i][d]+=s2[i+d][d];
            }
        }
    }

    while(q--){
        int s,d,k;
        cin>>s>>d>>k;
        int sum=0;
        if(d>block){
            for(int i=s;i<=n&&((i-s+d)/d<=k);i+=d){
                sum+=a[i]*(i-s+d)/d;
            }
        }else{
            sum=s2[s][d];
            if(s+k*d<=n){
                sum-=(s2[s+k*d][d]+k*s1[s+k*d][d]);
            }
        }
        cout<<sum<<" ";
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}