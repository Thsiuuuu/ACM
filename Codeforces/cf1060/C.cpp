#include <bits/stdc++.h>
using namespace std;
#define int long long  

/*


    最开始卡了很久，然后突然想到如果都是偶数，那么代价是0
    因为要gcd>1，那么可以从gcd为2入手
    如果都是偶数，代价是0
    对于剩下的情况，我们可以对每个数的质因子开一个桶，判断是否一个质因子在所有的数中至少出现了2次，如果是，那么就说明它们其中有两个数是有公因子在的
    如果不是的话，
    首先有奇有偶，那么代价就是1
    如果都是奇数，那么最多花费2，就是把两个奇数变成偶数，也有可能花费1的代价，就是一个数+1之后导致其中有些因子的频数+1>2。
    这里的判断利用了相邻数一定互质的性质，所以说+1之后并不需要删掉原有的质因子在桶中出现的频率。
    对每个数分解质因数的时间复杂度是O(n^(0.5))
    总的时间复杂度是O(n*n^(0.5))

*/

void sol(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    vector<int> num(2e5+2,0);
    bool f1=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int cpy=a[i];
        for(int j=2;j*j<=cpy;j++){
            if(cpy%j==0){
                num[j]++;
                if(num[j]>=2){
                    f1=true;
                }
                while(cpy%j==0){
                    cpy/=j;
                }
            }
        }
        if(cpy>1) num[cpy]++;
        if(num[cpy]>1) f1=true;
    }
    for(int i=1;i<=n;i++) cin>>b[i];

    if(f1){
        cout<<"0\n";
        return ;
    }
    for(int i=1;i<=n;i++){
        int cpy=a[i]+1;
        for(int j=2;j*j<=cpy;j++){
            if(cpy%j==0){
                if(num[j]>=1){
                    cout<<"1\n";
                    return ;
                }
                while(cpy%j==0){
                    cpy/=j;
                }
            }
        }
        if(cpy>1&&num[cpy]>=1){
            cout<<"1\n";
            return ;
        }
    }
    cout<<"2\n";
    
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
}