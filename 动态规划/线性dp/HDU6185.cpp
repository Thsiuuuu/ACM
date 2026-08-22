#include <bits/stdc++.h>
using namespace std;
/*

    通过找不可分割块，归纳出公式
    对f[n]和f[n-2]作差得出f[n]=f[n-1]+5f[n-2]+f[n-3]-f[n-4]
    直接进行转移会超时，所以要通过矩阵快速幂进行转移

*/
#define int long long  
const int mod=1e9+7;

struct Mat{
    int mat[4][4];
    Mat(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                mat[i][j]=0;
            }
        }
    }
    Mat operator*(const Mat&other)const{
        Mat res;
        for(int i=0;i<4;i++){
            for(int k=0;k<4;k++){
                if(mat[i][k]==0) continue;
                for(int j=0;j<4;j++){
                    res.mat[i][j]=(res.mat[i][j]+mat[i][k]*other.mat[k][j]%mod)%mod;
                }
            }
        }
        return res;
    }
};

Mat qmi(Mat a,int b){
    Mat res;
    res.mat[0][0]=res.mat[1][1]=res.mat[2][2]=res.mat[3][3]=1;

    while(b){
        if(b&1){
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}

int sol(int n) {
    if(n==1) return 1;
    if(n==2) return 5;
    if(n==3) return 11;
    Mat t;
    t.mat[0][0]=1,t.mat[0][1]=5,t.mat[0][2]=1,t.mat[0][3]=mod-1;
    t.mat[1][0]=1;
    t.mat[2][1]=1;
    t.mat[3][2]=1;
    Mat res=qmi(t,n-3);
    int ans=(res.mat[0][0]*(11ll)%mod+res.mat[0][1]*(5ll)%mod+res.mat[0][2]*(1ll)%mod+res.mat[0][3]*(1ll)%mod)%mod;
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // int t = 1;
    // cin >> t;
    int n;
    while (cin>>n) {
        cout<<sol(n)<<'\n';
    }
    return 0;
}