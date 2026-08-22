#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e3+10;

int x[N],y[N];

/*

    题目来源：2022ICPC南京M
    一道好题
    首先只有一个凹下去的形状才可能对答案产生贡献
    假设边界情况是上一条边向下，但是下一条边水平，那么只需要下一条边稍微向下倾斜，就是一个凹下去的东西。
    这种在几何上可以用向量表示，就是前一个向量y<0，后一个向量y>0
    然后这种凹下去的可以分为两种情况，第一种是有尖的，第二种是走一段直线再回去的。
    因为是逆时针
    对于第一种有尖的，仍分为两种情况，在图形上半部分和下半部分，直观可以发现
        下半部分的前后向量总是逆时针旋转，而上半部分的前后向量是顺时针旋转
    对于第二种水平的，仍分为两种情况，在图形上半部分和下半部分
        下半部分的水平线是x递增的，而上半部分是x递减的

    先想一想什么时候可以，然后不行的和行的区别在哪里
*/

int cross(int ax,int ay,int bx,int by){
    return ax*by-ay*bx;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0,j=1;i<n;i++){
        while(y[i]==y[j]) j=(j+1)%n;
        int pre=(i+n-1)%n;
        if(y[i]<y[pre]&&y[i]<y[j]){
            if(y[i]^y[(i+1)%n]){
                if(cross(x[i]-x[pre],y[i]-y[pre],x[j]-x[i],y[j]-y[i])>0) ans++;
            }else if(x[i]<x[(i+1)%n]) ans++;
        }
    }
    cout<<ans;
    return 0;
}