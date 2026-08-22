#include <bits/stdc++.h>
using namespace std;
/*
    好的一道思维题，首先交互题看数据范围，这个数据范围相当于遍历了一遍的数组又遍历一半的数组
    然后如果从左到右遍历，可以发现，第一次遇到MAD>0的时候，这个位置的数值一定就是它自己，
    但是它可能会影响后面的查询结果，所以说接下来的查询要忽略它
    这么处理可以保证每次MAD>0发生的时候，这个位置都是一个数第二次出现。
    这样是2*n次查询的
    接下来考虑怎么把这个数第一次出现的位置确定
    因为我们已经把n个数第二次出现的位置确定了，可以采用上述方法，再来一次
    每次都要输出n个数第二次出现的位置，以及当前查询的位置，然后就可以确定当前位置的数是什么了
    每次都是n,时间复杂度是O(n^2)的
    总次数是3*n-1的
*/
void sol(){
    int n;
    cin>>n;
    vector<int> ans(2*n+1,-1);
    vector<bool> st(2*n+1,false);
    int cnt=1;
    int sum=1;
    while(cnt<=2*n-1){
        cnt++;
        cout<<"? ";
        cout<<sum+1<<" ";
        for(int i=1;i<=cnt;i++){
            if(!st[i]){
                cout<<i<<" ";
            }
        }
        cout<<'\n'<<'\n';
        cout.flush();

        int x;
        cin>>x;
        if(x){
            ans[cnt]=x;
            st[cnt]=true;
        }else sum++;
    }
    cnt=1;
    while(cnt<=n){
        int num=0;
        cout<<"? "<<n+1<<" ";
        for(int i=1;i<=2*n;i++){
            if(st[i]){
                cout<<i<<" ";
            }else if(ans[i]==-1&&num==0){
                num=i;
                cout<<i<<" ";
            }
        }
        cout<<'\n'<<'\n';
        cout.flush();
        
        int x;
        cin>>x;
        ans[num]=x;
        cnt++;
    }
    cout<<"! ";
    for(int i=1;i<=2*n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n'<<'\n';
    cout.flush();
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