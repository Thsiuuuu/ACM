#include <bits/stdc++.h>
using namespace std;

/*

    对n=1而言，奇数是必胜态，偶数是必败态
    SG函数

    偶数的SG值一定是0，且sg[1]=1
    奇数的SG值是它的最小质因子在质数表当中的次序
    用线性筛处理

    快速用SG函数解决：
    1.写一个能算SG的朴素的方法
    2.观察前若干个值
    3.找规律，并采取一种更快的方法
    4.再更大的数字上进行验证，或进行证明
*/

const int N=1e7+1;
int sg[N];
bool visited[N];
int prime[N];
int cnt=1;

void init(){
    sg[0]=0,sg[1]=1;
    for(int i=2;i<=N;i++){
        if(!visited[i]){
            if(i==2) sg[i]=0;
            else{
                sg[i]=cnt;
            }
            prime[cnt++]=i;
        }
        for(int j=1;j<cnt;j++){
            if(i*prime[j]>N) break;
            visited[i*prime[j]]=true;
            sg[i*prime[j]]=sg[prime[j]];
            if(i%prime[j]==0){
                break;
            }
        }
    }
}


void sol(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int sum=0;
    for(int i=0;i<n;i++){
        sum^=sg[a[i]];
    }
    if(sum){
        cout<<"Alice\n";
    }else cout<<"Bob\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


    init();

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}