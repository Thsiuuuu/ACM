#include <bits/stdc++.h>
using namespace std;
/*

    简单的分类讨论一下
    这里仅讨论x<floor(n/2)的情况
    x位置之前的点，一定不会放到x位置之后，所以说只需要考虑[x,n]这一段的情况
    很显然，能够和x交换的一定是x的倍数，以此类推，每一个位置上都应该是x的倍数
    那么n需要找位置放，如果把每一位都放到前面的位置上，总会剩下一位，就需要放n
    所以说n一定是x的倍数

    接下来怎么构造最小字典序卡了很久
    考虑对n/x进行质因数分解，那么可以分解成若干的素数，也就是说，
    从前向后，不断的向x放置x乘以这些素数的结果
    所以说从小到大每次把x位置放上x乘以当前最小的素数，就可以，这样能够保证每次变化一定是当前最小的


*/
void sol() {
    int n,x;
    cin>>n>>x;
    if(x==n){
        cout<<n<<" ";
        for(int i=2;i<=n-1;i++){
            cout<<i<<" ";
        }
        cout<<"1\n";
    }else if(x>n/2){
        cout<<"-1\n";
    }else if(n%2==0&&x==n/2){
        cout<<n/2<<" ";
        for(int i=2;i<n/2;i++){
            cout<<i<<" ";
        }
        cout<<n<<" ";
        for(int i=n/2+1;i<n;i++){
            cout<<i<<" ";
        }
        cout<<"1\n";
    }else{
        if(n%x){
            cout<<"-1\n";
            return ;
        }
        int number=n/x;
        vector<int> ans(n+1,0);
        iota(ans.begin()+1,ans.end(),1);
        ans[n]=1,ans[1]=x;
        vector<int> order;
        for(int i=2;i<=number;i++){
            if(number%i==0){
                while(number%i==0){
                    order.push_back(i);
                    number/=i;
                }
            }
        }
        int cur=x;
        for(int i=0;i<order.size();i++){
            ans[cur]=cur*order[i];
            cur=cur*order[i];
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }
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